/*

Brief Overview:
Contains the implementation of a custom comparison function for edges. The comparison is based on the weights of the edges. 

*/

#include "EdgeComparer.h"

bool EdgeComparer::operator()(Edge* lhs, Edge* rhs)  {
    return lhs->weight > rhs->weight;
}
