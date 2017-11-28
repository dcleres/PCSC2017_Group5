/**
 * \file AbstractNumericalApproximation.h
 * \brief This is the virtual class we will use to implement all the approximations functions
 * This is a pure virtual class
 */

#ifndef PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H
#define PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H

#include "readFile.h"

using namespace std;

class AbstractNumericalApproximation {

public:
    ///\method
    ///\brief Virtual Method that we will implement in the sub-class
    ///It return a vector of double, the weight we found after apply the function
    ///It takes Data as a parameter, a structure made of two vector of double and one vector of Gender (Gender is a enum type)
    virtual vector<double> approximationFunction(Data const& data) = 0;

    ///@method Function that allows us to print the weight return by the approximation function
    void printWeight (vector<double> const& weight);

private:

};

#endif //PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H