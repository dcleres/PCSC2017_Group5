//
// Created by pcsc on 12/6/17.
//

#include <iostream>
#include <cmath>
#include <complex>
#include "FourierApproximation.h"

using namespace std;

double FourierApproximation::integre(Fonction f, double const& a, double const& b)
{
    double res;
    res =  41.0 * ( f(a) + f(b) )
           + 216.0 * ( f((5*a+b)/6.0) + f((5*b+a)/6.0) )
           +  27.0 * ( f((2*a+b)/3.0) + f((2*b+a)/3.0) )
           + 272.0 * f((a+b)/2.0) ;
    res *= (b-a)/840.0;
    return res;
}

double FourierApproximation::integre(FonctionComplex f, Fonction f_init, double const& a, double const& b, int const& n)
{
    double res;
    res =  41.0 * ( f(a, f_init,n) + f(b, f_init,n) )
           + 216.0 * ( f((5*a+b)/6.0, f_init,n) + f((5*b+a)/6.0, f_init,n) )
           +  27.0 * ( f((2*a+b)/3.0, f_init,n) + f((2*b+a)/3.0, f_init,n) )
           + 272.0 * f((a+b)/2.0, f_init,n) ;
    res *= (b-a)/840.0;
    return res;
}

std::complex complexFunction(double const& x, Fonction f, int const& n)
{
    std::complex<double> z = std::exp(-1i * x * n);
    return f*z;
}

vector<double> FourierApproximation::fourierCoefficients(Fonction f, int const& n)
{
    vector<double> coefs(2*abs(n)+1);
    double coef_zero(integre(f, -M_PI, M_PI));
    coefs[n]=coef_zero;
    cout << "coef zero is " << coef_zero;
    //We always compute both i and -i
    for (int i(-n); i < n; i++)
    {
        if (i != 0)
        {
            coefs[i+n] = integre(complexFunction, f, -M_PI, M_PI, n);
        }
    }
}

//on a mainteant les coefficent mais on doit donc juste faire la formule qui est la sommes de -n à n (desktop)

