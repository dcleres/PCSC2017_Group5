#include "readFile.h"
#include "Polynomial.h"
#include "PieceWise_NonContinue_Polynomial.h"


/// Piece-wise polynomial approximation with a non-continious derivative

void PieceWise_NonContinue_Polynomial::solve(Data data, int degree, vector<vector<double>> Intervale, int nb_intervale, vector<vector<double>>T){//double ** T,config configuration,double** M,double** Intervale, int& nb_intervale) {
  /*  int number_points = data.heights.size();
    Polynomial Polynomial;
    vector<vector<double>> M2 (number_points,vector<double>(number_points));

    int nb_boucle_entiere = 0;
    int add = 1;
    int count = 0;
    int left = 0;
    while (add < number_points){ // finding the number of intervals
        count++;
        add = add + degree;
    }

    if (add == number_points) {
        nb_intervale = count;
        nb_boucle_entiere = count;
    } else {
        nb_boucle_entiere = count - 1;
        nb_intervale = count;
        left = number_points - (add - degree);
    }

    for (int k = 0; k < nb_boucle_entiere; k++) {
        Intervale[k][0] = data.heights[k * degree];
        Intervale[k][1] = data.weights[k * degree + degree];

        int index_x = 0;
        for (int i = k * degree; i < (degree + 1) + k * degree; i++) {
            M2[index_x][0] = data.heights[i];
            M2[index_x][1] = data.weights[i];
            index_x++;
        }
        int Npts2 = degree + 1;
        Polynomial.solve(M2, T[k]);

        if (left != 0) {
            Intervale[k][0] = data.heights[k * degree];
            Intervale[k][1] = data.heights[k * degree + left];

            int index_x = 0;
            for (int i = k * degree; i < (left + 1) + k * degree; i++) {
                M2[index_x][0] = data.heights[i];
                M2[index_x][1]=data.weights[i];
                index_x++;
            }
            int Npts2 = left + 1;
            Polynomial.solve(T[k], M2, Npts2);

            double temp[degree + 1]; // copy of the coefs
            for (int t = 0; t < degree + 1; t++) {
                temp[t] = T[k][t];
            }

            for (int e = 0; e < degree + 1; e++) // put zeros at the highest degree
            {
                if (e > Npts2 - 1) {
                    T[k][e] = 0.0;
                } else {
                    T[k][e] = temp[e];
                }
            }
        }
    }*/
}