/**
 * \file main.cpp
 * \brief This is the function to call to run the script of the project
 */

#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>

#include <iostream>
#include <vector>
#include <complex>
//#include <zconf.h>
#include "readFile.h"
#include "gnuplot_i.hpp"
#include "FFT.h"
#include "Polynomial.h"
#include "Lagrange.h"
#include "LeastSquare.h"
#include "PieceWise_Continue_Polynomial.h"

using namespace std;

int main() {

    std::string fname("/home/pcsc/Desktop/PCSC2017_Group5/data/data.dat");
    ReadFile readFile(fname);

    vector<double> xs;
    vector<double> ys;
    Data data = {xs, ys};

    readFile.loadFromFile(data);
    readFile.show(data);

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
    vector<double>y3(piece.solve(data,1,2,x2));

    //on doit plotter data_copy ou on a changé les valeurs des x associé aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x2,y3,"Approximation");
    sleep(10);

    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(20);

    return 0;
}