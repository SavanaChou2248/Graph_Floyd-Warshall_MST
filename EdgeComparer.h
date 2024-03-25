/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 6: Spanning the Gamut
*/

#ifndef EDGECOMPARER_H
#define EDGECOMPARER_H

#include "Edge.h"

struct EdgeComparer {
    bool operator()(Edge* lhs, Edge* rhs);
};

#endif 