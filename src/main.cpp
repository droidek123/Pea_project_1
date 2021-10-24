#include <iostream>


#include "graph/Graph.h"


using namespace std;


int main() {
    Graph graph;
//    graph.add_node();
//    graph.add_node();
//    cout << graph.make_tour() << endl;
    graph.load_data("tsp2_");
    graph.display();
    cout <<graph.make_tour();
}
