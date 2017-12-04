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
    ///@method Function that allows us to print the weight return by the approximation function
    void printWeight (vector<double> const& weight);
    void GaussianElimination(vector<vector<double>> A, vector<double> b,int number_point);
    void Solve(vector<vector<double>> A, vector<double>b, int t, vector<double> x);


    ~AbstractNumericalApproximation();
private:
    void Swap(vector<vector<double>> A, vector<double> b, const int k,int number_point);

};

#endif //PCSC2017_GROUP5_ABSTRACTNUMERICALAPPROXIMATION_H