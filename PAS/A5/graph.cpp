#include "graph.h"
void Graph::buildGraph(ifstream &input)
{
    string line, lineProcessing;
    list<int> verticesStorage;
    list<int> *verticesPush;
    while (getline(input, line, '\n'))
    {
        stringstream inputStorage(line);
        numVertices++;
        inputStorage >> lineProcessing;
        if (lineProcessing == "-1")
        {
            break;
        }
        Vertex edge(stoi(lineProcessing));
        while (lineProcessing != "-1")
        {
            inputStorage >> lineProcessing;
            if (lineProcessing != "-1")
            {
                verticesStorage.push_back(stoi(lineProcessing));
            }
        }
        verticesPush = new list<int>(verticesStorage);
        node_list.push_back(edge);
        adj_list.push_back(verticesPush);
        verticesStorage.clear();
    }
};
void Graph::displayGraph()
{
    cout << "/////////// PRINTING GRAPH AND ADJ_LIST ///////////" << endl;
    for (int i = 0; i < node_list.size(); i++)
    {
        cout << node_list[i].label << ": ";
        for (const auto edges : *adj_list[i])
        {
            cout << edges << " ";
        }
        cout << endl;
    }
}