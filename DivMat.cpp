//
// Created by pcsc on 11/28/17.
//
#include <vector>
#include "MultMat.h"

using namespace std;

// ----------------------------------------------------------------------
Matrice MultMat::lire_matrice()
{
    cout << "Saisie d'une matrice :" << endl;

    size_t lignes;
    do {
        cout << "  Nombre de lignes : " << flush;
        cin >> lignes;
    } while (lignes < 1);

    size_t colonnes;
    do {
        cout << "  Nombre de colonnes : " << flush;
        cin >> colonnes;
    } while (colonnes < 1);

    Matrice M(lignes, vector<double>(colonnes));

    for (size_t i(0); i < lignes; ++i)
        for (size_t j(0); j < colonnes; ++j) {
            cout << "  M[" << i+1 << "," << j+1 << "]=" << flush;
            cin >> M[i][j];
        }

    return M;
}

// ----------------------------------------------------------------------
Matrice  MultMat::multiplication(const Matrice& M1,
                                 const Matrice& M2)
{
    Matrice prod(M1.size(), vector<double>(M2[0].size()));

    for (size_t i(0); i < M1.size(); ++i)
        for (size_t j(0); j < M2[0].size(); ++j) {
            prod[i][j] = 0.0;
            for (size_t k(0); k < M2.size(); k++)
                prod[i][j] += M1[i][k] * M2[k][j];
        }

    return prod;
}
/* Amélioration possible : stocker le résultats des appels à la fonction   *
 * size dans des variables locales (pour éviter de ré-invoquer la fonction *
 * plusieurs fois)*/
// ----------------------------------------------------------------------
void  MultMat::affiche_matrice(const Matrice& M)
{
    // On aurait aussi pu utiliser auto dans les boucles
    // des autres fonctions
    for (auto ligne : M) {
        for (auto element : ligne) {
            cout << element << " ";
        }
        cout << endl;
    }
}

MultMat::MultMat(Matrice const& mat1, Matrice const& mat2)
        : mMatrix_1(mat1)
        , mMatrix_2(mat2)
{}