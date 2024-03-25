/*

Brief Overview:
This class, Edge, represents an edge in a graph. An edge connects two vertices and has a weight associated with it. This class is part of the implementation for a graph-related programming assignment.

*/

#include "Edge.h"

Edge::Edge(VertexID from, VertexID to, double weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
}
