//
// Created by pcsc on 11/30/17.
//

#ifndef PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H
#define PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H


#include <iostream>
#include <cassert>
#include <cmath>
#include "readFile.h"
#include "AbstractNumericalApproximation.h"

class PieceWise_Continue_Polynomial : public AbstractNumericalApproximation {

public:

    vector<double> solve(Data data, int degree, int Intervale,vector<double>x_plot);

private:

};




#endif //PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H