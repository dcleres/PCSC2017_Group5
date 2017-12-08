//
// Created by pcsc on 12/6/17.
//

#include <vector>

#ifndef PCSC2017_GROUP5_FOURIERAPPROXIMATION_H
#define PCSC2017_GROUP5_FOURIERAPPROXIMATION_H

using namespace std;

typedef double (* Fonction)(double);
typedef std::complex (* FonctionComplex)(double const&, Fonction, int const&);


class FourierApproximation {
private:

    /*
     * @method pointer on function to compute the integral on
     */
    double integre(Fonction f, double const& a, double const& b);

    /*
     * @method pointer on function to compute the integral on
     */
    double integre(FonctionComplex f, Fonction f_init, double const& a, double const& b, int const& n);

    /*
     * @method pointer on function to compute the integral on
     */
    vector<double> fourierCoefficients(Fonction f, int const& n);
};


#endif //PCSC2017_GROUP5_FOURIERAPPROXIMATION_H
