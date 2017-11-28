//
// Created by nicol on 28.11.2017.
//

#ifndef PCSC2017_GROUP5_LEASTSQUARES_H
#define PCSC2017_GROUP5_LEASTSQUARES_H

/**
 * \file AbstractNumericalApproximation.h
 * \brief This is the virtual class we will use to implement all the approximations functions
 * \class AbstractNumericalApproximation
 * This is a pure virtual class
 */
using namespace std;
#include "AbstractNumericalApproximation.h"

class LeastSquares {

public:
    virtual vector<double> approximationFunction(Data const& data);

private:

};
#endif //PCSC2017_GROUP5_LEASTSQUARES_H
