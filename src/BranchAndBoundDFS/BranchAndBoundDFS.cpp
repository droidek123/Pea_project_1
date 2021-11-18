//
// Created by Andrzej on 16.11.2021.
//

#include "BranchAndBoundDFS.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

BranchAndBoundDFS::BranchAndBoundDFS() = default;

BranchAndBoundDFS::~BranchAndBoundDFS() = default;

/**
 * Przeciazanie operatora
 * @param arg1
 * @param arg2
 * @return
 */
bool operator>(const NodeDFS &arg1, const NodeDFS &arg2) {
    if (arg1.lower_bound > arg2.lower_bound)
        return true;
    else
        return false;
}

/**
 *Funkcaja obliczajaca dana granice
 * @param node obecny wierzcholek
 * @param next nastepny wierzcholek
 * @return Gorna granice
 */
int BranchAndBoundDFS::calculateLowerBound(NodeDFS node, int next) const {
    int result = node.lower_bound;
    result -= outgoing_edges[node.vertex];
    result += matrix[node.vertex][next];

    return result;
}

/**
 *  Zainicajlizowanie wszystkich potrzbnych danych, wykonanie pomiarów oraz wywołanie rkurancji
 * @param graph Graf na ktorym wykonujemy algorytm
 * @return Zwraca strukture z najlepszym wynikiem scierzka i czasem wykonania
 */
Result BranchAndBoundDFS::bnb(const Graph &graph) {
    number_of_vertices = graph.number_of_vertices;
    matrix = graph.matrix;
    upper_bound = INT_MAX;
    outgoing_edges = new int[number_of_vertices];
    visited_vertices = new bool[number_of_vertices];
    int lb = 0; // poczatkowa minimalna granica
    int min = INT_MAX;
    //wyznaczenie dolnej granicy oraz najmniejszych wartosci w kazdym wierszu macierzy
    for (int r = 0; r < number_of_vertices; r++) {
        for (int c = 0; c < number_of_vertices; c++) {
            if (matrix[r][c] < min)
                min = matrix[r][c];
        }
        outgoing_edges[r] = min;
        lb += min;
        min = INT_MAX;
    }
    // zainicjalizowanie tablicy z niedwiedzonymi wierzcholami
    for (int r = 0; r < number_of_vertices; r++) {
        visited_vertices[r] = false;
    }

    Result result;
    NodeDFS start{};
    start.vertex = 0;
    start.lower_bound = lb;
    result.startTimer();
    recursion(start);
    result.endTimer();
    result.best_score = upper_bound;
    result.list_of_nodes = path;
    return result;
}

/**
 * Glowna funkcja odpowiedzialna za rekurencyjne przeszukiwanie grafu
 * @param parentNode wierzchołek z którego przyszliśmy
 */
void BranchAndBoundDFS::recursion(NodeDFS parentNode) {
    helper_path.push_back(parentNode.vertex); // dodanie rodzica do tymczasowej nie zupelnej scierzki
    visited_vertices[parentNode.vertex] = true; // wierzcholek z ktorego przychodzimy staje sie odwiedzony
    NodeDFS child{};
    priority_queue<NodeDFS, std::vector<NodeDFS>, std::greater<>> nodes;

    // dodanie dzieci wychodzacych z wierzcholka do kolejki priorytetowej
    for (int i = 0; i < number_of_vertices; i++) {
        if (!visited_vertices[i]) {
            child.vertex = i;
            child.lower_bound = calculateLowerBound(parentNode,
                                                    i); // oblicznie dolnej granicy z uwzglednieniem odleglosci miedzy rodzicem a wierzcholkiem potomnym
            nodes.push(child);
        }
    }

    // jesli doszlismy do konca scierzki bo wtedy kolejka priorytetowa bedzie pusta
    // sprawdzamy czy jest obecnie naklepsza scierzka co za tym idzie gorna granica
    // jesli nie wchodzimy w glab rekurencji
    if (nodes.empty()) {
        if (calculateLowerBound(parentNode, 0) < upper_bound) {
            upper_bound = calculateLowerBound(parentNode, 0);
            path = helper_path;
        }
    } else {
        while (!nodes.empty()) {
            child = nodes.top();
            nodes.pop();

            if (child.lower_bound < upper_bound) {
                recursion(child);
            } else
                break;
        }
    }
    // wychodzac z rekurencji zwalniamy wierzcholek z ktorego przyszlismy
    helper_path.pop_back();
    visited_vertices[parentNode.vertex] = false;
}
