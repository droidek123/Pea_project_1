#include <iostream>


#include "graph/Graph.h"
#include "Dynamic_programming/Dynamic_programming.h"


using namespace std;

void printBits( unsigned int n )
{
    const int Bits = 8 * sizeof n;
    char tmp[ Bits + 1 ];

    for( int i = 0; i < Bits; ++i )
    {
        tmp[ Bits - i - 1 ] = '0' + n % 2;
        n /= 2;
    }

    tmp[ Bits ] = 0;
    std::cout << tmp;
}

int main() {
    Result result;
    Graph graph;
    Dynamic_programming dynamicProgramming;
    graph.load_data("tsp17");
//    Dynamic_programming dynamicProgramming;
//    dynamicProgramming.heldKarp(graph);

    result = dynamicProgramming.solve(graph);


//    result = graph.brute_force();
    cout << "Najlepszy wynik" << endl;
    cout << result.best_score << endl;
    cout << "Najlepsza scieszka" << endl;
    for (auto r: result.list_of_nodes){
        cout << to_string(r) + " ";
    }
}
