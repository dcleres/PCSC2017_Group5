//
// Created by pcsc on 11/29/17.
//

#ifndef PROJECT_POLYNOMIAL_H
#define PROJECT_POLYNOMIAL_H

#include <array>
#include "AbstractNumericalApproximation.h"

using namespace std ;

class Polynomial : public AbstractNumericalApproximation {

public:

    // Approximation polynomial des points par la methode de lagrange (ressort les coefs de lagrange)
    void solve(Data data, int degree);

    // overwritten pour PieceWiseNonContinue
    void solve(Data data);
};

#endif //PROJECT_POLYNOMIAL_H