//
// Created by nicol on 28.11.2017.
//

#ifndef PCSC2017_GROUP5_LEASTSQUARES_H
#define PCSC2017_GROUP5_LEASTSQUARES_H

/**
 * \file LeastSquares.h
 * \brief This is redefinition of the virtual class to implement LeastSquares functions
 * \class Subclass of AbstractNumericalApproximation
 * This is how we can approximate data
 */
using namespace std;
#include "AbstractNumericalApproximation.h"

class LeastSquares {

public:
    virtual vector<double> approximationFunction(Data const& data);

private:

};
#endif //PCSC2017_GROUP5_LEASTSQUARES_H
