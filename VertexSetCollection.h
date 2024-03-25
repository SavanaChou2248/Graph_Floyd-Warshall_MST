#ifndef VERTEXSETCOLLECTION_H
#define VERTEXSETCOLLECTION_H

#include <vector>
#include <unordered_map>
#include <unordered_set>

typedef unsigned int VertexID;

class VertexSetCollection {
public:
    VertexSetCollection(const std::vector<VertexID>& vertices);

    std::unordered_set<VertexID>* GetSet(VertexID vertex);
    void Merge(std::unordered_set<VertexID>* set1, std::unordered_set<VertexID>* set2);

private:
    std::unordered_map<VertexID, std::unordered_set<VertexID>*> vertexSets;
};

#endif 
