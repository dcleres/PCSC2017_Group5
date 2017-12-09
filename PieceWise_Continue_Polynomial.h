#ifndef PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H
#define PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H


#include <iostream>
#include <cassert>
#include <cmath>
#include "readFile.h"

using namespace std;

class PieceWise_Continue_Polynomial {

public:

    vector<double> solve_least_square(Data data, int degree, int Intervale,vector<double>x_plot);
    vector<double> solve_lagrange(Data& data, int Intervalle, vector<double>x_plot) ;


private:

};




#endif //PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H