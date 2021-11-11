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
    result.startTimer();
    int first_vertex = graph.getNumberOfVertices() - 1;
    int number_of_vertexes = graph.getNumberOfVertices() - 1;
    int path = (1 << number_of_vertexes) - 1;

    for (int i = 0; i < number_of_vertexes; i++) {
        map.insert({{0, i},
                    {graph.getDistance(first_vertex, i), first_vertex}});
    }
    int min_final_city = -1;
    for (int finalCity = 0; finalCity < number_of_vertexes; finalCity++) {
        int distance =
                solve_sub_problem(graph, number_of_vertexes, make_subpath(path, finalCity), finalCity) +
                graph.getDistance(finalCity, first_vertex);

        if (distance < result.best_score) {
            result.best_score = distance;
            min_final_city = finalCity;
        }
    }

    while (min_final_city != first_vertex) {
        result.list_of_nodes.push_back(min_final_city);
        path = make_subpath(path, min_final_city);
        auto search = map.find({path, min_final_city});
        min_final_city = search->second.parent;
    }
    result.list_of_nodes.push_back(first_vertex);
    result.endTimer();
    map.clear();
    return result;
}

int Dynamic_programming::solve_sub_problem(Graph &graph, int number_of_vertexes, int subpath, int dest_vertex) {
    auto search = map.find({subpath, dest_vertex});
    if (search != map.end()) {
        return search->second.weight;
    } else {
        int min_distance = INT_MAX;
        int min_parent = -1;

        for (int pre_dest_vertex = 0; pre_dest_vertex < number_of_vertexes; pre_dest_vertex++) {
            if (is_vertex_in_subpath(subpath, pre_dest_vertex)) {
                int subpath_without_pre_vertex = make_subpath(subpath, pre_dest_vertex);
                int distance =
                        solve_sub_problem(graph, number_of_vertexes, subpath_without_pre_vertex, pre_dest_vertex) +
                        graph.getDistance(pre_dest_vertex, dest_vertex);

                if (distance < min_distance) {
                    min_distance = distance;
                    min_parent = pre_dest_vertex;
                }
            }
        }

        map.insert({{subpath, dest_vertex},
                    {min_distance, min_parent}});
        return min_distance;
    }
}

int Dynamic_programming::make_subpath(int subpath, int vertex) {
    return subpath & ~(1 << vertex);
}

bool Dynamic_programming::is_vertex_in_subpath(int subpath, int city) {
    return (subpath & (1 << city)) != 0;
}
