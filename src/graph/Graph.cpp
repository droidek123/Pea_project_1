//
// Created by Andrzej on 23.10.2021.
//
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Graph.h"

Graph::Graph() {
    this->number_of_nodes = 0;
}

Graph::~Graph() = default;

void Graph::load_data(const string& name_file) {
    this->matrix.clear();
    string val;
    fstream file_in;


    file_in.open("C:/Users/Andrzej/Desktop/Studia/Sem5/Pea/Pea_projekt_1/src/" + name_file + ".txt");
    if(file_in.is_open())
    {
        file_in >> this->number_of_nodes;
        this->matrix.resize(this->number_of_nodes);
        this->number_of_nodes--;
//        for(int i = 0;i < this->number_of_nodes; i++){
//            this->default_tour.push_back(i);
//        }

        if(file_in.fail())
            cout << "File error - READ SIZE" << endl;
        else
            for(int i = 0; i <= this->number_of_nodes; i++)
            {
                for(int j = 0; j <= this->number_of_nodes; j++) {
                    file_in >> val;
                    if (file_in.fail()) {
                        cout << "File error - READ DATA" << endl;
                        break;
                    } else
                        this->matrix[i].push_back(stoi(val));
                }
            }
        file_in.close();
    }
    else
        cout << "File error - OPEN" << endl;
}

void Graph::display() {
    for(auto &m : this->matrix){
        for(auto &mm : m){
            cout << mm;
        }
        cout << endl;
    }
}

int Graph::make_tour() {
    Result result;

    for(int i = 0; i <= this->number_of_nodes; i++){
        this->default_tour.push_back(i);
    }

    result.best_score = calculate_distance(this->default_tour);

    while (next_permutation(this->default_tour.begin() + 1, this->default_tour.end())) {
        int r = calculate_distance(this->default_tour,result.best_score);
        if (r < result.best_score) {
            result.best_score = r;
//            best_tour = tour;
        }
    }

    return result.best_score;
}

int Graph::calculate_distance(const vector<int> &tour) {
    int result = 0;
    for(int i = 1; i < tour.size(); ++i) {
        result += matrix[tour[i-1]][tour[i]];
//        cout<< i << endl;
//        cout<< matrix[tour[i-1]][tour[i]] << endl;
//        cout<< result << endl;
    }
    return result;
}

int Graph::calculate_distance(const vector<int> &tour, int best_score) {
    int result = 0;
    for(int i = 1; i < tour.size(); ++i) {
        if (result>best_score) {
//            cout << i << endl;
//            cout << matrix[tour[i - 1]][tour[i]] << endl;
//            cout << result << endl;
//            cout << best_score << endl;
            return best_score;
        } else {
            result += matrix[tour[i - 1]][tour[i]];
//            cout << i << endl;
//            cout << matrix[tour[i - 1]][tour[i]] << endl;
//            cout << result << endl;
//            cout << best_score << endl;
        }
    }
    return result;
}

void Graph::add_node() {
    if (this->matrix.empty()){
        this->matrix.resize(1);
        this->matrix[0].push_back(0);
    }
    this->number_of_nodes +=1;
    this->matrix.resize(this->number_of_nodes+1);
    for(int i = 0; i <= this->number_of_nodes; i++){
        if(i == this->number_of_nodes){
            this->matrix[i].push_back(0);
        } else{
            cout << "Podaj odleglosc od " + to_string(i) + "-go wierzcholka do " + to_string(this->number_of_nodes) + "-go wierzcholka" << endl;
            int temp;
            cin >> temp;
            cout << endl;
            this->matrix[i].push_back(temp);
            this->matrix[this->number_of_nodes].push_back(temp);
        }
    }
    cout << this->number_of_nodes << endl;
}


