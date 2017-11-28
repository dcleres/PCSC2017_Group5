/**
 * \file main.cpp
 * \brief This is the function to call to run the script of the project
 */

#include <iostream>
#include <vector>

#include "readFile.h"

using namespace std;

int main() {

    std::string fname("/Users/davidcleres/CLionProjects/PCSC2017_Group5/height_weight_genders.txt");
    ReadFile readFile(fname);

    vector<double> weights;
    vector<double> heights;
    vector<Gender> genders;

    Data data = {genders, heights, weights};

    readFile.loadFromFile(data);
    readFile.show(data);

    return 0;
}