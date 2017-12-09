/**
 * \class Graph
 *
 * \ingroup PackageName
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief This is class that enables us to plot the approximated data.
 *
 *
 * \note Mandatory part of the project
 *
 * \author (last to touch it) $Author: DC & NL$
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2017.12.09 $
 *
 * Contact: david.cleres@epfl.ch & nicolas.lesimple@epfl.ch
 *
 */

#ifndef PCSC2017_GROUP5_GRAPH_H
#define PCSC2017_GROUP5_GRAPH_H

#include "readFile.h"
using namespace std;

class Graph {
public:
    /** \brief Constructor of the class graph
     * \param data is a structure that contains the information about the X and Y axis
     */
    explicit Graph(Data const& data);

    /** \brief plots the graph for the least square regression
     * \param degree is a positive integer that represents the degree of the fitted polynome
     */
    void make_graph_least_square(size_t const& degree) const;

    /** \brief plots the graph for the lagrange polynoma regression
     */
    void make_graph_lagrange() const;

    /** \brief Plots the graph for the least square regression
     * \param degree is a positive integer that represents the degree of the fitted polynome
     * \param intervalle is the intervall for the the leat square method
     */
    void make_graph_piece_wise_least_squares(size_t const& degree, int const& intervalle) const;

    /** \brief Plots the graph for the lagrange regression
    * \param intervalle is the intervall for the the leat square method
    */
    void make_graph_piece_wise_lagrange(int const& intervalle);

    /** \brief Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function.
     * \param real is a vector with the values read from the data.dat file
     * \param imag is a vector with the values read from the data.dat file, if we have only real entries then you have to
     * specify a vector with the same size as real but filled with zeros.
     */
    void make_graph_FFT(Data data_original);
private:
    Data mData;
};

#endif //PCSC2017_GROUP5_GRAPH_H
