//
// Created by pcsc on 12/2/17.
//

#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include "readFile.h"
#include "Lagrange.h"


//ATTENTION: cette valeur n est valable que pour un degré 2. Comment fair epour un degré 3?
//pour un dgre N je pense qu il faut rajouter une somme, c est a dire une boucle for pour chaque yi*Li ou i va de 0 a N
//je mettrai un boucle for sur toute la fonction et j'ajouterais nos polynome mais ca me parait grave bizarre.Enfin pas sur

using namespace std ;

/// Polynomial approximation by the Lagrange algorithm
double Lagrange::solve(Data data,double xi) {

    // function to interpolate the given data points using Lagrange's formula
// xi corresponds to the new data point whose value is to be obtained
// n represents the number of known data points
    int n= data.heights.size();
    double result = 0; // Initialize result

    for (int i=0; i<n; i++)
    {
        // Compute individual terms of above formula
        double term = data.weights[i];
        for (int j=0;j<n;j++)
        {
            if (j!=i)
                term = term*(xi - data.heights[j])/double(data.heights[i] - data.heights[j]);
        }

        // Add current term to result
        result += term;
    }

    return result;


   /* int number_pts = data.heights.size();

    vector<double> w(number_pts); //X qui nous permet de tracer la courbe
    vector<double> b(number_pts); //factoriel de xi-xj


    double maxx = getmax(data.heights);
    double minx = getmin(data.heights);


    //we calculate the denominator of lagrange polynome which is Factoriel(xi-xj)
    for(int i=0;i<number_pts;i++) {
        for(int j=0;j<number_pts;j++) {
            if(i!=j) {
                b[i] *=(data.heights[i]-data.heights[j]);
            }
            if(i==j) {
                b[i]=b[i]*1;
            }
        }
    }

    double p=(maxx-minx)/0.1;
    vector<vector<double>> L(p+1, vector<double>(number_pts));
    //We calculate the numerator of the Lagrange polynome which is Factoriel(X-xi);
    for(int m=0;m<p+1;m++) {
        w[m]=minx+(m*0.1);
        for(int n=0;n<number_pts;n++) {
            L[m][n]=1;
            for(int i=0;i<number_pts ;i++) {
                if(n!=i) {
                    L[m][n]*= w[m]-data.heights[i];
                }
                if(n==i) {
                    L[m][n]=L[m][n]*1;
                }
            }
        }
    }

    //We calculate the lagrage polynome for each point m
    for(int m=0;m <p+1;m++) {
        for(int n=0;n<number_pts ;n++) {
            L[m][n]=L[m][n]*(data.weights[n]/b[n]);
        }
    }

    //We apply Lagrange polynome to some points . Thus we calculate y with the formula of Lagrange Polynome setting a range of x.
    vector<vector<double>> point(p+1, vector<double>(number_pts));
    for(int m=0;m <p+1;m++) {
        point[m][0]=w[m];
        point[m][1]=0;
        for(int n=0;n<number_pts;n++) {
            point[m][1]+= L[m][n];
        }
    }

    return point;*/
}

//method that return the max of th value in the vector given in argument
double Lagrange :: getmax(vector<double>x) {
    double max= 0;
    for(int i=0;i<x.size();i++){
        if (x[i]>max) {
            max= x[i];
        }
    }
    return max;
}

//method that return the min of th value in the vector given in argument
double Lagrange :: getmin(vector<double>x) {
    double min= 0;
    for(int i=0;i<x.size();i++) {
        if (x[i]<min) {
            min= x[i];
        }
    }
    return min;
}

/// Polynomial approximation by the Lagrange algorithm
double Lagrange::solve(vector<double> const& data_x,vector<double> const& data_y,double xi) {

    // function to interpolate the given data points using Lagrange's formula
// xi corresponds to the new data point whose value is to be obtained
// n represents the number of known data points
    int n = data_x.size();
    double result = 0; // Initialize result

    for (int i = 0; i < n; i++) {
        // Compute individual terms of above formula
        double term = data_y.[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                term = term * (xi - data_x[j]) / double(data_x[i] - data_x[j]);
        }

        // Add current term to result
        result += term;
    }

    return result;
}
