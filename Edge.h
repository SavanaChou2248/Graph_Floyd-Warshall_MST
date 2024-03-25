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
