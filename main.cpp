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
#include "FFT.h"
#include "Polynomial.h"
#include "Lagrange.h"
#include "LeastSquare.h"
#include "PieceWise_Continue_Polynomial.h"
#include "FFTreal.h"

using namespace std;

double f1(double x) { return x*x;             }
double f2(double x) { return sqrt(exp(x));    }
double f3(double x) { return log(1.0+sin(x)); }

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


    FFTreal fft;
    fft.transform(data.heights, data.weights);
    for (auto element : data.weights)
    {
        cout << element << endl;
    }
    data.heights = data_original.heights;
    fft.inverseTransform(data.heights, data.weights);
    cout << "WORD" << endl;
    /*for (auto& element : data.weights)
    {
        element /= 10; //(2*M_PI); //F = 1/(2*PI) * F-¹
    }*/
    for (auto element : data.heights)
    {
        cout << element << endl;
    }

    //on doit plotter data_copy où on a changé les valeurs des x associée aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(data_original.heights,data.weights,"Approximation");
    sleep(2);

    g1.plot_xy(data_original.heights,data_original.weights,"Default points");
    sleep(20);

    return 0;
}