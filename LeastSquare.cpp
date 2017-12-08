#include <cmath>
#include "LeastSquare.h"
#include "Polynomial.h"

using namespace std;

// Approximation of the given points using the Least-Square algorithm
vector<double> LeastSquare::solve(Data data,int degree)
{

    int number_point = data.heights.size() ;

    vector<double> q(degree+1);
    vector<double> w(2*degree+1);
    vector<vector<double>>phi(degree+1,vector<double>(number_point));
    vector<vector<double>>A(degree+1,vector<double>(degree+1));


    for(int i=0;i<number_point;i++) {
        for(int j=0;j<degree+1;j++) {
            phi[j][i] = pow(data.heights[i],j) ; //on remplit le tableau phi dans lequel  chaque lign correspond à un degré. Dans chaque ligne on met chaque x correspondant au degré de la ligne
            q[j] += phi[j][i]*data.weights[i] ; //on additionne tout les x de chaque ligne. It's the sum of all the function for each degree : sum(xi²) then sum(xi³) abd so on.
            }
    }

    for(int k=0;k<(2*degree)+1;k++) {
        w[k]=0;
        for(int l=0;l<number_point;l++) {
            w[k] = w[k]+ pow(data.heights[l],k) ; //on remplit w[k] en mettant au degré correspondant a la ligne tout les x et on les sommes. On va jusqu'au degré 2*degree+1. It's the sum extended to big degree.
            //We fill w[k] with the sum of xi at each degree
        }
    }

    for(int r=0;r<degree+1;r++) {
        for(int z=0;z<degree+1;z++) {
            A[r][z] = w[r+z]; //on remplit une matrice A avec les valeur de w[r+z] ce qui crée les polynomes
        }
    }

    Polynomial leastsquare;
    A=leastsquare.GaussianElimination(A,q,degree+1) ; //on fait appel a la methode d'elimination gaussienne
    return leastsquare.Solve(A,q,degree+1,data.heights); //on resout ce système avec la méthode Solve implémenté dans AbstractNumericalApproximation

}


/*

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
*/
/*vector<double> LeastSquare::mldivide(){


    int linreg(int n, const double x[], const double y[], double* m, double* b, double* r){
        double   sumx = 0.0;                         /* sum of x     */
//  double      sumx2 = 0.0;                     /* sum of x**2  */
// double      sumxy = 0.0;                     /* sum of x * y */
//double     sumy = 0.0;                      /* sum of y     */
// double     sumy2 = 0.0;                     /* sum of y**2  */

/*   for (int i=0;i<n;i++){
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
//      sqrt((sumx2 - sqrt(sumx)/n) *
//             (sumy2 - sqrt(sumy)/n));
// }

//    return 0;
//}