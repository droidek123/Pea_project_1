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
    result.best_score = INT_MAX;
    int firstVertice = graph.getNumberOfVertices() - 1;
    int numberOfMidpathCities = graph.getNumberOfVertices() - 1;
    int numberOfSubsets = 1 << numberOfMidpathCities;
    int allMidpathCities = (1 << numberOfMidpathCities) - 1;

    for (int i = 0; i < numberOfMidpathCities; i++) {
        map.insert({{0,                                  i},
                    {graph.getDistance(firstVertice, i), firstVertice}});
    }

    for (int finalCity = 0; finalCity < numberOfMidpathCities; finalCity++) {
        int distance =
                solve_sub_problem(graph, numberOfMidpathCities, make_subset(allMidpathCities, finalCity), finalCity) +
                graph.getDistance(finalCity, firstVertice);

        if (distance < result.best_score) {
            result.best_score = distance;
        }
    }
    map.clear();
    return result;
}

int Dynamic_programming::solve_sub_problem(Graph &graph, int number_of_mid_path_vertexes, int subset, int destCity) {
    auto search = map.find({subset, destCity});
    if (search != map.end()) {
        return search->second.weight;
    } else {
        int minDistance = INT_MAX;
        int minParent = -1;

        for (int preDestCity = 0; preDestCity < number_of_mid_path_vertexes; preDestCity++) {
            if (is_city_in_subset(subset, preDestCity)) {
                int subsetWithoutPreDestCity = make_subset(subset, preDestCity);
                int distance =
                        solve_sub_problem(graph, number_of_mid_path_vertexes, subsetWithoutPreDestCity, preDestCity) +
                        graph.getDistance(preDestCity, destCity);

                if (distance < minDistance) {
                    minDistance = distance;
                    minParent = preDestCity;
                }
            }
        }

        map.insert({{subset,      destCity},
                    {minDistance, minParent}});
        return minDistance;
    }
}

int Dynamic_programming::make_subset(int subset, int vertex) {
    return subset & ~(1 << vertex);
}

bool Dynamic_programming::is_city_in_subset(int subset, int city) {
    return (subset & (1 << city)) != 0;
}
