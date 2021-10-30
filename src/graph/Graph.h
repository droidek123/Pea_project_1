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
private:
    vector<vector<int>> matrix;
    int number_of_vertices;
public:

    Graph();

    virtual ~Graph();

    const vector<vector<int>> &getMatrix() const;

    int getNumberOfVertices() const;

    int getDistance(int startDist, int endDist);

    void add_node();

    void load_data(const string &name_file);

    void display();

    Result brute_force();

    int calculate_distance(const vector<int> &path);

    Result dynamic();
};


#endif //PEA_PROJEKT_1_GRAPH_H
