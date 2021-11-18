#include <iostream>
#include <iomanip>
#include "graph/Graph.h"
#include "DynamicProgramming/Dynamic_programming.h"
#include "BruteForce/BruteForce.h"
#include "BranchAndBoundLowCost/BranchAndBound.h"
#include "BranchAndBoundDFS/BranchAndBoundDFS.h"


using namespace std;

void displayMainMenu();

void menuBruteForce();

void menuBnB();

void menuBnBDFS();

void menuDynamicPrograming();

void printTime(long long elapsed, long long frequency);

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
                menuBnBDFS();
                break;
            case '4':
                menuDynamicPrograming();
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
    return 0;

}

void displayMainMenu() {
    cout << "================== MAIN MENU ==================" << endl;
    cout << "\t   1. Brute Force" << endl;
    cout << "\t   2. B&B" << endl;
    cout << "\t   3. B&B DFS" << endl;
    cout << "\t   4. Dynamic programming" << endl;
    cout << "\t   0. Exit" << endl << endl;
    cout << "Chosen option: ";
}

void menuBruteForce() {
    bool quit = false;
    char option;
    string name;
    Graph graph;
    BruteForce bruteForce;
    do {
        cout << "================= BRUTE FORCE =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm" << endl;
        cout << "\t   5. Make tests" << endl;
        cout << "\t   0. Back to the main menu" << endl << endl;
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
                graph.loadData(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                graph.generateGraph(x);
                break;
            case '3':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4': {
                Result result;
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                } else {
                    result = bruteForce.bruteForce(graph);
                    cout << "Result: " + to_string(result.best_score) << endl;
                    cout << "Best path: ";
                    for (auto r: result.list_of_nodes) {
                        cout << to_string(r) + " ";
                    }
                    cout << endl;
                    printTime(result.elapsed, result.frequency);
                    break;
                }
            }
            case '5': {
                Result result;
                for (int i = 4; i < 14; i++) {
                    long long time_elapsed_memory = 0;
                    long long time_frequency_memory = 0;
                    if (i > 11) {
                        for (int j = 0; j < 10; j++) {
                            graph.generateGraph(i);
                            result = bruteForce.bruteForce(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;

                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 100, time_frequency_memory / 100);
                        cout << endl;
                    } else {
                        for (int j = 0; j < 100; j++) {
                            graph.generateGraph(i);
                            result = bruteForce.bruteForce(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 100, time_frequency_memory / 100);
                        cout << endl;
                    }
                }
            }
                break;
            default:
                cout << "Wrong option chosen.\n";
        }

    } while (!quit);
}

