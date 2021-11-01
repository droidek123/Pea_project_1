#include <iostream>


#include "graph/Graph.h"
#include "Dynamic_programming/Dynamic_programming.h"


using namespace std;

int main() {
    Result result;
    Graph graph,graph1;
    Dynamic_programming dynamicProgramming;
    graph.load_data("tsp17");

    result = dynamicProgramming.solve(graph);
    cout << "Najlepszy wynik" << endl;
    cout << result.best_score << endl;
    cout << "Najlepsza scieszka" << endl;
    for (auto r: result.list_of_nodes){
        cout << to_string(r) + " ";
    }

    graph1.load_data("tsp6_2");

    result = dynamicProgramming.solve(graph1);
    cout << "Najlepszy wynik" << endl;
    cout << result.best_score << endl;
    cout << "Najlepsza scieszka" << endl;
    for (auto r: result.list_of_nodes){
        cout << to_string(r) + " ";
    }
}
