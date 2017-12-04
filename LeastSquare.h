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

class LeastSquare : public AbstractNumericalApproximation {

public:
    void solve(Data data,int degree, vector<vector<double>> beta);
private:

};

#endif //PCSC2017_GROUP5_LEASTSQUARE_H