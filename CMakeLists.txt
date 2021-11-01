cmake_minimum_required(VERSION 3.20)
project(Pea_projekt_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Pea_projekt_1 src/main.cpp src/graph/Graph.cpp src/graph/Graph.h src/graph/Structures.h src/Dynamic_programming/Dynamic_programming.cpp src/Dynamic_programming/Dynamic_programming.h)

file(COPY sample_data/tsp17.txt sample_data/tsp4.txt
        sample_data/tsp6_1.txt sample_data/tsp6_2.txt sample_data/tsp10.txt sample_data/tsp12.txt
        sample_data/tsp13.txt sample_data/tsp14.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
