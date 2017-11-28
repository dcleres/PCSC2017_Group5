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

#include <string>
#include <fstream>
#include readFile.h;
using namespace std;


class AbstratcNumericalApproximation {

    //Virtual Method that we will implement in the sub-class
    //It return a vector of double, the weight we found after apply the function
    //It takes Data as a parameter, a structure made of two vector of double and one vector of Gender (Gender is a enum type)
    virtual vector<double> approximationFunction(Data) = 0;

    //Function that allows us to print the weight return by the approximation function
    virtual void printWeight (vector<double>);

};






#endif //PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H