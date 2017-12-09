/**
 * \class Point
 *
 * \ingroup PackageName
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief This is the function to call to perform the FFT of a given set of values but also to implement the data
 * approximation by computing the fourier series coefficients.
 *
 * \file Point.h
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

#ifndef PCSC2017_GROUP5_POINT_H
#define PCSC2017_GROUP5_POINT_H

#include <vector>
using namespace std ;

///@class
class Point {

public:

    /** \brief Constructor
     * \param taille is the size of the vector
     */
    explicit Point(size_t const& taille);

    /** \brief Constructor
    * \param x is a vector with the values of approximate (x-axis)
    * \param y is a vector with the values of approximate (y-axis)
    */
    Point(vector<double> const& x,vector<double> const& y);

    /** \brief returns the value of mx
    */
    vector<double> get_x() const;

    /** \brief returns the value of my
    */
    vector<double> get_y() const;

    /** \brief setter for x
    * \param index
    * \param value
    */
    void set_x(size_t const& index,double const& value);

    /** \brief setter for y
  * \param index
  * \param value
  */
    void set_y(size_t const& index,double const& value);

private:
    vector<double> mx;
    vector<double> my;
};

#endif //PCSC2017_GROUP5_POINT_H
