//
// Created by Andrzej on 28.10.2021.
//

#include <algorithm>
#include <iostream>
#include <limits>
#include "Dynamic_programming.h"


Dynamic_programming::Dynamic_programming() = default;

Dynamic_programming::~Dynamic_programming() = default;

/**
 * Glowna funkcja
 * @param graph Graf na ktorym wykonujemy algorytm
 * @return Zwraca strukture z najlepszym wynikiem scierzka i czasem wykonania
 */
Result Dynamic_programming::solve(Graph &graph) {
    Result result;
    result.startTimer();
    int first_vertex = graph.getNumberOfVertices() - 1; // ustawiamy wierzcholek startowy na ostani
    int number_of_vertexes = graph.getNumberOfVertices() - 1;
    int path = (1 << number_of_vertexes) -
               1; // poprzez przesuniecie bitowe zapelniamy cala sciezeke 1 co oznacza ze zaden wierzcholek jest odwiedzony

    // dodawanie pierwszych polaczen
    for (int i = 0; i < number_of_vertexes; i++) {
        map.insert({{0,                                  i},
                    {graph.getDistance(first_vertex, i), first_vertex}});
    }
    int min_final_city = -1;
    // glowna petla z rekurencja
    for (int finalCity = 0; finalCity < number_of_vertexes; finalCity++) {
        // oblicznie odleglosci dla danej sciezki
        int distance =
                solve_sub_problem(graph, number_of_vertexes, make_subpath(path, finalCity), finalCity) +
                graph.getDistance(finalCity, first_vertex);
        // ustawianie najlepszej sciezki
        if (distance < result.best_score) {
            result.best_score = distance;
            min_final_city = finalCity;
        }
    }

    // przpisywanie najlepszej sciezki
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
    auto search = map.find({subpath, dest_vertex}); // jesli dana sciezke juz obliczylismy to zwracamy jej warosc
    if (search != map.end()) {
        return search->second.weight;
    } else { // winnym wypadku obliczamy dany pod zbior
        int min_distance = INT_MAX;
        int min_parent = -1;

        for (int pre_dest_vertex = 0; pre_dest_vertex < number_of_vertexes; pre_dest_vertex++) {
            if (is_vertex_in_subpath(subpath, pre_dest_vertex)) { // nastepny wierzcholek w sciezce
                int subpath_without_pre_vertex = make_subpath(subpath, pre_dest_vertex);
                int distance =
                        solve_sub_problem(graph, number_of_vertexes, subpath_without_pre_vertex, pre_dest_vertex) +
                        graph.getDistance(pre_dest_vertex, dest_vertex);
                // ustawianie najkrotszej sciezki
                if (distance < min_distance) {
                    min_distance = distance;
                    min_parent = pre_dest_vertex;
                }
            }
        }
        // dodanie obliczonej sciezki do mapy
        map.insert({{subpath,      dest_vertex},
                    {min_distance, min_parent}});
        return min_distance;
    }
}

/**
 * Funkacja zwracajaca sciezke z odiwedzonym danym wierzcholkiem
 * @param subpath podsciezka bez odwiedzonego wierzcholka
 * @param vertex wierzcholek ktory chcemy odwiedzic
 * @return Zwraca pociezke z odwiedzonym danym wierzchlkiem
 */
int Dynamic_programming::make_subpath(int subpath, int vertex) {
    return subpath & ~(1 << vertex);
}

/**
 * Funkcja sprawdzajaca zcy wierzcholek ktory chcemy sprawdzic czy jest w danej podsciezce
 * @param subpath dana podsciezka
 * @param city  wierzcholek ktory chcemy sprawdzic czy jest w danej podsciezce
 * @return zwraca prawde gdy wierzcholek znajduje sie  wpodsciezce
 */
bool Dynamic_programming::is_vertex_in_subpath(int subpath, int vertex) {
    return (subpath & (1 << vertex)) != 0;
}
