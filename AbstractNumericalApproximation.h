//
// Created by nicol on 28.11.2017.
//

#ifndef PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H
#define PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H


/**
 * \file AbstractNumericalApproximation.h
 * \brief This is the virtual class we will use to implement all the approximations functions
 * \class AbstractNumericalApproximation
 * This is a pure virtual class
 */

#include readFile.h;
using namespace std;


class AbstractNumericalApproximation {

public:
    //Virtual Method that we will implement in the sub-class
    //It return a vector of double, the weight we found after apply the function
    //It takes Data as a parameter, a structure made of two vector of double and one vector of Gender (Gender is a enum type)
    virtual vector<double> approximationFunction(Data data) = 0;

    //Function that allows us to print the weight return by the approximation function
    void printWeight (vector<double> weight);

private:



};






#endif //PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H