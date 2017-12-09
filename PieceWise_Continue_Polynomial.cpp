//
// Created by pcsc on 11/30/17.
//


#include <iostream>
#include <cassert>
#include <cmath>
#include "readFile.h"
#include "PieceWise_Continue_Polynomial.h"
#include "Polynomial.h"
#include "Lagrange.h"

using namespace std ;


/// Piece-wise polynomial approximation with continuous derivative using polynoms
vector<double> PieceWise_Continue_Polynomial::solve_least_square(Data data, int degree,int Intervalle,vector<double>x_plot) //double** coefs_poly,config configuration,double** M,double** Intervale, int& nb_intervale)
{
    cout << endl;

    int N = data.heights.size();
    int nb_intervalle = N / Intervalle;
    vector<vector<double>> x((Intervalle), vector<double>(nb_intervalle));
    vector<vector<double>> y((Intervalle), vector<double>(nb_intervalle));
    if (Intervalle % 2 == 0) {
        for (int i = 1; i <= Intervalle; ++i) {
            for (int j = (nb_intervalle) * (i - 1); j < (nb_intervalle * i); ++j) {
                x[i - 1][j - ((i - 1) * nb_intervalle)] = data.heights[j];
                y[i - 1][j - ((i - 1) * nb_intervalle)] = data.weights[j];
            }

        }
    } else {
        cout << "pour l'instant je sais pas comment faire" << endl;
    }

    vector<double> Y_return(x_plot.size());
    Polynomial polynomial;
    vector<double> tmpx(nb_intervalle);
    vector<double> tmpy(nb_intervalle);
    for (int i = 1; i <= Intervalle; i++) {
        for (int j = 0; j < (nb_intervalle); ++j) {
            tmpx[j] = x[i - 1][j];
            tmpy[j] = y[i - 1][j];
        }

        vector<double> a(polynomial.solve(tmpx, tmpy, degree));
        //for (int j = (nb_intervalle)*(i-1); j < (nb_intervalle*i); ++j) {
        //  for (int z=0; z<(degree+1); z++) {
        //    Y_return[j]+=pow(x[i-1][j-((i-1)*nb_intervalle)],z)*a[z];

        //}
        //}
        for (int k = (x_plot.size() / Intervalle) * (i - 1); k < ((x_plot.size() / Intervalle) * i); ++k) {
            for (int z = 0; z < (degree + 1); z++) {
                Y_return[k] += pow(x_plot[k], z) * a[z];
            }
        }
    }

    return Y_return;
}

