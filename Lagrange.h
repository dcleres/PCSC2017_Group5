/**
 * \file Lagrange.h
 * \brief This is redefinition of the virtual class to implement Lagrange functions
 * \class Lagrange
 * This is how we can calculate the approximation of the data using Lagrange Polynome
 */

#ifndef PCSC2017_GROUP5_LAGRANGE_H
#define PCSC2017_GROUP5_LAGRANGE_H


#include <iostream>
#include <vector>
#include <algorithm>
#include "readFile.h"

using namespace std;

class Lagrange{


public:
    //Lagrange return directly the point corresponding to the argument xi
    double solve(vector<double> const& data_x,vector<double> const& data_y,double xi);

private:
};

#endif //PCSC2017_GROUP5_LAGRANGE_H