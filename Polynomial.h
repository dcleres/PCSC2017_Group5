/**
 * \file Polynomial.h
 * \brief This is the function to call to run the script of the project
 */

#ifndef PROJECT_POLYNOMIAL_H
#define PROJECT_POLYNOMIAL_H

#include <array>
#include "AbstractNumericalApproximation.h"

using namespace std ;

class Polynomial : public AbstractNumericalApproximation {

public:
    // Approximation polynomial des points par la methode de lagrange (ressort les coefs de lagrange)
    vector<double> solve(Data const& data, size_t const& degree);
    vector<double> solve(vector<double> const& data,vector<double> const& data_y, size_t const& degree);

    // overwritten pour PieceWiseNonContinue
    void solve(Data const& data);
};

#endif //PROJECT_POLYNOMIAL_H