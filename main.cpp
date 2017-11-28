#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "readFile.h"

using namespace std;

int main() {

    std::string fname("/Users/davidcleres/CLionProjects/PCSC2017_Group5/height_weight_genders.txt");
    ReadFile readFile(fname);

    vector<double> weights;
    vector<double> heights;
    vector<Gender> genders;

    std::cout << << std::endl;

    return 0;
}