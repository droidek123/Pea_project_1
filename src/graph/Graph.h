//
// Created by Andrzej on 23.10.2021.
//

#ifndef PEA_PROJEKT_1_GRAPH_H
#define PEA_PROJEKT_1_GRAPH_H

#include <vector>
#include <string>


using namespace std;

struct Result {
    int best_score;
    vector<int> list_of_nodes;
};


class Graph {
public:
    vector<vector<int>> matrix;
    int number_of_nodes;

    Graph();

    virtual ~Graph();

    void load_data(const string &name_file);

    void display();

    Result brute_force();

    int calculate_distance(const vector<int> &tour);


    int calculate_distance(const vector<int> &tour, int best_score);

    void add_node();
};


#endif //PEA_PROJEKT_1_GRAPH_H
