//
// Created by David Cleres on 29.11.17.
//

#ifndef PCSC2017_GROUP5_FFTREAL_H
#define PCSC2017_GROUP5_FFTREAL_H

#pragma once

#include <vector>


class FFTreal {

public:
    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function.
     */
    void transform(std::vector<double> &real, std::vector<double> &imag);


    /*
     * Computes the inverse discrete Fourier transform (IDFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This is a wrapper function. This transform does not perform scaling, so the inverse is not a true inverse.
     */
    void inverseTransform(std::vector<double> &real, std::vector<double> &imag);


    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector's length must be a power of 2. Uses the Cooley-Tukey decimation-in-time radix-2 algorithm.
     */
    void transformRadix2(std::vector<double> &real, std::vector<double> &imag);


    /*
     * Computes the discrete Fourier transform (DFT) of the given complex vector, storing the result back into the vector.
     * The vector can have any length. This requires the convolution function, which in turn requires the radix-2 FFT function.
     * Uses Bluestein's chirp z-transform algorithm.
     */
    void transformBluestein(std::vector<double> &real, std::vector<double> &imag);


    /*
     * Computes the circular convolution of the given real vectors. Each vector's length must be the same.
     */
    void convolve(const std::vector<double> &x, const std::vector<double> &y, std::vector<double> &out);


    /*
     * Computes the circular convolution of the given complex vectors. Each vector's length must be the same.
     */
    void convolve(
            const std::vector<double> &xreal, const std::vector<double> &ximag,
            const std::vector<double> &yreal, const std::vector<double> &yimag,
            std::vector<double> &outreal, std::vector<double> &outimag);

private:

};


#endif //PCSC2017_GROUP5_FFTREAL_H