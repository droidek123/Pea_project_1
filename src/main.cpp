#include <iostream>


#include "graph/Graph.h"
#include "Dynamic_programming/Dynamic_programming.h"


using namespace std;

void displayMainMenu();

void menuBruteForce();

void menuBnB();

void menuDynamicPrograming();

int main() {
    bool quit = false;
    char option;
    do {
        displayMainMenu();
        cin >> option;

        cout << endl;
        switch (option) {
            case '0':
                quit = true;
                break;
            case '1':
                menuBruteForce();
                break;

            case '2':
                menuBnB();
                break;

            case '3':
                menuDynamicPrograming();
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);

    return 0;

}


void menuBruteForce(){
    bool quit = false;
    char option;
    string name;
    Graph graph;

    do {
        cout << "================= BRUTE FORCE =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm without Algorithms" << endl;
        cout << "\t   5. Execute algorithm with Algorithms" << endl;
        cout << "\t   0. Back to the main menu" << endl<<endl;
        cout << "Chosen option: ";
        cin >> option;

        cout << endl;
        switch (option) {
            case '0':
                quit = true;
                break;
            case '1':
                cout << ("Plese enter name of the file: ");
                cin >> name;
                graph.load_data(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                //graph.generateGraph(x);
                break;
            case '3':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                {
                    graph.brute_force();
                }
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}

void displayMainMenu(){
    // system("clear");
    cout << "================== MAIN MENU ==================" << endl;
    cout << "\t   1. Brute Force" << endl;
    cout << "\t   2. B&B" << endl;
    cout << "\t   3. Dynamic programming" << endl;
    cout << "\t   0. Exit" << endl<<endl;
    cout << "Chosen option: ";
}

void menuDynamicPrograming(){
    bool quit = false;
    char option;
    string name;
    Graph graph;
    Dynamic_programming dynamicProgramming;
    do {
        cout << "================= DYNAMIC PROGRAMING =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm" << endl;
        cout << "\t   0. Back to the main menu" << endl<<endl;
        cout << "Chosen option: ";
        cin >> option;

        cout << endl;
        switch (option) {
            case '0':
                quit = true;
                break;
            case '1':
                cout << ("Plese enter name of the file: ");
                cin >> name;
                graph.load_data(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                //graph.generateGraph(x);
                break;
            case '3':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                {
                    dynamicProgramming.solve(graph);
                }
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}

void menuBnB(){
    bool quit = false;
    char option;
    string name;
    Graph graph;
    //BranchAndBound dBnB;
    do {
        cout << "================= BRANCH AND BOUND =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm" << endl;
        cout << "\t   0. Back to the main menu" << endl<<endl;
        cout << "Chosen option: ";
        cin >> option;

        cout << endl;
        switch (option) {
            case '0':
                quit = true;
                break;
            case '1':
                cout << ("Plese enter name of the file: ");
                cin >> name;
                graph.load_data(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                //graph.generateGraph(x);
                break;
            case '3':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if(graph.getNumberOfVertices() <=1){
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                {
                    //dBnB.bnb(graph);
                }
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}
