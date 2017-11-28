//
// Created by nicol on 28.11.2017.
//

using namespace std;
#include "AbstractNumericalApproximation.h"

void AbstratcNumericalApproximation :: printWeight (vector<double> weight){

    cerr << "The weight found by the approximation function are :"<< endl;
    for (int i=0; i< weight.size(); i++) {
        std::cerr << weight[i] << " | ";
    }
    cerr <<endl;

}