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
#include "readFile.h"
#include "gnuplot_i.hpp"
#include "FFT.h"

complex<double> cx;

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

    std::string fname("/Users/davidcleres/CLionProjects/PCSC2017_Group5/height_weight_genders.txt");
    ReadFile readFile(fname);

    vector<double> weights;
    vector<double> heights;
    vector<Gender> genders;

    Data data = {genders, heights, weights};

    readFile.loadFromFile(data);
    readFile.show(data);


    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(weights,heights,"Approximation");
    sleep(1);

    //g1.plot_xy(ptX,ptY,"Default points"); //Display a second graph
    sleep(20);

    /*MultMat
    Matrice M1(lire_matrice()), M2(lire_matrice());

    if (M1[0].size() != M2.size())
        cout << "Multiplication de matrices impossible !" << endl;
    else {
        cout << "Résultat :" << endl;
        affiche_matrice(multiplication(M1, M2));
    }*/

    return 0;
}