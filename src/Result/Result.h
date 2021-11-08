//
// Created by Andrzej on 08.11.2021.
//

#ifndef PEA_PROJEKT_1_RESULT_H
#define PEA_PROJEKT_1_RESULT_H
#include <vector>

using namespace std;

class Result {
public:
    int best_score;
    vector<int> list_of_nodes;
    volatile long long int frequency;
    volatile long long int start;
    volatile long long int elapsed;

    Result();

    ~Result();

    void startTimer();

    void endTimer();
};


#endif //PEA_PROJEKT_1_RESULT_H
