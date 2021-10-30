//
// Created by Andrzej on 28.10.2021.
//

#ifndef PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
#define PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H

#include <unordered_map>
#include <vector>
#include "../graph/Graph.h"


class Dynamic_programming {
private:
//    unordered_map<pairKey,int,pair_hash> map;
    vector<vector<int>> distances;
    vector<vector<int>> prev_vertex;
public:
    Dynamic_programming();

    virtual ~Dynamic_programming();

    Result solve(Graph &graph);

    int solve_sub_problem(Graph &graph, int numberOfMidpathCities, int subset, int destCity);

    static int make_subset(int subset, int vertex);

    static bool is_city_in_subset(int subset, int city);
//    void heldKarp(Graph &graph);
//    static vector<int> combinations(int size, int r);
};


#endif //PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
