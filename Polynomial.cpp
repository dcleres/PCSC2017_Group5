#include <assert.h>
#include <cmath>
#include <iostream>
#include "readFile.h"
#include "Polynomial.h"

//
// Created by pcsc on 11/29/17.
//
Polynomial::~polynomial(){}

/// Polynomial approximation of the given points using a single polynome
void Polynomial::solve(Data data,int degree)
{
    int number_point=data.heights.size();
    vector<double>b(number_point);
    vector<vector<double>>A(number_point,vector<double>(number_point));

    if(number_point!=degree+1) {
        cerr << "ERROR: The number of points must be equal to the degree of the polynome plus 1 !!!" << endl ;
        assert(number_point==degree+1);
    }

    for(int i=0;i<number_point;i++) {
        for(int j=0;j<number_point;j++) {
            A[i][j] = pow(data.heights[i],j) ;
        }
        b[i] = data.weights[i] ;
    }

    GaussianElimination(A,b,number_point) ;
    Solve(A,b,number_point,data.heights[0]);

}



//ATTENTION JE VOIS PAS VRAIEMENT LA DIFF ENTRE LE DEUX ...

/// Approximation of some points using a single polynome (used for Piece-Wise No-Continious)
void Polynomial::solve(Data data)
{
    int number_point=data.heights.size();
    vector<double>b(number_point);
    vector<vector<double>>A(number_point,vector<double>(number_point));

    for(int i=0;i<number_point;i++) {
        for(int j=0;j<number_point;j++) {
            A[i][j] = pow(data.heights[i],j) ;
        }
        b[i] = data.weights[i] ;
    }

    GaussianElimination(A,b,number_point) ;
    Solve(A,b,number_point,data.heights);
}