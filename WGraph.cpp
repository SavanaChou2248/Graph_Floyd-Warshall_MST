/*

Brief Overview:
This class, WGraph, represents a weighted graph and provides functionality for managing edges, computing the transitive closure using Floyd-Warshall algorithm, calculating the cheapest cost between vertices, and finding the Minimum Spanning Tree (MST) using Prim's algorithm. 

*/

#include "WGraph.h"

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}

WGraph::~WGraph(){
  //release memory
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }

  for(int im = 0; im < m_size; ++im){ //transitive closure
    for(int source = 0; source < m_size; ++source){
      for(int sink = 0; sink < m_size; ++sink){
        //every possible pair of source,sink and intermediate node
        if(source==sink){
          continue;
        }
        if(m_conn[source][im] != std::numeric_limits<double>::max() &&
           m_conn[im][sink] != std::numeric_limits<double>::max() &&
           m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
          m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }

      }
    }
  }


}

double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j];
}


/*
Name: computeMST
Parameter(s): None
Brief Overview: Computes and displays the Minimum Spanning Tree (MST) of the graph using Kruskal's algorithm. Outputs the cost of the MST and its adjacency matrix representation.
*/
void WGraph::computeMST() {
  std::vector<Edge*> mstEdges = MinimumSpanningTree();

    // Display the cost of the MST
    double mstCost = 0.0;
    for (Edge* edge : mstEdges) {
        mstCost += edge->weight;
    }
    cout << "Cost of MST: " << mstCost << endl;

    // Display the adjacency matrix representation of the MST
    // (Assuming m_size is the number of vertices)
    std::vector<std::vector<double>> mstAdjMatrix(m_size, std::vector<double>(m_size, 0.0));
    for (Edge* edge : mstEdges) {
        mstAdjMatrix[edge->from][edge->to] = edge->weight;
        mstAdjMatrix[edge->to][edge->from] = edge->weight;
    }

    // Display the adjacency matrix
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            cout << mstAdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*
Name: computeMST
Parameter(s): ostream& outputStream
Brief Overview: Same as computeMST(), but outputs the cost of the MST and its adjacency matrix representation to the specified output stream.
*/
void WGraph::computeMST(ostream& outputStream) {
  std::vector<Edge*> mstEdges = MinimumSpanningTree();

    // Display the cost of the MST
    double mstCost = 0.0;
    for (Edge* edge : mstEdges) {
        mstCost += edge->weight;
    }
    outputStream << "Cost of MST: " << mstCost << endl;

    // Display the adjacency matrix representation of the MST
    std::vector<std::vector<double>> mstAdjMatrix(m_size, std::vector<double>(m_size, 0.0));
    for (Edge* edge : mstEdges) {
        mstAdjMatrix[edge->from][edge->to] = edge->weight;
        mstAdjMatrix[edge->to][edge->from] = edge->weight;
    }

    // Display the adjacency matrix
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            outputStream << mstAdjMatrix[i][j] << " ";
        }
        outputStream << endl;
    }
}

/*
Name: MinimumSpanningTree
Parameter(s): None
Brief Overview: Finds and returns the Minimum Spanning Tree (MST) of the graph. Utilizes a priority queue and a disjoint-set data structure for edge selection.
*/
vector<Edge*> WGraph::MinimumSpanningTree() {
  std::priority_queue<Edge*, std::vector<Edge*>, EdgeComparer> edgeQueue;
    for (int i = 0; i < m_size; ++i) {
        for (int j = i + 1; j < m_size; ++j) {
            if (m_adj[i][j] < std::numeric_limits<double>::max()) {
                edgeQueue.push(new Edge(i, j, m_adj[i][j]));
            }
        }
    }

    std::vector<VertexID> allVertices(m_size);
    for (int i = 0; i < m_size; ++i) {
        allVertices[i] = i;
    }
    VertexSetCollection vertexSets(allVertices);

    std::vector<Edge*> resultList;

    while (!edgeQueue.empty()) {
        Edge* nextEdge = edgeQueue.top();
        edgeQueue.pop();

        std::unordered_set<VertexID>* set1 = vertexSets.GetSet(nextEdge->from);
        std::unordered_set<VertexID>* set2 = vertexSets.GetSet(nextEdge->to);

        if (set1 != set2) {
            resultList.push_back(nextEdge);
            vertexSets.Merge(set1, set2);
        } else {
            delete nextEdge; 
        }
    }

    return resultList;
}
