/**
 * \file FFT.h
 * \brief This is the class we will use to implement all the approximations functions for periodic functions
 * This is a pure virtual class
 */

#ifndef PCSC2017_GROUP5_FFT_H
#define PCSC2017_GROUP5_FFT_H

#pragma once

#include <complex>
#include <vector>

#include "AbstractNumericalApproximation.h"

class FFT{
public:
    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function.
     */
    void transform(std::vector<std::complex<double> > &vec);

    /*
     * Computes the inverse discrete Fourier transform (IDFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function. This transform does not perform scaling, so the inverse is not a true inverse.
     */
    void inverseTransform(std::vector<std::complex<double> > &vec);

    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
     */
    void transformRadix2(std::vector<std::complex<double> > &vec);

    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This requires the convolution function, which in turn requires the radix-2 FFT function.
     * Uses Bluestein's chirp z-transform algorithm.
     */
    void transformBluestein(std::vector<std::complex<double> > &vec);

    /*
     * Computes the circular convolution of the given complex vectors. Each vector's length must be the same.
     */
    void convolve(
            const std::vector<std::complex<double> > &vecx,
            const std::vector<std::complex<double> > &vecy,
            std::vector<std::complex<double> > &vecout);

private:

};

#endif //PCSC2017_GROUP5_FFT_H
