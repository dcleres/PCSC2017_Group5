//
// Created by pcsc on 12/11/17.
//


#include "Test.h"
#include "gnuplot_i.hpp"



double Test::testFourier() {

    FFTreal fft;
    size_t nbK(mApproxData.weights.size()); //number of ak and bk to compute
    vector<double> an(nbK, 0.0);
    vector<double> bn(nbK, 0.0);

    fft.transformCoefs(mApproxData.weights, an, bn, 2);
    mDataToApproximate.heights = fft.transformApproximation(an, bn, 2, mDataToApproximate.weights);

    size_t counter(0);

    for (size_t i(0); i < mDataToApproximate.weights.size(); i++) {
        if (mDataToApproximate.heights[i] == mRealData.weights[i]) {
            counter++;
        }
        cout << "input" << mDataToApproximate.weights[i] << " " << mRealData.heights[i] << endl;
        cout << "output" << mDataToApproximate.heights[i] << " " << mRealData.weights[i] << endl;
    }

    //on doit plotter data_copy où on a changé les valeurs des x associée aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(mDataToApproximate.weights, mDataToApproximate.heights, "Approximation");
    sleep(2);
    g1.plot_xy(mRealData.heights, mRealData.weights, "Real Data");
    sleep(20);

    cout << counter << " " << mDataToApproximate.weights.size();
    return counter / mDataToApproximate.weights.size();
}

Test::Test()
{
    //TRAINING VALUES
    vector<double> xs;
    vector<double> ys;
    Data data = {xs, ys};

    mApproxData = data;
    mRealData = data;
    mDataToApproximate = data;
    //INIT THE VECTORS
    string filenameApprox("/home/pcsc/Desktop/PCSC2017_Group5/data/data.dat");
    string filenameReal("/home/pcsc/Desktop/PCSC2017_Group5/data/realDataSin.dat");
    string filenameTest("/home/pcsc/Desktop/PCSC2017_Group5/data/dataInterpolationX.dat");
    ReadFile readFileApprox(filenameApprox);
    ReadFile readFileReal(filenameReal);
    ReadFile readFileTest(filenameTest);
    readFileApprox.loadFromFile(mApproxData);           //Data to train the model
    readFileReal.loadFromFile(mRealData);               //Actual Data
    readFileTest.loadFromFileTest(mDataToApproximate);  //data to interpolate

    //PieceWiseContinuePolynomial piecewise(mRealData);
    //mPiecewise = piecewise;
}

double Test::testLeastSquares() {

    Polynomial poly;
    vector<double> a(poly.solve(mApproxData.heights, mApproxData.weights,
                                mDegree));                  // we found the coefficient by the least square method minimizibg the loss. a is a vector with the coefficients searched.
    vector<double> y(10 *
                     mApproxData.heights.size());                                            //y will have the polynomial approximation thanks to the coefficients we found

    cout << "The interpolation polynome is : ";
    for (size_t i(0); i < (mDegree + 1); i++) {
        cout << " + (" << a[i] << ")" << "x^" << i;
    }
    cout << endl;
    vector<double> x(10 *
                     mApproxData.heights.size());                                            //We choose to put 10 points of approximation between each point we have in the data set
    for (size_t count(0); count < (mApproxData.heights.size() -
                                   1); ++count) {                          //The for loop help us to augment the number of point on which we will apply our approximation
        for (size_t d(0); d < 10; ++d) {
            x[count * 10 + d] = (((mApproxData.heights[count] - mApproxData.heights[count + 1]) / 10) * d) +
                                mApproxData.heights[count];
        }
    }
    for (size_t j(0); j < 10 * mApproxData.heights.size(); ++j) {
        for (size_t i(0); i < (mDegree + 1); i++) {
            y[j] += pow(x[j], i) *
                    a[i];                                                     //we apply the least square coefficient to find the approimation
        }
    }

    //GENERATE THE CONTROL VALUES
    vector<double> controlY;
    for (auto const& element : x)
    {
        controlY.push_back(sin(element));
    }

    ///Plot///
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x, y, "Approximation");
    sleep(2);
    g1.plot_xy(x, controlY, "Default points");
    sleep(20);


    size_t counter(0);

    for (size_t i(0); i < mRealData.weights.size(); i++) {
        if (CompareDoubles2(y[i], mRealData.weights[i])) {
            counter++;
        }
        cout << "input" << x[i] << " " << x[i] << endl;
        cout << "output" << y[i] << " " << controlY[i] << endl;
    }

    cout << counter << " " << x.size();
    return counter / x.size();
}

bool Test::CompareDoubles2 (double const& A, double const& B) const
{
    double const EPSILON = 0.5;
    double diff (A - B);
    return (diff < EPSILON) && (-diff < EPSILON);
}

double Test::testLagrange() {
    return 0;
}

double Test::testLeastSquaresPieceWise() {
    return 0;
}

double Test::testLagrangePiecewise() {
    return 0;
}
