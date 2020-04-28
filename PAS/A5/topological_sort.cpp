#include <iostream>
#include "graph.h"

void Graph::compute_indegree()
{
    for (int i = 0; i < node_list.size(); i++)
    {
        for (const auto edges : *adj_list[i])
        {
            node_list.at(edges - 1).indegree++;
        }
    }
}

void Graph::topological_sort()
{
    queue<Vertex> q;
    int counter = 0;
    q.empty();

    for (int i = 0; i < node_list.size(); i++)
    {
        if (node_list.at(i).indegree == 0)
        {
            q.push(node_list.at(i));
        }
    }

    while (!q.empty())
    {
        Vertex v = q.front();
        q.pop();
        v.top_num = ++counter; //not useful because we are using a different vector to store topological orders.
        top_order.push_back(v);

        for (const auto adj : *adj_list[v.label - 1])
        {
            if (--node_list.at(adj - 1).indegree == 0)
            {
                q.push(node_list.at(adj - 1));
            }
        }
    }

    if (counter != numVertices)
    {
        throw CycleDetected("A cycle has been detected in the graph!");
    }
}

void Graph::print_top_sort()
{

    cout << "/////////// PRINTING GRAPH AND ADJ_LIST ///////////" << endl;
    for (const auto top : top_order)
    {
        // OR cout << top.top_num << " ";
        cout << top.label << " ";
    }
}
