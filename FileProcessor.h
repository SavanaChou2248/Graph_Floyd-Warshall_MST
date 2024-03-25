/*
Savana Chou
2428859
sachou@chapman.edu
CPSC350-02
Programming Assignment 6: Spanning the Gamut
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "WGraph.h"

using namespace std;


class FileProcessor {
public:
    FileProcessor(string& inputFileName);
    virtual ~FileProcessor();
    void runProgram();
private:
    ifstream m_inputFileName;

};

#endif