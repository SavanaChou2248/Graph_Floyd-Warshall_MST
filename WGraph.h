/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 6: Spanning the Gamut
*/

#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "EdgeComparer.h"
#include "VertexSetCollection.h"

using namespace std;

//an unweighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public:
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();

  void computeMST();
  void computeMST(ostream& outputStream);


private:
  double** m_adj;
  double** m_conn;
  unsigned int m_size; //nodes in WGraph (fixed)

  vector<Edge*> MinimumSpanningTree();
};






#endif