vector<double> PieceWise_Continue_Polynomial::solve_lagrange(Data data,int Intervalle) //double** coefs_poly,config configuration,double** M,double** Intervale, int& nb_intervale)
{
    cout << endl;

    int N = data.heights.size();
    int nb_intervalle = N / Intervalle;
    vector<vector<double>> x((Intervalle), vector<double>(nb_intervalle));
    vector<vector<double>> y((Intervalle), vector<double>(nb_intervalle));
    if (Intervalle % 2 == 0) {
        for (int i = 1; i <= Intervalle; ++i) {
            for (int j = (nb_intervalle) * (i - 1); j < (nb_intervalle * i); ++j) {
                x[i - 1][j - ((i - 1) * nb_intervalle)] = data.heights[j];
                y[i - 1][j - ((i - 1) * nb_intervalle)] = data.weights[j];
            }

        }
    } else {
        cout << "pour l'instant je sais pas comment faire" << endl;
    }

    vector<double> Y_return(nb_intervalle*9*Intervalle);
    vector<double> tmpx(nb_intervalle);
    vector<double> tmpy(nb_intervalle);
    for (int i = 1; i <= Intervalle; i++) {
        for (int j = 0; j < (nb_intervalle); ++j) {
            tmpx[j] = x[i - 1][j];
            tmpy[j] = y[i - 1][j];
        }


        Lagrange lagrange;
        vector<double> x_fit(31);
        int count = 0;
        for (size_t d(0); d < nb_intervalle * 9; ++d) {
            for (int t(0); t < 10; t++) {
                x_fit[d] = (((tmpx[count + 1] - tmpx[count]) / 10) * t + tmpx[count]);
            }
            count++;
        }

        for (size_t l(1); l <= x_fit.size()*Intervalle; ++l) {
            Y_return[l] = lagrange.solve(data, x_fit[l-(l-1)*x_fit.size()*Intervalle]);
        }

    }

    return Y_return;
}

    /*Lagrange lagrange;
    vector<double>x2(31);
    vector<double>y2(31);
    for (size_t d(0); d < 31;++d)
    {
        x2[d]= (1+ 0.1*d);
    }
    for (size_t j(0); j < 30; ++j)
    {
        y2[j] = lagrange.solve(data,x2[j]);
    }*/

    /*
    int number_points = data.heights.size();

    if(degree>number_points) {
        cerr << "ERROR : For the piece-wise continious the degree of the approximating polynom has to be smaller than the number of points" << endl ;
        assert(degree< number_points);
    }



    int add = 1;
    int count=0;
    int nb_intervale_entier=0 ;
    int nb_intervale2 = 0;
    bool reste;
    int left ;

    while(add<number_points){ // finding the number of intervals and if there are some pts left and how many
        count++;
        add = add + degree-1;
    }
    if(add==number_points) {
        nb_intervale2 = count;
        nb_intervale_entier = count;
        reste = 0 ;
    } else {
        nb_intervale2 = count;
        nb_intervale_entier = count-1;
        reste = true ;
        left = number_points - (add - degree+1) ;
    }

    double direction = (data.weights[1]-data.weights[0])/(data.heights[1] - data.heights[0]) ; // definition of the first direction
    vector<vector<double>> X (degree+1, vector<double>(degree+1));
    vector<double> Y (degree+1);
    for(int k = 0;k< nb_intervale_entier;k++) {
        Intervale[k][0] = data.heights[k * (degree - 1)];
        Intervale[k][1] = data.heights[k * (degree - 1) + (degree - 1)];
        for (int i = 0; i < degree; i++) {
            for (int j = 0; j < degree + 1; j++) {
                X[i][j] = pow(data.heights[i + k * (degree - 1)], j);
            }
            Y[i] = data.weights[i + k * (degree - 1)];
        }
        Y[degree] = direction;
        X[degree][0] = 0;

        for (int j = 1; j < degree + 1; j++) {
            X[degree][j] = j * pow(data.heights[k * (degree - 1)], j - 1);
        }

        GaussianElimination(X, Y, degree + 1);
        Solve(X, Y, degree + 1, coefs_poly[k]);

        direction = 0;
        for (int j = 1; j < degree + 1; j++) {
            direction += coefs_poly[k][j] * j *
                         pow(data.heights[(k + 1) * (degree - 1)], j - 1); //final derivative of the interval
        }
        cout << "   |    " << k << endl;

        int b = left;
        if (reste) {
            int deg_last_poly = b + 1;
            Intervale[k][0] = Intervale[k - 1][1];
            Intervale[k][1] = data.heights[k * (degree - 1) + b];

            vector<vector<double>> Xr(deg_last_poly + 1, vector<double>(deg_last_poly + 1));
            vector<double> Yr(deg_last_poly + 1);
            for (int i = 0; i < deg_last_poly; i++) {
                for (int j = 0; j < deg_last_poly + 1; j++) {
                    Xr[i][j] = pow(data.heights[i + k * (degree - 1)], j);
                }
                Yr[i] = data.weights[i + k * (degree - 1)];
            }
            Yr[b + 1] = direction;
            Xr[b + 1][0] = 0;

            direction = 0;
            for (int j = 1; j < deg_last_poly + 1; j++) {
                Xr[deg_last_poly][j] = j * pow(data.heights[(k - 1) * (degree - 1) + b + 1], j - 1);
            }

            GaussianElimination(Xr, Yr, deg_last_poly + 1);
            Solve(Xr, Yr, deg_last_poly + 1, coefs_poly[k]);

            double temp[degree + 1];
            for (int t = 0; t < degree + 1; t++) { // copy of the last coefs
                temp[t] = coefs_poly[k][t];
            }

            for (int e = 0;
                 e < degree + 1; e++) { // we put them at the right place and also put some zeros at the highest degree
                if (e > deg_last_poly) {
                    coefs_poly[k][e] = 0.0;
                } else {
                    coefs_poly[k][e] = temp[e];
                }
            }
        }
    }*/
