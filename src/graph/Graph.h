//
// Created by Andrzej on 23.10.2021.
//
#pragma once
#ifndef PEA_PROJEKT_1_GRAPH_H
#define PEA_PROJEKT_1_GRAPH_H

#include <vector>
#include <string>
#include "Structures.h"


class Graph {
public:
    int** matrix{};
    int number_of_vertices;

    Graph();

    virtual ~Graph();

    void destruct();

    [[nodiscard]] int getNumberOfVertices() const;

    int getDistance(int startDist, int endDist) const;

    void loadData(const string &name_file);

    void display() const;

    void generateGraph(int size);

    void resize(int new_size);
};


#endif //PEA_PROJEKT_1_GRAPH_H
