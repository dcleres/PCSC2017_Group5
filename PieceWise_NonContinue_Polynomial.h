//
// Created by pcsc on 12/2/17.
//

#ifndef PCSC2017_GROUP5_PIECEWISE_NONCONTINUE_POLYNOMIAL_H
#define PCSC2017_GROUP5_PIECEWISE_NONCONTINUE_POLYNOMIAL_H
#include "AbstractNumericalApproximation.h"
#include "Polynomial.h"

using namespace std ;

// HOW INHERIT POLYNOMIAL ?
class PieceWise_NonContinue_Polynomial : public Polynomial {

public:

    // Piece-wise approximation polynomial avec DERIVEE NON CONTINUE
    void solve(Data data, int degree, vector<vector<double>> Intervale, int nb_intervale,vector<vector<double>>T);

};
#endif //PCSC2017_GROUP5_PIECEWISE_NONCONTINUE_POLYNOMIAL_H
