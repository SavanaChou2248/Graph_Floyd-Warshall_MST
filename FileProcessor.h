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
