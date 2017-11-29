//
// Created by pcsc on 11/28/17.
//


#include <cmath>
#include "LeastSquare.h"
#include "MultMat.h"
#include "MultMat.h"

using namespace std;

vector<double> LeastSquare::approximationFunction(Data const& data,unsigned int degre){

    Matrice B(data.heights.size(), vector<double> (data.weights.size()));
    Matrice BT(data.weights.size(), vector<double> (data.heights.size()));
    Matrice weight((degre + 1),vector<double> (1));
    for (int i=0; i<data.heights.size();++i) {
        for (int j = 0; j < degre; ++j) {
            B[i][j] = pow(data.heights[i], j);
            BT[j][i]=B[i][j];
        }
    }
    MultMat multmat;
    Matrice a = multmat.multiplication(BT,B);
    Matrice b = multmat.mutiplication(BT,)


    return weight;
};

vector<double> LeastSquare::mldivide(){


    int linreg(int n, const double x[], const double y[], double* m, double* b, double* r){
        double   sumx = 0.0;                         /* sum of x     */
        double      sumx2 = 0.0;                     /* sum of x**2  */
        double      sumxy = 0.0;                     /* sum of x * y */
        double     sumy = 0.0;                      /* sum of y     */
        double     sumy2 = 0.0;                     /* sum of y**2  */

        for (int i=0;i<n;i++){
            sumx  += x[i];
            sumx2 += sqrt(x[i]);
            sumxy += x[i] * y[i];
            sumy  += y[i];
            sumy2 += sqrt(y[i]);
        }

        double denom = (n * sumx2 - sqrt(sumx));
        if (denom == 0) {
            // singular matrix. can't solve the problem.
            *m = 0;
            *b = 0;
            if (r) *r = 0;
            return 1;
        }

        *m = (n * sumxy  -  sumx * sumy) / denom;
        *b = (sumy * sumx2  -  sumx * sumxy) / denom;
        if (r!=NULL) {
            *r = (sumxy - sumx * sumy / n) /    /* compute correlation coeff */
                 sqrt((sumx2 - sqrt(sumx)/n) *
                      (sumy2 - sqrt(sumy)/n));
        }

        return 0;
    }