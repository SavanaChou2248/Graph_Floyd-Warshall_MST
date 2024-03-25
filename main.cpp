#include "WGraph.h"
#include "FileProcessor.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    string inputFile = argv[1];
    FileProcessor test(inputFile);

    test.runProgram();
    
    return 0;
}
