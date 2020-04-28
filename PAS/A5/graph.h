#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

struct CycleDetected : public std::runtime_error
{
  explicit CycleDetected(char const *msg = nullptr) : runtime_error(msg) {}
};

struct Vertex
{
  int label;
  int indegree;
  int top_num;
  Vertex(int l) : label(l) {}
  Vertex(int l, int ind) : label(l), indegree(ind) {}
};

class Graph
{
private:
  int numVertices = 0;
  vector<Vertex> node_list;
  vector<list<int> *> adj_list;
  vector<Vertex> top_order;

public:
  // default constructor
  Graph(){
      //it should be empty
  };
  // destructor
  ~Graph()
  {
    for (const auto edges : adj_list)
    {
      delete edges;
    }
  };
  // build a graph
  void buildGraph(ifstream &input);
  // display the graph
  void displayGraph();
  // topological sort
  void topological_sort();
  // find indegree
  void compute_indegree();
  // print topological sort
  void print_top_sort();
};

#endif
