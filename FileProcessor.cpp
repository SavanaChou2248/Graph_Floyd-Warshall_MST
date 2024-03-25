/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 6: Spanning the Gamut

Brief Overview:
This class is responsible for processing input files and running the main logic of the program. It reads a square matrix of weights from the input file, constructs a weighted graph, computes its Minimum Spanning Tree (MST), and writes the MST details to an output file.

*/

#include "FileProcessor.h"

//Constructor
FileProcessor::FileProcessor(string& inputFileName) {
    m_inputFileName.open(inputFileName);

    if (!m_inputFileName.is_open()) {
        cout << "Error: Unable to open input file." << endl;
    }
}

//Destructor
FileProcessor::~FileProcessor() {
    m_inputFileName.close();
}

/*
Name: runProgram
Parameter(s): None
Brief Overview: Reads input data from the file, constructs a weighted graph, computes its Minimum Spanning Tree (MST), and writes the MST details to an output file.
*/
void FileProcessor::runProgram() {

    string line;
    int numNodes;
    m_inputFileName >> numNodes;

    WGraph newGraph(numNodes);

    double weight;
    for (int i = 0; i < numNodes; ++i) {
        for (int j = 0; j < numNodes; ++j) {
            m_inputFileName >> weight;
            if (weight == 0.0) {
                continue;
            }
            newGraph.addEdge(i,j, weight);
        }
    }

    ofstream outputFile;
    outputFile.open("outputFile.txt");
    newGraph.computeMST(outputFile);

}