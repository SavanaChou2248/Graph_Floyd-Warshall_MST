/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 6: Spanning the Gamut
*/

#ifndef EDGE_H
#define EDGE_H

typedef unsigned int VertexID;

class Edge {
public:
    VertexID from;
    VertexID to;
    double weight;

    Edge(VertexID from, VertexID to, double weight);
};

#endif 