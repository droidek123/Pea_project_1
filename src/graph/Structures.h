//
// Created by Andrzej on 26.10.2021.
//

#ifndef PEA_PROJEKT_1_STRUCTURES_H
#define PEA_PROJEKT_1_STRUCTURES_H
#include <vector>

using namespace std;

struct Result {
    int best_score;
    vector<int> list_of_nodes;
};

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

#endif //PEA_PROJEKT_1_STRUCTURES_H
