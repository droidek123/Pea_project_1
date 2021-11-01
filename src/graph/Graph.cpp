//
// Created by Andrzej on 23.10.2021.
//
#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include "Graph.h"

Graph::Graph() {
    this->number_of_vertices = 0;
}

Graph::~Graph() = default;


void Graph::add_node() {
    if (this->matrix.empty()) {
        this->matrix.resize(1);
        this->number_of_vertices = 1;
        this->matrix[0].push_back(0);
    }
    this->number_of_vertices += 1;
    this->matrix.resize(this->number_of_vertices + 1);
    for (int i = 0; i < this->number_of_vertices; i++) {
        if (i == this->number_of_vertices) {
            this->matrix[i].push_back(0);
        } else {
            cout << "Podaj odleglosc od " + to_string(i) + "-go wierzcholka do " + to_string(this->number_of_vertices) +
                    "-go wierzcholka" << endl;
            int temp;
            cin >> temp;
            this->matrix[i].push_back(temp);
            this->matrix[this->number_of_vertices].push_back(temp);
        }
    }
}


void Graph::load_data(const string &name_file) {
    this->matrix.clear();
    string val;
    fstream file_in;


    file_in.open(name_file + ".txt");
    if (file_in.is_open()) {
        file_in >> this->number_of_vertices;
        this->matrix.resize(this->number_of_vertices);

        if (file_in.fail())
            cout << "File error - READ SIZE" << endl;
        else
            for (int i = 0; i < this->number_of_vertices; i++) {
                for (int j = 0; j < this->number_of_vertices; j++) {
                    file_in >> val;
                    if (file_in.fail()) {
                        cout << "File error - READ DATA" << endl;
                        break;
                    } else
                        this->matrix[i].push_back(stoi(val));
                }
            }
        file_in.close();
    } else
        cout << "File error - OPEN" << endl;
}

void Graph::display() {
    for (auto &m: this->matrix) {
        for (auto &mm: m) {
            cout << mm;
        }
        cout << endl;
    }
}

Result Graph::brute_force() {
    Result result;
    vector<int> path;

    for (int i = 0; i < this->number_of_vertices; i++) {
        path.push_back(i);
    }
    path.push_back(0);

    result.best_score = calculate_distance(path);

    while (next_permutation(path.begin() + 1, path.end() - 1)) {
        int r = calculate_distance(path);
        if (r < result.best_score) {
            result.best_score = r;
            result.list_of_nodes = path;
        }
    }
    return result;
}

int Graph::calculate_distance(const vector<int> &path) {
    int result = 0;
    for (int i = 1; i < path.size(); ++i) {
        result += this->matrix[path[i - 1]][path[i]];
    }
    return result;
}

const vector<vector<int>> &Graph::getMatrix() const {
    return matrix;
}

int Graph::getNumberOfVertices() const {
    return number_of_vertices;
}

int Graph::getDistance(int startDist, int endDist) {
    return this->matrix[startDist][endDist];
}
