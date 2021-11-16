//
// Created by Andrzej on 16.11.2021.
//

#ifndef PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H
#define PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H

#include <stack>
#include <string>
#include "../graph/Graph.h"
#include "../Result/Result.h"

using namespace std;

struct NodeDFS{
    int lower_bound;
    int vertex;
};


class BranchAndBoundDFS {
public:
    int **matrix;
    int number_of_vertices;
    int u_bound;
    int temp_cost;
    bool *visited;
    int *outgoing_edges;
    int n0_lb;
    stack<int> path;
    stack<int> helper_path;

    explicit BranchAndBoundDFS(const Graph& graph);
    ~BranchAndBoundDFS();
    [[nodiscard]] int calculateLowerBound(NodeDFS nodeDfs, int next) const;
    Result bnb();
    void recursion(NodeDFS node);

};


#endif //PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H
