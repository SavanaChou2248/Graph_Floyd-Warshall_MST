#ifndef EDGECOMPARER_H
#define EDGECOMPARER_H

#include "Edge.h"

struct EdgeComparer {
    bool operator()(Edge* lhs, Edge* rhs);
};

#endif 
