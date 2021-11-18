//
// Created by Andrzej on 23.10.2021.
//
#include <iostream>
#include <limits>
#include <random>
#include <fstream>
#include "Graph.h"

Graph::Graph() {
    this->number_of_vertices = 0;
}

Graph::~Graph() {
    if (this->number_of_vertices >= 1) {
        this->destruct();
    }
}

void Graph::destruct() {
    for (int i = 0; i < number_of_vertices; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    this->number_of_vertices = 0;
}


void Graph::loadData(const string &name_file) {
    if (this->number_of_vertices >= 1)
        this->destruct();
    string val;
    fstream file_in;


    file_in.open(name_file + ".txt");
    if (file_in.is_open()) {
        file_in >> this->number_of_vertices;
        this->resize(number_of_vertices);

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
                        this->matrix[i][j] = stoi(val);
                }
            }
        file_in.close();
    } else
        cout << "File error - OPEN" << endl;
}

void Graph::display() const {
    for (int i = 0; i < this->number_of_vertices; i++) {
        for (int j = 0; j < this->number_of_vertices; j++) {
            cout << this->matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int Graph::getNumberOfVertices() const {
    return number_of_vertices;
}

int Graph::getDistance(int startDist, int endDist) const {
    return this->matrix[startDist][endDist];
}

void Graph::generateGraph(int size) {

    if (size <= 1) {
        cout << "To little nodes were given." << endl;
        return;
    }
    if (this->number_of_vertices >= 1)
        this->destruct();
    this->number_of_vertices = size;
    this->resize(size);

    srand(time(nullptr));
    for (int i = 0; i < this->number_of_vertices; i++) {
        for (int j = 0; j < this->number_of_vertices; j++) {
            if (i == j)
                this->matrix[i][j] = 0;
            else
                this->matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void Graph::resize(int new_size) {
    this->matrix = new int *[new_size];
    for (int i = 0; i < new_size; ++i) {
        this->matrix[i] = new int[new_size];
    }
}