void menuDynamicPrograming() {
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
        cout << "\t   5. Make tests" << endl;
        cout << "\t   0. Back to the main menu" << endl << endl;
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
                graph.loadData(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                graph.generateGraph(x);
                break;
            case '3':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                } else {
                    Result result;
                    result = dynamicProgramming.solve(graph);
                    cout << "Result: " + to_string(result.best_score) << endl;
                    cout << "Best path: ";
                    for (auto r: result.list_of_nodes) {
                        cout << to_string(r) + " ";
                    }
                    cout << endl;
                    printTime(result.elapsed, result.frequency);
                }
                break;
            case '5': {
                Result result;
                for (int i = 4; i < 24; i++) {
                    long long time_elapsed_memory = 0;
                    long long time_frequency_memory = 0;
                    if (i < 18) {
                        for (int j = 0; j < 100; j++) {
                            graph.generateGraph(i);
                            result = dynamicProgramming.solve(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 100, time_frequency_memory / 100);
                        cout << endl;
                    } else {
                        for (int j = 0; j < 3; j++) {
                            graph.generateGraph(i);
                            result = dynamicProgramming.solve(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 3, time_frequency_memory / 3);
                        cout << endl;
                    }
                }
            }
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}

void menuBnB() {
    bool quit = false;
    char option;
    string name;
    Graph graph;
    do {
        cout << "================= BRANCH AND BOUND =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm" << endl;
        cout << "\t   5. Make tests" << endl;
        cout << "\t   0. Back to the main menu" << endl << endl;
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
                graph.loadData(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                graph.generateGraph(x);
                break;
            case '3':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                } else {
                    Result result;
                    BranchAndBound branchAndBound;
                    result = branchAndBound.bnb(graph);
                    cout << "Result: " + to_string(result.best_score) << endl;
                    cout << "Best path: ";
                    for (auto r: result.list_of_nodes) {
                        cout << to_string(r) + " ";
                    }
                    cout << endl;
                    printTime(result.elapsed, result.frequency);
                    break;
                }
            case '5': {
                Result result;
                BranchAndBound branchAndBound;
                for (int i = 4; i < 17; i++) {
                    long long time_elapsed_memory = 0;
                    long long time_frequency_memory = 0;
                    if (i < 12) {
                        for (int j = 0; j < 100; j++) {
                            graph.generateGraph(i);
                            result = branchAndBound.bnb(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 100, time_frequency_memory / 100);
                        cout << endl;
                    } else if (i < 14) {
                        for (int j = 0; j < 10; j++) {
                            graph.generateGraph(i);
                            result = branchAndBound.bnb(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 10, time_frequency_memory / 10);
                        cout << endl;
                    } else {
                        graph.generateGraph(i);
                        result = branchAndBound.bnb(graph);
                        time_elapsed_memory += result.elapsed;
                        time_frequency_memory += result.frequency;
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory, time_frequency_memory);
                        cout << endl;
                    }
                }
            }
                break;
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}

void menuBnBDFS() {
    bool quit = false;
    char option;
    string name;
    Graph graph;
    BranchAndBoundDFS branchAndBoundDfs;
    do {
        cout << "================= BRANCH AND BOUND =================" << endl;
        cout << "\t   1. Load from file" << endl;
        cout << "\t   2. Generate adjacency matrix" << endl;
        cout << "\t   3. Display adjacency matrix" << endl;
        cout << "\t   4. Execute algorithm" << endl;
        cout << "\t   5. Make tests" << endl;
        cout << "\t   0. Back to the main menu" << endl << endl;
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
                graph.loadData(name);
                break;
            case '2':
                int x;
                cout << "Enter amount of nodes: ";
                cin >> x;
                graph.generateGraph(x);
                break;
            case '3':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                }
                graph.display();
                break;
            case '4':
                if (graph.getNumberOfVertices() <= 1) {
                    cout << ("No adjacency matrix was created.\n");
                    break;
                } else {
                    Result result;
                    result = branchAndBoundDfs.bnb(graph);
                    cout << "Result: " + to_string(result.best_score) << endl;
                    cout << "Best path: ";
                    for (auto r: result.list_of_nodes) {
                        cout << to_string(r) + " ";
                    }
                    cout << endl;
                    printTime(result.elapsed, result.frequency);
                    break;
                }
            case '5': {
                Result result;
                for (int i = 4; i < 21; i++) {
                    long long time_elapsed_memory = 0;
                    long long time_frequency_memory = 0;
                    if (i < 12) {
                        for (int j = 0; j < 100; j++) {
                            graph.generateGraph(i);
                            result = branchAndBoundDfs.bnb(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 100, time_frequency_memory / 100);
                        cout << endl;
                    } else {
                        for (int j = 0; j < 10; j++) {
                            graph.generateGraph(i);
                            result = branchAndBoundDfs.bnb(graph);
                            time_elapsed_memory += result.elapsed;
                            time_frequency_memory += result.frequency;
                        }
                        cout << "Time for tsp" << i << endl;
                        printTime(time_elapsed_memory / 10, time_frequency_memory / 10);
                        cout << endl;
                    }
                }
                break;
            }
            default:
                cout << "Wrong option chosen.\n";

        }

    } while (!quit);
}

void printTime(long long elapsed, long long frequency) {
    cout << "Time [s] " << setprecision(3) << (float) elapsed / frequency << endl;
    cout << "Time [ms] " << (1000.0 * elapsed) / frequency << endl;
    cout << "Time [us] " << (1000000.0 * elapsed) / frequency << endl;
}
