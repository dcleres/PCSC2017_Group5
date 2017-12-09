/**
 * \file Lagrange.h
 * \brief This is redefinition of the virtual class to implement Lagrange functions
 * \class Subclass of AbstractNumericalApproximation
 * This is how we can calculate the approximation of the data using Lagrange Polynome
 */

#ifndef PCSC2017_GROUP5_LAGRANGE_H
#define PCSC2017_GROUP5_LAGRANGE_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "readFile.h"
#include "AbstractNumericalApproximation.h"

using namespace std;

class Lagrange : public AbstractNumericalApproximation{


public:
    //Lagrange return directly some points
    double solve(Data data, double xi) ;
    double solve(vector<double> const& data_x,vector<double> const& data_y,double xi)

private:
    double getmax(vector<double>x);
    double getmin(vector<double>x);
};

#endif //PCSC2017_GROUP5_LAGRANGE_H