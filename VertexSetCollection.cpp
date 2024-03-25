/*

Brief Overview:
This class represents a collection of disjoint sets of vertices. It is used in the context of a graph-related programming assignment to manage sets of vertices.

*/

#include "VertexSetCollection.h"

/*
Name: VertexSetCollection (constructor)
Parameter(s): const std::vector<VertexID>& vertices
Brief Overview: Initializes a VertexSetCollection with individual sets for each vertex in the provided vector.
*/
VertexSetCollection::VertexSetCollection(const std::vector<VertexID>& vertices) {
    for (VertexID vertex : vertices) {
        vertexSets[vertex] = new std::unordered_set<VertexID>{vertex};
    }
}

/*
Name: GetSet
Parameter(s): VertexID vertex
Brief Overview: Returns the set containing the specified vertex.
*/
std::unordered_set<VertexID>* VertexSetCollection::GetSet(VertexID vertex) {
    return vertexSets[vertex];
}

/*
Name: Merge
Parameter(s): std::unordered_set<VertexID>* set1, std::unordered_set<VertexID>* set2
Brief Overview: Merges two sets, updating the collection and ensuring that all vertices in the merged set point to the same representative set.
*/
void VertexSetCollection::Merge(std::unordered_set<VertexID>* set1, std::unordered_set<VertexID>* set2) {
    set1->insert(set2->begin(), set2->end());
    for (VertexID vertex : *set2) {
        vertexSets[vertex] = set1;
    }
    delete set2;
}
