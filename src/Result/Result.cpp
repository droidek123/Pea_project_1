//
// Created by Andrzej on 08.11.2021.
//

#include <limits>
#include <windows.h>
#include "Result.h"

Result::Result() : best_score(INT_MAX),frequency(0), start(0), elapsed(0) {}

Result::~Result() = default;

void Result::startTimer() {
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);

    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    start = ((long long int)count.QuadPart);
}

void Result::endTimer() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    elapsed = ((long long int)count.QuadPart) - start;
};

