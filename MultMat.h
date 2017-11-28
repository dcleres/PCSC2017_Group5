#ifndef PCSC2017_GROUP5_MULTMAT_H
#define PCSC2017_GROUP5_MULTMAT_H

#include <iostream>
#include <vector>
using namespace std;

// Définition d'un type synonyme (alias)

/* remarquez que par rapport à la version C++98         *
 * on a le droit d'écrire:  vector < vector<double>>    *
 * au lieu de vector < vector<double> > (plus besoin de *
 * séparer les deux symboles > par un espace )          */

typedef vector < vector<double>> Matrice;

Matrice  lire_matrice();
void  affiche_matrice(const Matrice& M);
Matrice  multiplication(const Matrice& M1, const Matrice& M2);

// ----------------------------------------------------------------------
int main()
{
    Matrice M1(lire_matrice()), M2(lire_matrice());

    if (M1[0].size() != M2.size())
        cout << "Multiplication de matrices impossible !" << endl;
    else {
        cout << "Résultat :" << endl;
        affiche_matrice(multiplication(M1, M2));
    }

    return 0;
}

// ----------------------------------------------------------------------
Matrice  lire_matrice()
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
Matrice  multiplication(const Matrice& M1,
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
void  affiche_matrice(const Matrice& M)
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
#endif //PCSC2017_GROUP5_MULTMAT_H
