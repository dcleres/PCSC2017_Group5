//
// Created by pcsc on 11/30/17.
//


#include <iostream>
#include <cassert>
#include <cmath>
#include "readFile.h"
#include "PieceWise_Continue_Polynomial.h"

using namespace std ;


/// Piece-wise polynomial approximation with continuous derivative using polynoms
void PieceWise_Continue_Polynomial::solve(Data data, int degree,vector<vector<double>> Intervale, vector<vector<double>> coefs_poly)//double** coefs_poly,config configuration,double** M,double** Intervale, int& nb_intervale)
{
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
    }
}