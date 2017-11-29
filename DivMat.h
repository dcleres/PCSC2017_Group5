//
// Created by pcsc on 11/28/17.
//
/**
 * \file DivMat.h
 * \brief This is redefinition of the operator * for 2 matrices
 * \class Class is DivMat
 * This is how you could multiply 2 matrices
 */

#ifndef PCSC2017_GROUP5_DIVMAT_H
#define PCSC2017_GROUP5_DIVMAT_H


#include <iostream>
#include <vector>

using namespace std;

// Définition d'un type synonyme (alias)

/* remarquez que par rapport à la version C++98         *
 * on a le droit d'écrire:  vector < vector<double>>    *
 * au lieu de vector < vector<double> > (plus besoin de *
 * séparer les deux symboles > par un espace )          */
typedef vector <vector<double>> Matrice;


class DivMat {
private:
    Matrice mMatrix_1;
    Matrice mMatrix_2;
public:
    void  affiche_matrice(const Matrice& M);
    Matrice  division(const Matrice& M1, const Matrice& M2);
    DivMat(Matrice const& mat1, Matrice const& mat2);
    Matrice lire_matrice();
};






#endif //PCSC2017_GROUP5_DIVMAT_H
