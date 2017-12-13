/**
 * \class Test
 *
 * \ingroup PackageName
 * (Note, this needs exactly one \defgroup somewhere)
 *
 * \brief This is the class that is testing all the other classes that are performing our data approximation methods
 *
 * \note Optional part of the project
 *
 * \author (last to touch it) $Author: DC & NL$
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2017.12.11 $
 *
 * Contact: david.cleres@epfl.ch & nicolas.lesimple@epfl.ch
 *
 */

#ifndef PCSC2017_GROUP5_TEST_H
#define PCSC2017_GROUP5_TEST_H


#include "FFTreal.h"
#include "Polynomial.h"
#include "PieceWiseContinuePolynomial.h"
#include "Lagrange.h"

class Test {
public:
    /** \brief Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function
     */
    Test();

    /**\brief Computes Fraction of accurately predicted values while comparing the values between predicted output and
     * real value
     * \return Fraction of accurately predicted
     */
    double testFourier();

    /**\brief Computes Fraction of accurately predicted values while comparing the values between predicted output and
     * real value for the Fourrier approximation
     * \return Fraction of accurately predicted
     */
    double testLeastSquares();

    /**\brief Computes Fraction of accurately predicted values while comparing the values between predicted output and
     * real value for the Lagrange interpolation
     * \return Fraction of accurately predicted
     */
    double testLagrange();

    /**\brief Computes Fraction of accurately predicted values while comparing the values between predicted output and
     * real value for the PieceWise Lagrange approximation
     * \return Fraction of accurately predicted
     */
    double testLagrangePiecewise();

    /**\brief Computes Fraction of accurately predicted values while comparing the values between predicted output and
     * real value PieceWise Least Square approximation
     * \return Fraction of accurately predicted
     */
    double testLeastSquaresPieceWise();

    /**\brief returns a boolean values about if 2 given numbers are equal taking in account a certain margin
     * \param double number 1 to compare
     * \param double number 2 to compare with double number 2
     * \return return true if the numbers are in the wrigth interval
     */
    bool CompareDoubles2 (double const& A, double const& B) const;

private:
    Data mDataToApproximate;
    Data mApproxData;
    Data mRealData;
    size_t mDegree = 50;
};

#endif //PCSC2017_GROUP5_TEST_H
