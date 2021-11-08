//
// Created by Andrzej on 08.11.2021.
//

#include <algorithm>
#include "BruteForce.h"

BruteForce::BruteForce(const Graph& graph){
    this->graph =graph;
}

BruteForce::~BruteForce() = default;

Result BruteForce::bruteForce() {
    Result result;
    vector<int> path;
    result.best_score = INT_MAX;

    path.reserve(this->graph.number_of_vertices);
    for (int i = 0; i < graph.getNumberOfVertices(); i++) {
        path.push_back(i);
    }

    do {
        int r = 0;
        for (int i = 1; i < path.size(); ++i) {
            r += this->graph.matrix[path[i-1]][path[i]];
        }
        if (r < result.best_score) {
            result.best_score = r;
            result.list_of_nodes = path;
        }
    }while (next_permutation(path.begin() + 1, path.end()));
    result.list_of_nodes.push_back(0);
    unsigned int i = result.list_of_nodes.size()-1;
    result.best_score += graph.matrix[result.list_of_nodes[i-1]][result.list_of_nodes[i]];
    return result;
}
