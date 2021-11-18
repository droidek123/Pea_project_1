//
// Created by Andrzej on 08.11.2021.
//
#pragma once
#ifndef PEA_PROJEKT_1_BRUTEFORCE_H
#define PEA_PROJEKT_1_BRUTEFORCE_H

#include "../graph/Graph.h"
#include "../Result/Result.h"

class BruteForce {
private:
    Graph graph;
public:
    explicit BruteForce();

    virtual ~BruteForce();

    Result bruteForce(const Graph &graph);
};


#endif //PEA_PROJEKT_1_BRUTEFORCE_H
