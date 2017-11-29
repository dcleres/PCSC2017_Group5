//
// Created by pcsc on 11/29/17.
//

#include<vector>
#include "Lagrange.h"

vector<double>* Lagrange :: lagrange_coeffs(const vector<point_t> points) {
    auto len = points.size();
    auto res = new vector<double> (len, 0);

    for (auto curpoint : points) {
        vector<double> tmpcoeffs (len, 0);
        // Start with a constant polynomial
        tmpcoeffs[0] = curpoint.y;
        double prod = 1;
        for(auto point : points) {
            if (curpoint.x == point.x) continue;
            prod *= curpoint.x - point.x;
            double precedent = 0;
            for (auto resptr = tmpcoeffs.begin(); resptr < tmpcoeffs.end(); resptr++) {
                // Compute the new coefficient of X^i based on
                // the old coefficients of X^(i-1) and X^i
                double newres = (*resptr) * (-point.x) + precedent;
                precedent = *resptr;
                *resptr = newres;
            }
        }
        transform(res->begin(), res->end(),
                  tmpcoeffs.begin(),
                  res->begin(),
                  [=] (double oldcoeff, double add) {return oldcoeff+add/prod;}
        );
    }
    return res;
}


void Lagrange :: print_lagrange_coef(const vector<point_t> points){
    for (auto coeff : *lagrange_coeffs(points)) {
        cout << coeff << endl;
    }
}

double Lagrange :: poly_eval(const vector<double> coeffs, double point) {
    double res = 0;
    double multiplier = 1;
    for(double coeff: coeffs) {
        res += coeff * multiplier;
        multiplier *= point;
    }
    return res;
}