//
// Created by David Cleres on 29.11.17.
//

#ifndef PCSC2017_GROUP5_DFT_H
#define PCSC2017_GROUP5_DFT_H


#include <complex.h>
#include "AbstractNumericalApproximation.h"
class DFT
{
private:

public:

    void realDFT(const vector<double> &inreal, const vector<double> &inimag,
                 vector<double> &outreal, vector<double> &outimag);

    vector<complex<double>> computeDFT (const vector<complex<double> > &input);

};


#endif //PCSC2017_GROUP5_DFT_H
