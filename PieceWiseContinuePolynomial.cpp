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

vector<vector<double>> PieceWiseContinuePolynomial::solve_lagrange_degree(int const& degree, vector<double> const& x_plot) const
{
    size_t N  (mData.heights.size());
    cout << N<< endl;
    size_t nb_intervalle (degree+1); cout <<nb_intervalle<<endl;
    size_t Intervalle(N/(degree+1));
    size_t reste(N%(degree+1));
    vector<vector<double>> x((Intervalle), vector<double>(nb_intervalle));                                      //We declare the matrix that we will need to store in each line each point of just one interval.
    vector<vector<double>> y((Intervalle), vector<double>(nb_intervalle));                                      //Each line correspond to one interval and each colunm in one line correspond to one point in the interval
    //If the number of interval choosen is even we separate the data in that way
    for (size_t i(1); i <= Intervalle; ++i) {
        if (i==Intervalle and reste !=0)
        {
            for (size_t j((nb_intervalle) * (i - 1)); j <= (nb_intervalle * i); ++j) {
                if (j==((nb_intervalle*Intervalle))) {
                    for (size_t z(0); z < reste; z++){
                        x[i-1].push_back(mData.heights[j+z]);
                        y[i-1].push_back(mData.weights[j+z]);
                    }
                } else {
                    x[i - 1][j - ((i - 1) * nb_intervalle)] = mData.heights[j];
                    y[i - 1][j - ((i - 1) * nb_intervalle)] = mData.weights[j];
                }
            }

        } else {
            for (size_t j((nb_intervalle) * (i - 1)); j <= (nb_intervalle * i); ++j) {
                x[i - 1][j - ((i - 1) * nb_intervalle)] = mData.heights[j];
                y[i - 1][j - ((i - 1) * nb_intervalle)] = mData.weights[j];
            }
        }
        for (int z(0); z<x[1].size();++z){cout <<x[1][z]<<endl;}
        cout << x[1][(x[1].size()-1)]<<"//////////////"<<endl;
    }

    vector<vector<double>> approx(2,vector<double>(0));
    vector<double> tmpx(nb_intervalle);
    cout << "fuck fuck 222"<<endl;
    vector<double> tmpy(nb_intervalle);
    cout << "fuck" << endl;
    for (int i(1); i <= Intervalle; i++) {
        for (int j = 0; j <=nb_intervalle; ++j) {
            tmpx[j] = x[i - 1][j];
            tmpy[j] = y[i - 1][j];
            if(reste!=0 and i==Intervalle and j==nb_intervalle){
                for (size_t z(0); z<reste;++z){
                    tmpx.push_back(x[i - 1][j+z]);
                    tmpy.push_back(y[i - 1][j+z]);
                }
            }
        }
        Lagrange lagrange;
        for (size_t k(0); k < x_plot.size(); ++k) {//We apply Least Square method on the data of the interval.
            if (x_plot[k]>=tmpx[0] and x_plot[k]<tmpx[(tmpx.size()-1)]) {
                approx[0].push_back(x_plot[k]);
                approx[1].push_back(lagrange.solve(tmpx, tmpy, x_plot[k]));
            }
        }
    }
    return approx;

}


PieceWiseContinuePolynomial::PieceWiseContinuePolynomial(Data const &data)
:mData(data)
{}
/*
void PieceWiseContinuePolynomial :: create_interval(vector<vector<double>>& x,vector<vector<double>>& y, int const) {
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
}*/