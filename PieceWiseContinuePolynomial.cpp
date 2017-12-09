#include <iostream>
#include <cmath>
#include "readFile.h"
#include "PieceWiseContinuePolynomial.h"
#include "Polynomial.h"
#include "Lagrange.h"

using namespace std ;


vector<double> PieceWiseContinuePolynomial::solve_least_square(size_t const& degree,int const& Intervalle,vector<double> const& x_plot) const
{
    size_t N (mData.heights.size());
    size_t nb_intervalle (N / Intervalle);
    vector<vector<double>> x((Intervalle), vector<double>(nb_intervalle));                                      //We declare the matrix that we will need to store in each line each point of just one interval.
    vector<vector<double>> y((Intervalle), vector<double>(nb_intervalle));                                      //Each line correspond to one interval and each colunm in one line correspond to one point in the interval
    if (Intervalle % 2 == 0) {                                                                                  //If the number of interval choosen is even we separate the data in that way
        for (int i = 1; i <= Intervalle; ++i) {
            for (size_t j ((nb_intervalle) * (i - 1)); j < (nb_intervalle * i); ++j) {
                x[i - 1][j - ((i - 1) * nb_intervalle)] = mData.heights[j];
                y[i - 1][j - ((i - 1) * nb_intervalle)] = mData.weights[j];
            }
        }
    } else {                                                                                                    //If the number of interval is odd we need to adjust index
        ///////////////////A implementer !!!!!!!
        cout << "Le nombre d'intervalle doit être pair" << endl;
    }

    vector<double> Y_return(x_plot.size());
    Polynomial polynomial;
    vector<double> tmpx(nb_intervalle);
    vector<double> tmpy(nb_intervalle);
    for (size_t i(1); i <= Intervalle; i++) {
        for (size_t j(0); j < (nb_intervalle); ++j) {                                                             //With the for loop, we select the points of one interval and we put it on a vector tmp.
            tmpx[j] = x[i - 1][j];
            tmpy[j] = y[i - 1][j];
        }

        vector<double> a(polynomial.solve(tmpx, tmpy, degree));                                                 //We apply Least Square method on the data of the interval.

        for (size_t k ((x_plot.size() / Intervalle) * (i - 1)); k < ((x_plot.size() / Intervalle) * i); ++k) {
            for (int z = 0; z < (degree + 1); z++) {
                Y_return[k] += pow(x_plot[k], z) * a[z];
            }
        }
    }

    return Y_return;
}

vector<double> PieceWiseContinuePolynomial::solve_lagrange(int const& Intervalle, vector<double> const& x_plot) const
{
    size_t N  (mData.heights.size());
    size_t nb_intervalle (N / Intervalle);
    vector<vector<double>> x((Intervalle), vector<double>(nb_intervalle));                                      //We declare the matrix that we will need to store in each line each point of just one interval.
    vector<vector<double>> y((Intervalle), vector<double>(nb_intervalle));                                      //Each line correspond to one interval and each colunm in one line correspond to one point in the interval
    if (Intervalle % 2 == 0) {                                                                                  //If the number of interval choosen is even we separate the data in that way
        for (size_t i(1); i <= Intervalle; ++i) {
            for (size_t j((nb_intervalle) * (i - 1)); j < (nb_intervalle * i); ++j) {
                x[i - 1][j - ((i - 1) * nb_intervalle)] = mData.heights[j];
                y[i - 1][j - ((i - 1) * nb_intervalle)] = mData.weights[j];
            }
        }
    } else {                                                                                                    //If the number of interval is odd we need to adjust index
        ///////////////////A implementer !!!!!!!
        cout << "Le nombre d'intervalle doit être pair" << endl;
    }

    vector<double> Y_return(x_plot.size());
    Polynomial polynomial;
    vector<double> tmpx(nb_intervalle);
    vector<double> tmpy(nb_intervalle);
    for (int i = 1; i <= Intervalle; i++) {
        for (int j = 0; j < (nb_intervalle); ++j) {                                                             //With the for loop, we select the points of one interval and we put it on a vector tmp.
            tmpx[j] = x[i - 1][j];
            tmpy[j] = y[i - 1][j];
        }

        Lagrange lagrange;
        for (int k = (x_plot.size() / Intervalle) * (i - 1); k <= ((x_plot.size() / Intervalle) * i); ++k) {                 //We apply Least Square method on the data of the interval.
                Y_return[k]= lagrange.solve(tmpx,tmpy,x_plot[k]);
        }
    }
    return Y_return;
}

PieceWiseContinuePolynomial::PieceWiseContinuePolynomial(Data const &data)
:mData(data)
{}
