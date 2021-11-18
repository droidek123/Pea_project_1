//
// Created by Andrzej on 16.11.2021.
//

#ifndef PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H
#define PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H

#include <stack>
#include <string>
#include "../graph/Graph.h"
#include "../Result/Result.h"

using namespace std;

/**
 * Struktora reprezentujaca wierzcholek
 */
struct NodeDFS {
    int lower_bound;
    int vertex;
};

/**
 * Klasa wykonujaca algorytm bnb
 */
class BranchAndBoundDFS {
public:
    int **matrix{}; // graf na ktorym wykonujemy algorytm
    int number_of_vertices{}; // liczba wierzcholkow w grafie
    int upper_bound{}; // gorna granica a zarazem najlepszy wynik
    bool *visited_vertices{};   // odwiedzone wierzcholki
    int *outgoing_edges{};  // dolne ograniczenia
    [[maybe_unused]] vector<int> path; // najlepsza scierzka
    vector<int> helper_path; // scierzka w ktorej w danym momencie jestesmy

    BranchAndBoundDFS();

    ~BranchAndBoundDFS();

    [[nodiscard]] int calculateLowerBound(NodeDFS node, int next) const;

    Result bnb(const Graph &graph);

    void recursion(NodeDFS node);

};


#endif //PEA_PROJEKT_1_BRANCHANDBOUNDDFS_H
