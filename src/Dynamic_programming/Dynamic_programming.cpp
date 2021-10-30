//
// Created by Andrzej on 28.10.2021.
//

#include <algorithm>
#include <iostream>
#include <limits>
#include "Dynamic_programming.h"


Dynamic_programming::Dynamic_programming() = default;

Dynamic_programming::~Dynamic_programming() = default;

Result Dynamic_programming::solve(Graph &graph) {
    Result result;
    result.best_score = numeric_limits<int>::max();
    int startVertex = graph.getNumberOfVertices()-1;
    int number_of_mid_path_vertexes = graph.getNumberOfVertices();
    int number_of_subsets = 1 << number_of_mid_path_vertexes;


    this->distances.resize(number_of_subsets);
    this->prev_vertex.resize(number_of_subsets);
    for (int i = 0; i < number_of_subsets; i++) {
        distances[i].resize(number_of_mid_path_vertexes);
        prev_vertex[i].resize(number_of_mid_path_vertexes);

        for (int j = 0; j < number_of_mid_path_vertexes; j++) {
            distances[i][j] = -1;
        }
    }
    for (auto i = 0; i < number_of_mid_path_vertexes ; i++) {
        this->distances[0][i] = graph.getDistance(startVertex,i); //.insert(i,graph.getDistance(startVertex,counter)); //.push_back(graph.getDistance(startVertex, i));
        this->prev_vertex[0][i] = startVertex;
    }

    int minFinalCity = 0;
    number_of_subsets--; // stworzenie scierzki zawirajaca wszystkie wierzcholki

    for (int finalVertex = 0; finalVertex < number_of_mid_path_vertexes; finalVertex++) {
        int distance = solve_sub_problem(graph, number_of_mid_path_vertexes,make_subset(number_of_subsets, finalVertex), finalVertex) +
                       graph.getDistance(finalVertex, startVertex);

        if (distance < result.best_score) {
            result.best_score = distance;
            minFinalCity = finalVertex;
        }
    }

    result.list_of_nodes.push_back(startVertex);

    int currentSubset = 1 << number_of_mid_path_vertexes;
    while (minFinalCity != startVertex) {
        result.list_of_nodes.push_back(minFinalCity);
        currentSubset = make_subset(currentSubset, minFinalCity);

        minFinalCity = prev_vertex[currentSubset][minFinalCity];
    }

    result.list_of_nodes.push_back(startVertex);

    return result;
}

int Dynamic_programming::solve_sub_problem(Graph &graph, int number_of_mid_path_vertexes, int subset, int destCity) {
    if (distances[subset][destCity] != -1) {
        return distances[subset][destCity];
    } else {
        int best_result = INT_MAX;
        int last_parent = -1;

        for (int preDestCity = 0; preDestCity < number_of_mid_path_vertexes; preDestCity++) {
            if (is_city_in_subset(subset, preDestCity)) {
                int subsetWithoutPreDestCity = make_subset(subset, preDestCity);
                int distance = solve_sub_problem(graph, number_of_mid_path_vertexes, subsetWithoutPreDestCity, preDestCity) + graph.getDistance(preDestCity, destCity);

                if (distance < best_result) {
                    best_result = distance;
                    last_parent = preDestCity;
                }
            }
        }

        // Save results
        distances[subset][destCity] = best_result;
        prev_vertex[subset][destCity] = last_parent;

        return best_result;
    }
}

int Dynamic_programming::make_subset(int subset, int vertex) {
    return subset & ~(1 << vertex);
}

bool Dynamic_programming::is_city_in_subset(int subset, int city) {
    return (subset & (1 << city)) != 0;
}
