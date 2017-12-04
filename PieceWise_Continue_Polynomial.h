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

    void solve(Data data, int degree, vector<vector<double>>Intervale,vector<vector<double>>coefs_poly);

private:

};




#endif //PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H