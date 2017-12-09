/**
 * \file Polynomial.h
 * \brief
 */

#ifndef PROJECT_POLYNOMIAL_H
#define PROJECT_POLYNOMIAL_H

#include <array>

using namespace std ;

class Polynomial {

public:
    vector<double> solve(vector<double> const& data,vector<double> const& data_y, size_t const& degree);
};

#endif //PROJECT_POLYNOMIAL_H