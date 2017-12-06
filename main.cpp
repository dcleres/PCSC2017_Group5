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

/*unsigned int bitReverse(unsigned int x, int log2n) {
    int n = 0;
    int mask = 0x1;
    for (int i=0; i < log2n; i++) {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n; }
const double PI = 3.1415926536;
template<class Iter_T>
void FFT(Iter_T a, Iter_T b, int log2n)
{
    typedef typename iterator_traits<Iter_T>::value_type complex;
    const complex J(0, 1);
    int n = 1 << log2n;
    for (unsigned int i=0; i < n; ++i) {
        b[bitReverse(i, log2n)] = a[i];
    }
    for (int s = 1; s <= log2n; ++s) {
        int m = 1 << s;
        int m2 = m >> 1;
        complex w(1, 0);
        complex wm = exp(-J * (PI / m2));
        for (int j=0; j < m2; ++j) {
            for (int k=j; k < n; k += m) {
                complex t = w * b[k + m2];
                complex u = b[k];
                b[k] = u + t;
                b[k + m2] = u - t;
            }
            w *= wm; }
    } }*/

int main() {

    std::string fname("/home/pcsc/Desktop/PCSC2017_Group5/data/data.dat");
    ReadFile readFile(fname);

    vector<double> xs;
    vector<double> ys;
    Data data = {xs, ys};

    readFile.loadFromFile(data);
    readFile.show(data);

    // Lagrange :
    //Lagrange lagrange;
    //vector<vector<double>> points = lagrange.solve(data, 3);
    //cout << "coucou"<<endl;
    //vector <double> x (points.size());
    //vector<double> y (points.size());
    //plot the approximation
    //for (int i=0; i<points.size();++i){
        //for (int j=0; i<points[0].size();++j){

      //      x[i]=points[i][0];
        //    y[i]=points[i][1];
        //}
   // }

    //Least Squares
    Polynomial poly;
    int degree = 3;
    vector <double> a (poly.solve(data, degree));
    vector<double>x(21);
    vector<double>y(21);
    for (int i=0;i<(degree+1);i++){

        cout<<" + ("<<a[i]<<")"<<"x^"<<i<<endl;
    }

    for (int d=0; d<21;++d){
        x[d]= (1+ 0.1*d);
    }
    for (int j=0; j<20;++j) {
        for (int i = 0; i <(degree+1); i++) {
            y[j]+=pow(x[j],i)*a[i];
        }
    }

    Lagrange lagrange;
    vector<double>x2(31);
    vector<double>y2(31);
    for (int d=0; d<31;++d){
        x2[d]= (1+ 0.1*d);
    }
    for (int j=0; j<30;++j) {
        y2[j]=lagrange.solve(data,x2[j]);
    }

    PieceWise_Continue_Polynomial piece;
    vector<double>y3(piece.solve(data,1,2,x2));


    //on doit plotter data_copy ou on a changé les valeurs des x associé aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x2,y3,"Approximation");
    sleep(10);

    //int taille = 10;
   // vector<double> ptX(taille); // points given by the user
    //vector<double> ptY(taille);
    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(20);





    return 0;
}