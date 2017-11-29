//
// Created by pcsc on 11/29/17.
//

#ifndef PROJECT_POLYNOMIAL_H
#define PROJECT_POLYNOMIAL_H

#include <array>

using namespace std ;

class Polynomial
{

public:
    virtual ~polynomial() ;

    // Approximation polynomiale des points par la mÃ©thode de lagrange (ressort les coefs de lagrange)
    void solve(Data data, int degree);

    // overwritten pour PWNC
    void solve(double* x,double** M,int Npts);
};

#endif //PROJECT_POLYNOMIAL_H
