//
// Created by Andrzej on 08.11.2021.
//
#pragma once
#ifndef PEA_PROJEKT_1_BRUTEFORCE_H
#define PEA_PROJEKT_1_BRUTEFORCE_H

#include "../graph/Structures.h"
#include "../graph/Graph.h"

class BruteForce {
private:
    Graph graph;
public:
    explicit BruteForce(const Graph& graph);

    virtual ~BruteForce();

    Result bruteForce();
};


#endif //PEA_PROJEKT_1_BRUTEFORCE_H
