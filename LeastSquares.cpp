//
// Created by nicol on 28.11.2017.
//

#include "LeastSquares.h"
using namespace std;

vector<double> LeastSquares::approximationFunction(Data const& data){
    //We want to solve ax=b;
    vector<double> const& a(height.size);
    vector<double> const& b(weigth.size);
    vector<double> const& weight;
    //We set value of a and b
    //Then we solve the equation knowing that we are on 1D space
    for (int i=0; i<data.heigth.size() or i<data.weigth.size();++i){
        a[i]=data.heigth[i]*data.heigth[i];
        b[i]=data.heigth[i]*data.weigth[i];
        weight[i]= b[i]/a[i];
    };
    return weight;
};
