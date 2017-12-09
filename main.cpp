/*! \mainpage Data Approximation
 *
 * This project helps user to approximate data that he can her-/himself plug into the program using the data.dat file.
 * Currently two types of shapes can be drawn:
 * - \subpage LagrangePolynomial Functions "How to use the Lagrange method?"
 *
 * - \subpage FourierTransforms "How to does the Fourier Approximation works?"
 *
 */

/*! \page LagrangePolynomial How to use the Lagrange method?
 *
 * Lorem ipsum dolor sit amet
 *
 */

/*! \page FourierTransforms How to does the Fourier Approximation works?
 *
 * This page is about how to draw a circle.
 * Following sections describe circle:
 * - \ref groupCircleDefinition "Definition of Circle"
 * - \ref groupCircleClass "Circle Class"
 */


/**
 * \file main.cpp
 * \brief This is the function to call to run the script of the project
 */

#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <unistd.h>
#include <vector>
#include <complex>
#include "readFile.h"
#include "gnuplot_i.hpp"
#include "Polynomial.h"
#include "Lagrange.h"
#include "LeastSquare.h"
#include "PieceWise_Continue_Polynomial.h"
#include "FFTreal.h"

using namespace std;

int main() {
    std::string fname("/home/pcsc/Desktop/PCSC2017_Group5/data/data.dat");
    ReadFile readFile(fname);

    vector<double> xs;
    vector<double> ys;
    Data data = {xs, ys};

    readFile.loadFromFile(data);
    readFile.show(data);

    Data data_original = data;

    /*
    //Least Squares
    Polynomial poly;
    int degree = 3;
    vector <double> a (poly.solve(data, degree));
    vector<double>x(21);
    vector<double>y(21);
    for (size_t i(0); i < (degree+1);i++){

        cout<< " + ("<<a[i]<<")"<<"x^"<<i<<endl;
    }

    for (size_t d(0); d <21; ++d)
    {
        x[d] = (1 + 0.1*d);
    }
    for (size_t j(0); j<20; ++j)
    {
        for (size_t i(0); i < (degree+1); i++)
        {
            y[j]+=pow(x[j],i)*a[i];
        }
    }

    Lagrange lagrange;
    vector<double>x2(31);
    vector<double>y2(31);
    for (size_t d(0); d < 31;++d)
    {
        x2[d]= (1+ 0.1*d);
    }
    for (size_t j(0); j < 30; ++j)
    {
        y2[j] = lagrange.solve(data,x2[j]);
    }


    PieceWise_Continue_Polynomial piece;
    vector<double>y3(piece.solve(data,1,2,x2));*/

    //////////////////////// COMPUTE THE FFT /////////////////////////////////////////////////
    FFTreal fft;
    vector<double> imaginary_part(data.heights.size(), 0.0);
    fft.transform(data.weights, imaginary_part);

    //data.heights = data_original.heights;

    vector<double> ifft(data.weights);
    fft.inverseTransform(ifft, imaginary_part);


    //////////////////////// COMPUTE THE FOURIER APPROXIMATION ////////////////////////////////
    size_t nbK(data.weights.size()); //number of ak and bk to compute
    vector<double> an(nbK, 0.0);
    vector<double> bn(nbK, 0.0);

    //we used cos(pi*x which has a period of 2
    fft.transformCoefs(data_original.weights, an, bn, 2);
    vector<double> approx (fft.transformApproximation(an,bn,2,data_original.weights));

    //cout << "WORD" << endl;
    /*for (auto& element : data.weights)
    {
        element /= 10; //(2*M_PI); //F = 1/(2*PI) * F-¹
    }*/
    /*for (auto element : data.heights)
    {
        cout << element << endl;
    }*/

    /*FourierApproximation approx;
    int n (10);
    vector<double> v = approx.fourierCoefficients(f1, n);

    vector<double> weightsApprox(data.heights.size());
    for(size_t i(0); i < weightsApprox.size(); i++)
    {
        weightsApprox[i] = approx.fourierApproximation(v, data.heights[i], n);
    }*/

    //FAIRE AVEC DES COSINUS ET SINUS ET PUIS PAS DES COMPLEXES ET C'EST CHILL

    /*double a(0);
    double b(0);

    double* a_ptr(&a);
    double* b_ptr(&b);

    double t1(0);
    double t2(2*M_PI);

    vector<double> ans(5);
    vector<double> bns(5);

    for (int n(0); n < 6; n++)
    {
        AnalyticFourierHn(t1,t2, n, a_ptr, b_ptr);
        ans[n] = *a_ptr;
        bns[n] = *b_ptr;
    }

    vector<double> results(data.heights.size());
    for (int i(0); i < data.heights.size(); i++)
    {
        results[i] = approxFunction (data.heights[i], ans, bns);
    }*/

    for (auto& element : ifft) {
        element /= ifft.size();
    }

    //on doit plotter data_copy où on a changé les valeurs des x associée aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(data_original.heights,data.weights,"Approximation");
    sleep(2);
    g1.plot_xy(data_original.heights,ifft,"Inverse FFT");
    sleep(2);
    g1.plot_xy(data_original.heights,data_original.weights,"Default points");
    sleep(2);
    g1.plot_xy(data_original.heights,approx,"Fourier");
    sleep(20);

    return 0;
}