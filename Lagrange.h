//
// Created by pcsc on 11/29/17.
//

#ifndef PCSC2017_GROUP5_LAGRANGE_H
#define PCSC2017_GROUP5_LAGRANGE_H




#include <iostream>
#include <vector>
#include <algorithm>
#include "readFile.h"

using namespace std;



/**
* Lagrane_coeffs generate the polynomials coefficients of the lagrange interpolation polynomial
* for the given points
 * The polynomial is such that for all i P(x_i) = y_i.
  This program works in O(N^3) where N is the number of input points.
*/

/**
Poly eval take a vector containing polynomial coefficient, and evaluates the polynomial
function at the points given on standard input.
**/
class Lagrange {

public:
    vector<double>* lagrange_coeffs(const vector<point_t> points);

    void print_lagrange_coef(const vector<point_t> points);

    double poly_eval(const vector<double> coeffs, double point);

private:


};


#endif //PCSC2017_GROUP5_LAGRANGE_H
