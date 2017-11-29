//
// Created by nicol on 28.11.2017.
//

#include <iostream>
#include "AbstractNumericalApproximation.h"

using namespace std;

void AbstractNumericalApproximation::printWeight (vector<double> const& weight){
    cout << "The weight found by the approximation function are :"<< endl;
    for (size_t i(0); i< weight.size(); i++) {
        cout << weight[i] << " | ";
    }
    cout << endl;
}