//
// Created by pcsc on 11/29/17.
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

using namespace std ;

Lagrange::~lagrange() {}

/// Polynomial approximation by the Lagrange algorithm
vector<vector<double>> Lagrange::solve_lagrange(Data data,int degre)
{
    int number_pts = data.heights.size();

    vector<double> x(number_pts); //abscisse
    vector<double> y(number_pts); //ordonné
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
                    L[m][n]*= w[m]-x[i];
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
            L[m][n]=L[m][n]*(y[n]/b[n]);
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

    return point;
}

double Lagrange :: getmax(vector<double>x) {
    double max= 0;
    for(int i=0;i<x.size();i++){
        if (x[i]>max) {
            max= x[i];
        }
    }
    return max;
}

double Lagrange :: getmin(vector<double>x) {
    double min= 0;
    for(int i=0;i<x.size();i++) {
        if (x[i]<min) {
            min= x[i];
        }
    }
    return min;
}

