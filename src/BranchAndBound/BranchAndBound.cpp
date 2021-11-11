//
// Created by Andrzej on 08.11.2021.
//

#include <iostream>
#include <utility>
#include "BranchAndBound.h"

Result BranchAndBound::bnb(Graph &graph) {
    Result result;
    vertexes_number = graph.number_of_vertices;
    int track_cost =INT_MAX;
    Node *source = newNode(graph.matrix, r, 0, -1, 0, vertexes_number);
    source->cost = costFind(source->reduced_matrix, vertexes_number);
    pq.push(source);

    while (!pq.empty()) {
        Node *leastCost = pq.top();
        pq.pop();
        if (leastCost->cost >= track_cost) {
            continue;
        }
        int i = leastCost->cityNum;

        if (leastCost->level == vertexes_number - 1) {
            leastCost->trackpath.emplace_back(i, 0);

            track_cost = leastCost->cost;
            result.best_score = track_cost;
            cout << "Current upperbound: " << result.best_score << endl;
            printTrackPath(leastCost->trackpath);
            for(int h = 0; h< vertexes_number;h++){
                result.list_of_nodes.push_back(leastCost->trackpath[h].first);
            }

        }

        for (int j = 0; j < vertexes_number; j++) {
            if (leastCost->reduced_matrix[i][j] != INT_MAX) {

                Node *child = newNode(leastCost->reduced_matrix, leastCost->trackpath, leastCost->level + 1, i, j,
                                      vertexes_number);
                child->cost = leastCost->cost + leastCost->reduced_matrix[i][j];
                child->cost += costFind(child->reduced_matrix, vertexes_number);

                if (child->cost < track_cost) {
                    pq.push(child);
                }

            }
        }

        for (int f = 0; f < vertexes_number; ++f) {
            delete[] leastCost->reduced_matrix[f];
        }
        delete[] leastCost->reduced_matrix;
        delete leastCost;

    }
    return result;
}

Node *BranchAndBound::newNode(int **ancestorMtrx, vector<pair<int, int>> const &track_path, int level, int i, int j,
                              int vertexes_number) {
    Node *node = new Node;

    node->trackpath = track_path;

    node->reduced_matrix = new int *[vertexes_number];
    for (int z = 0; z < vertexes_number; ++z) {
        node->reduced_matrix[z] = new int[vertexes_number];
    }

    if (level != 0)
        node->trackpath.emplace_back(i, j);


    for (int y = 0; y < vertexes_number; ++y) {
        for (int r = 0; r < vertexes_number; ++r) {
            node->reduced_matrix[y][r] = ancestorMtrx[y][r];
        }
    }

    for (int k = 0; level != 0 && k < vertexes_number; k++) {
        node->reduced_matrix[i][k] = INT_MAX;
        node->reduced_matrix[k][j] = INT_MAX;
    }

    node->reduced_matrix[j][0] = INT_MAX;
    node->level = level;
    node->cityNum = j;

    return node;

}

void BranchAndBound::reduceRow(int **reduced_matrix, int *row, int vertexes_number) {
    for (int i = 0; i < vertexes_number; i++) {
        row[i] = INT_MAX;
    }

    for (int i = 0; i < vertexes_number; i++)
        for (int j = 0; j < vertexes_number; j++)
            if (reduced_matrix[i][j] < row[i])
                row[i] = reduced_matrix[i][j];

    for (int i = 0; i < vertexes_number; i++)
        for (int j = 0; j < vertexes_number; j++)
            if (reduced_matrix[i][j] != INT_MAX && row[i] != INT_MAX)
                reduced_matrix[i][j] -= row[i];

}

void BranchAndBound::reduceCol(int **reduced_matrix, int *col, int vertexes_number) {
    fill_n(col, vertexes_number, INT_MAX);

    for (int i = 0; i < vertexes_number; i++)
        for (int j = 0; j < vertexes_number; j++)
            if (reduced_matrix[i][j] < col[j])
                col[j] = reduced_matrix[i][j];

    for (int i = 0; i < vertexes_number; i++)
        for (int j = 0; j < vertexes_number; j++)
            if (reduced_matrix[i][j] != INT_MAX && col[j] != INT_MAX)
                reduced_matrix[i][j] -= col[j];

}

int BranchAndBound::costFind(int **reduced_matrix, int vertexes_number) {
    int cost = 0;

    int *row = new int[vertexes_number];

    reduceRow(reduced_matrix, row, vertexes_number);

    int *col = new int[vertexes_number];

    reduceCol(reduced_matrix, col, vertexes_number);

    for (int i = 0; i < vertexes_number; i++) {
        cost += (row[i] != INT_MAX) ? row[i] : 0;
        cost += (col[i] != INT_MAX) ? col[i] : 0;

    }
    delete[] row;
    delete[] col;
    return cost;

}

void BranchAndBound::printTrackPath(vector<pair<int, int>> const &list) {
    for (int i = 0; i < list.size(); i++) {
        cout << list[i].first;

        if (i < list.size() - 1)
            cout << " ";
    }
    cout << " " << 0 << endl;
}
