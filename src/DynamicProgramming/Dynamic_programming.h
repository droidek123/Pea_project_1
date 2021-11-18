//
// Created by Andrzej on 28.10.2021.
//

#ifndef PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
#define PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H

#include <unordered_map>
#include <vector>
#include "../graph/Graph.h"
#include "../Result/Result.h"

/**
 *  Struktura do trzymania wartosci w mapie
 */
struct MapInfo{
    int weight;
    int parent;
};

typedef std::pair<int,int> pairKey;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pairKey) const
    {
        return std::hash<T1>()(pairKey.first) ^ std::hash<T2>()(pairKey.second);
    }
};

class Dynamic_programming {
private:
    unordered_map<pairKey, MapInfo, pair_hash> map;
public:
    Dynamic_programming();

    virtual ~Dynamic_programming();

    Result solve(Graph &graph);

    int solve_sub_problem(Graph &graph, int number_of_vertexes, int subset, int destCity);

    static int make_subpath(int subset, int vertex);

    static bool is_vertex_in_subpath(int subset, int vertex);
};


#endif //PEA_PROJEKT_1_DYNAMIC_PROGRAMMING_H
