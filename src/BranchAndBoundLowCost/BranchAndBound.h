//
// Created by Andrzej on 08.11.2021.
//
#pragma once
#ifndef PEA_PROJEKT_1_BRANCHANDBOUND_H
#define PEA_PROJEKT_1_BRANCHANDBOUND_H

#include <queue>
#include <utility>
#include <vector>
#include "../graph/Graph.h"
#include "../Result/Result.h"

using namespace std;

struct Node
{
    std::vector<std::pair<int, int>> trackpath;
    int **reduced_matrix;
    int cityNum;
    int level;
    int cost;
};

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->cost > rhs->cost;
    }
};


class BranchAndBound{
private:
    int vertexes_number;
    std::vector<std::pair<int, int>> r;
    std::priority_queue<Node*, std::vector<Node*>, comp> pq;
public:
    Result bnb(Graph &graph);

    static void reduceRow(int**reduced_matrix, int* row, int vertexes_number);

    static void reduceCol(int**reduced_matrix, int* col, int vertexes_number);

    static int costFind(int** reduced_matrix, int vertexes_number);

    static Node* newNode(int** ancestorMtrx, std::vector<std::pair<int,int>> const &track_path, int level, int i , int j, int vertexes_number );
};
#endif //PEA_PROJEKT_1_BRANCHANDBOUND_H
