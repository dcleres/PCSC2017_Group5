/**
 * \file main.cpp
 * \brief This is the function to call to run the script of the project
 */

#include <iostream>
#include <vector>

#include "readFile.h"
#include "MultMat.h"

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

    /*MultMat
    Matrice M1(lire_matrice()), M2(lire_matrice());

    if (M1[0].size() != M2.size())
        cout << "Multiplication de matrices impossible !" << endl;
    else {
        cout << "Résultat :" << endl;
        affiche_matrice(multiplication(M1, M2));
    }*/

    return 0;
}