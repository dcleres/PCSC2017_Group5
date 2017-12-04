//
// Created by pcsc on 12/2/17.
//

#include <assert.h>
#include <cmath>
#include <iostream>
#include "readFile.h"
#include "Polynomial.h"


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
            A[i][j] = pow(data.heights[i],j) ; //We fill the matrix A with each xi at each degree and each xi^j correspond to a case in A
        }
    }

    GaussianElimination(A,data.weights,number_point) ;
    Solve(A,data.weights,number_point,data.heights);

}

/// Approximation of some points using a single polynome (used for Piece-Wise No-Continious)
void Polynomial::solve(Data data)
{
    int number_point=data.heights.size();
    vector<double>b(number_point);
    vector<vector<double>>A(number_point,vector<double>(number_point));

    for(int i=0;i<number_point;i++) {
        for(int j=0;j<number_point;j++) {
            A[i][j] = pow(data.heights[i],j) ;  //We fill the matrix A with each xi at each degree and each xi^j correspond to a case in A. A is a square matrix
        }
    }

    GaussianElimination(A,data.weights,number_point) ;
    Solve(A,data.weights,number_point,data.heights); //Solve is in the file AbstractNumericalApproximation
}