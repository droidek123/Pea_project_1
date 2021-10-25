cmake_minimum_required(VERSION 3.20)
project(Pea_projekt_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pea_projekt_1 src/main.cpp src/graph/Graph.cpp src/graph/Graph.h)

file(COPY sample_data/tsp17.txt sample_data/tsp4.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
