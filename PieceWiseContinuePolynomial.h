/**
 * \class PieceWiseContinuePolynomial
 *
 * \ingroup PackageName
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief This is the function to call to perform the FFT of a given set of values but also to implement the data
 * approximation by computing the fourier series coefficients.
 *
 * \file PieceWiseContinuePolynomial.h
 *
 * \note Optional part of the project
 *
 * \author (last to touch it) $Author: DC & NL$
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2017.12.10 $
 *
 * Contact: david.cleres@epfl.ch & nicolas.lesimple@epfl.ch
 *
 */

#ifndef PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H
#define PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H


#include <iostream>
#include <cassert>
#include <cmath>
#include "readFile.h"

using namespace std;

///@class
class PieceWiseContinuePolynomial {

public:

    /**\brief Constructor
     * \param data is the input value from the files
     */
    explicit PieceWiseContinuePolynomial(Data const& data);

    /**\brief
     * \param degree degree of the polynome
     * \param Intervale
     * \param x_plot gives the x axis values of the plot
     */
    vector<double> solve_least_square(size_t const& degree, int const& Intervale,vector<double> const& x_plot) const;

    /**\brief solves by using lagrange
     * \param Intervalle
     * \param x_plot gives the x axis values of the plot
     */
    vector<double> solve_lagrange(int const& Intervalle, vector<double> const& x_plot) const;

    vector<double> solve_lagrange_degree(int const& Intervalle, vector<double> const& x_plot) const;

    //void create_interval(vector<vector<double>>& x,vector<vector<double>>& y,int const& Intervalle,size_t nb_intervalle);

private:
    Data mData;

};

#endif //PROJECT_PIECEWISE_CONTINUE_POLYNOMIAL_H