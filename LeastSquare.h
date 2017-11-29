/**
 * \file LeastSquares.h
 * \brief This is redefinition of the virtual class to implement LeastSquares functions
 * \class Subclass of AbstractNumericalApproximation
 * This is how we can approximate data
 */

#ifndef PCSC2017_GROUP5_LEASTSQUARE_H
#define PCSC2017_GROUP5_LEASTSQUARE_H
using namespace std;
#include "AbstractNumericalApproximation.h"

class LeastSquare {

public:
    //virtual vector<double> approximationFunction(Data const& data, unsigned int degre);
    //vector<double> mldivide ();
    void solve_least_square(Data data,int degree);
private:

};
#endif //PCSC2017_GROUP5_LEASTSQUARES_H

#include <vector>

#endif //PCSC2017_GROUP5_LEASTSQUARE_H
