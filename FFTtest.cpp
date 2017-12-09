//
// Created by David Cleres on 29.11.17.
//
/*
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#include "FFT.h"

using std::complex;
using std::cout;
using std::endl;
using std::vector;


// Private function prototypes
static void testFft(int n);
static void testConvolution(int n);
static vector<complex<double> > naiveDft(const vector<complex<double> > &input, bool inverse);
static vector<complex<double> > naiveConvolve(const vector<complex<double> > &xvec, const vector<complex<double> > &yvec);
static double log10RmsErr(const vector<complex<double> > &xvec, const vector<complex<double> > &yvec);
static vector<complex<double> > randomComplexes(int n);

// Mutable global variable
static double maxLogError = -INFINITY;

// Random number generation
std::default_random_engine randGen((std::random_device())());
*/

/*---- Main and test functions ----*/
/*
int mainTest() {
    // Test power-of-2 size FFTs
    for (int i = 0; i <= 12; i++)
        testFft(1 << i);

    // Test small size FFTs
    for (int i = 0; i < 30; i++)
        testFft(i);

    // Test diverse size FFTs
    for (int i = 0, prev = 0; i <= 100; i++) {
        int n = static_cast<int>(std::lround(std::pow(1500.0, i / 100.0)));
        if (n > prev) {
            testFft(n);
            prev = n;
        }
    }

    // Test power-of-2 size convolutions
    for (int i = 0; i <= 12; i++)
        testConvolution(1 << i);

    // Test diverse size convolutions
    for (int i = 0, prev = 0; i <= 100; i++) {
        int n = static_cast<int>(std::lround(std::pow(1500.0, i / 100.0)));
        if (n > prev) {
            testConvolution(n);
            prev = n;
        }
    }

    cout << endl;
    cout << "Max log err = " << std::setprecision(3) << maxLogError << endl;
    cout << "Test " << (maxLogError < -10 ? "passed" : "failed") << endl;
    return EXIT_SUCCESS;
}


static void testFft(int n) {
    const vector<complex<double> > input = randomComplexes(n);
    const vector<complex<double> > refout = naiveDft(input, false);
    vector<complex<double> > actualout = input;
    FFT fft;
    fft.transform(actualout);
    cout << "fftsize=" << std::setw(4) << std::setfill(' ') << n << "  "
         << "logerr=" << std::setw(5) << std::setprecision(3) << std::setiosflags(std::ios::showpoint)
         << log10RmsErr(refout, actualout) << endl;
}


static void testConvolution(int n) {
    const vector<complex<double> > input0 = randomComplexes(n);
    const vector<complex<double> > input1 = randomComplexes(n);
    const vector<complex<double> > refout = naiveConvolve(input0, input1);
    vector<complex<double> > actualout(n);
    FFT fft;
    fft.convolve(input0, input1, actualout);
    cout << "convsize=" << std::setw(4) << std::setfill(' ') << n << "  "
         << "logerr=" << std::setw(5) << std::setprecision(3) << std::setiosflags(std::ios::showpoint)
         << log10RmsErr(refout, actualout) << endl;
}
*/

/*---- Naive reference computation functions ----*/
/*
static vector<complex<double> > naiveDft(const vector<complex<double> > &input, bool inverse) {
    int n = static_cast<int>(input.size());
    vector<complex<double> > output;
    double coef = (inverse ? 2 : -2) * M_PI / n;
    for (int k = 0; k < n; k++) {  // For each output element
        complex<double> sum(0);
        for (int t = 0; t < n; t++) {  // For each input element
            double angle = coef * (static_cast<long long>(t) * k % n);
            sum += input[t] * std::exp(complex<double>(0, angle));
        }
        output.push_back(sum);
    }
    return output;
}


static vector<complex<double> > naiveConvolve(
        const vector<complex<double> > &xvec, const vector<complex<double> > &yvec) {
    int n = static_cast<int>(xvec.size());
    vector<complex<double> > outvec(n);  // All zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = (i + j) % n;
            outvec[k] += xvec[i] * yvec[j];
        }
    }
    return outvec;
}
*/

/*---- Utility functions ----*/
/*
static double log10RmsErr(const vector<complex<double> > &xvec, const vector<complex<double> > &yvec) {
    int n = static_cast<int>(xvec.size());
    double err = std::pow(10, -99 * 2);
    for (int i = 0; i < n; i++)
        err += std::norm(xvec.at(i) - yvec.at(i));
    err /= n > 0 ? n : 1;
    err = std::sqrt(err);  // Now this is a root mean square (RMS) error
    err = std::log10(err);
    maxLogError = std::max(err, maxLogError);
    return err;
}


static vector<complex<double> > randomComplexes(int n) {
    std::uniform_real_distribution<double> valueDist(-1.0, 1.0);
    vector<complex<double> > result;
    for (int i = 0; i < n; i++)
        result.push_back(complex<double>(valueDist(randGen), valueDist(randGen)));
    return result;
}*/