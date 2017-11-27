#include <iostream>
#include <sstream>
#include <fstream>

#include "readFile.h"


int main() {

    std::string fname("/Users/davidcleres/CLionProjects/PCSC2017_Group5/test.txt");
    ReadFile readFile(fname);

    std::cout << readFile.loadFromFile() << std::endl;

    return 0;
}