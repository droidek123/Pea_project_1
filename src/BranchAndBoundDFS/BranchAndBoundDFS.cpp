//
// Created by Andrzej on 16.11.2021.
//

#include "BranchAndBoundDFS.h"

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool operator > (const NodeDFS &arg1, const NodeDFS &arg2)
{
    if (arg1.lower_bound > arg2.lower_bound)
        return true;
    else
        return false;
}

bool operator < (const NodeDFS &arg1, const NodeDFS &arg2)
{
    if (arg1.lower_bound < arg2.lower_bound)
        return true;
    else
        return false;
}

bool operator == (const NodeDFS &arg1, const NodeDFS &arg2)
{
    if (arg1.lower_bound == arg2.lower_bound)
        return true;
    else
        return false;
}


int BranchAndBoundDFS::calculateLowerBound(NodeDFS nodeDfs,int next) const
{
    int result = nodeDfs.lower_bound;
    result -= outgoing_edges[nodeDfs.vertex];
    result += matrix[nodeDfs.vertex][next];

    return result;
}

Result BranchAndBoundDFS::bnb()
{
    Result result;
    NodeDFS start{};
    start.vertex = 0;
    start.lower_bound = n0_lb;
    result.startTimer();
    recursion(start);
    result.endTimer();
    result.best_score = u_bound;
    return result;
}

void BranchAndBoundDFS::recursion(NodeDFS node)
{
    helper_path.push(node.vertex);
    visited[node.vertex] = true;
    NodeDFS temp{};
    priority_queue <NodeDFS, std::vector<NodeDFS>, std::greater<NodeDFS>> bounds;

    for (int i = 0; i < number_of_vertices; i++)
    {
        if (!visited[i])
        {
            temp.vertex = i;
            temp.lower_bound = calculateLowerBound(node, i);
            bounds.push(temp);
        }
    }

    if (bounds.empty())
    {
        if (calculateLowerBound(node, 0) < u_bound)
        {
            u_bound = calculateLowerBound(node, 0);
            //helper_path.copy(&path);
            path = helper_path;
        }
    }
    else
    {
        while (!bounds.empty())
        {
            temp = bounds.top();
            bounds.pop();

            if (temp.lower_bound < u_bound)
            {
                recursion(temp);
            }
            else
                break;
        }
    }
    helper_path.pop();
    visited[node.vertex] = false;
}

BranchAndBoundDFS::BranchAndBoundDFS(const Graph& graph)
{
    number_of_vertices = graph.number_of_vertices;
    matrix = graph.matrix;
    u_bound = INT_MAX;
    temp_cost = 0;
    outgoing_edges = new int[number_of_vertices];
    visited = new bool[number_of_vertices];
    n0_lb = 0;
    int min = INT_MAX;

    for (int r = 0; r < number_of_vertices; r++)
    {
        for (int c = 0; c < number_of_vertices; c++)
        {
            if (matrix[r][c] < min)
                min = matrix[r][c];
        }
        outgoing_edges[r] = min;
        n0_lb += min;
        min = INT_MAX;
    }

    for (int r = 0; r < number_of_vertices; r++)
    {
        visited[r] = false;
    }
}

BranchAndBoundDFS::~BranchAndBoundDFS()
= default;
