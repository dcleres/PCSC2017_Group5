//
// Created by nicol on 28.11.2017.
//

#include <iostream>
#include <cmath>
#include "AbstractNumericalApproximation.h"

using namespace std;

void AbstractNumericalApproximation::printWeight (vector<double> const& weight){
    cout << "The weight found by the approximation function are :"<< endl;
    for (size_t i(0); i< weight.size(); i++) {
        cout << weight[i] << " | ";
    }
    cout << endl;
}



AbstractNumericalApproximation::~AbstractNumericalApproximation(){}

/// Swap lines to always have the biggest value at the top, less numerical errors
vector<vector<double>> AbstractNumericalApproximation::SwapA(vector<vector<double>>& A, const int k,int number_point) {

    //A is the xi matrix put it with degree and b is the yi vector
    double max = fabs(A[k][k]); //return the absolute value
    int Imax = k;
    for (int i = k+1; i<number_point; ++i) {
        double val = fabs(A[i][k]);
        if (val > max) {
            max = val;
            Imax = i;
        }
    }
    vector<double>temp1 = A[k];// Echange les lignes de la matrice
    A[k] = A[Imax];
    A[Imax] = temp1;

    return A;

}

/// Swap lines to always have the biggest value at the top, less numerical errors
vector<double> AbstractNumericalApproximation::Swapb(vector<vector<double>>& A, vector<double>& b, const int k,int number_point) {

    //A is the xi matrix put it with degree and b is the yi vector
    double max = fabs(A[k][k]); //return the absolute value
    int Imax = k;
    for (int i = k+1; i<number_point; ++i) {
        double val = fabs(A[i][k]);
        if (val > max) {
            max = val;
            Imax = i;
        }
    }
    vector<double>temp1 = A[k];// Echange les lignes de la matrice
    A[k] = A[Imax];
    A[Imax] = temp1;
    double temp2 = b[k]; // Echange les valeurs du vecteur
    b[k] = b[Imax];
    b[Imax] = temp2;
    return b;
}

/// Do the gaussian elimination to solve the system Ax = b
vector<vector<double>> AbstractNumericalApproximation::GaussianElimination(vector<vector<double>> B, vector<double> b,int n)
{
    /*for (int k = 0; k < number_point; ++k) {
        A=SwapA(A, k, number_point); // Swap lines to always have the biggest value at the top, less numerical errors
        b=Swapb(A, b, k, number_point);
        for (int i = k+1; i < number_point; ++i) {
            double r = A[i][k] / A[k][k];
            for (int j = k+1; j < number_point; ++j) {
                A[i][j] -= r * A[k][j];
            }
            b[i] -= r * b[k];
        }
        for (int i = k+1; i <number_point; ++i) {
            A[i][k] = 0;
        }
    }
    return A;*/

}



/// Solve the simplified system made by the gaussian elimination
vector<double> AbstractNumericalApproximation::Solve(vector<vector<double>> A, vector<double>b, int t, vector<double> x)
{
    for (int i = t-1; i>= 0; --i) {
        x[i] = b[i];
        cout << x[i] << endl;
        for (int j = i+1; j<t; ++j) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
        cout <<x[i]<<endl;
    }
    return x;
}
