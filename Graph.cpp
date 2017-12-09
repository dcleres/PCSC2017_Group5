#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Polynomial.h"
#include "gnuplot_i.hpp"
#include "PieceWiseContinuePolynomial.h"
#include "Lagrange.h"
#include "FFTreal.h"

Graph :: Graph(Data const& data)
: mData(data)
{}

////////////////LeastSquare//////////////////////////////
void Graph :: make_graph_least_square(size_t const& degree) const
{
    Polynomial poly;
    vector <double> a (poly.solve(mData.heights,mData.weights, degree));                  // we found the coefficient by the least square method minimizibg the loss. a is a vector with the coefficients searched.
    vector<double>y(10*mData.heights.size());                                            //y will have the polynomial approximation thanks to the coefficients we found

    cout<< "The interpolation polynome is : ";
    for (size_t i(0); i < (degree+1);i++){
        cout<<" + ("<<a[i]<<")"<<"x^"<<i;
    }
    cout<<endl;
    vector<double>x(10*mData.heights.size());                                            //We choose to put 10 points of approximation between each point we have in the data set
    for(size_t count(0); count < (mData.heights.size()-1); ++count)
    {                          //The for loop help us to augment the number of point on which we will apply our approximation
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((mData.heights[count]-mData.heights[count+1])/ 10) * d) + mData.heights[count];
        }
    }
    for (size_t j(0); j<10*mData.heights.size(); ++j)
    {
        for (size_t i(0); i < (degree+1); i++)
        {
            y[j]+=pow(x[j],i)*a[i];                                                     //we apply the least square coefficient to find the approimation
        }
    }
    ///Plot///
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(mData.heights,mData.weights,"Default points");
    sleep(20);
}


/////////////////////////Lagrange/////////////////////////////
void Graph :: make_graph_lagrange() const
{
    vector<double>x(10*mData.heights.size());
    for(size_t count(0);count< (mData.heights.size()-1);++count) {                          //The for loop help us to augment the number of point on which we will apply our approximation
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((mData.heights[count]-mData.heights[count+1])/ 10) * d) + mData.heights[count];
        }
    }
    vector<double>y(10*mData.heights.size());                                            //y is the vector where we keep the approximation of each points
    Lagrange lagrange;
    for (size_t j(0); j<10*mData.heights.size(); ++j)
    {
        y[j]+=lagrange.solve(mData.heights,mData.weights,x[j]);                           //we apply the lagrange formula to each augmented set of x points.
    }

    ///Plot///
    PieceWiseContinuePolynomial piece;
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(mData.heights,mData.weights,"Default points");
    sleep(20);
}

void Graph :: make_graph_piece_wise_least_squares(size_t const& degree, int const& Intervalle) const
{
    vector<double>x(10*mData.heights.size());                                            //The for loop help us to augment the number of point on which we will apply our approximation
    for(size_t count(0);count< (mData.heights.size()-1);++count) {
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((mData.heights[count]-mData.heights[count+1])/ 10) * d) + mData.heights[count];
        }
    }
    PieceWiseContinuePolynomial piece;
    vector<double>y(piece.solve_least_square(mData, degree, Intervalle,x));                //We apply piece wise least square method.
    ///Plot///
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(mData.heights,mData.weights,"Default points");
    sleep(20);

}

void Graph :: make_graph_piece_wise_lagrange(int const& intervalle)
{
    vector<double>x(10*mData.heights.size());                                            //The for loop help us to augment the number of point on which we will apply our approximation
    for(int count(0);count< (mData.heights.size()-1);++count) {
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((mData.heights[count] - mData.heights[count+1])/ 10) * d) + mData.heights[count];
        }
    }
    PieceWiseContinuePolynomial piece;
    vector<double>y(piece.solve_lagrange(mData, intervalle, x));                           //We apply piece wise Lagrange method.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(mData.heights, mData.weights,"Default points");
    sleep(20);
}

void Graph :: make_graph_FFT(Data data_original)
{
    //////////////////////// COMPUTE THE FFT /////////////////////////////////////////////////
    FFTreal fft;
    vector<double> imaginary_part(mData.heights.size(), 0.0);
    fft.transform(mData.weights, imaginary_part);

    vector<double> ifft(mData.weights);
    fft.inverseTransform(ifft, imaginary_part);

    //////////////////////// COMPUTE THE FOURIER APPROXIMATION ////////////////////////////////
    size_t nbK(mData.weights.size()); //number of ak and bk to compute
    vector<double> an(nbK, 0.0);
    vector<double> bn(nbK, 0.0);

    //we used cos(pi*x which has a period of 2
    fft.transformCoefs(data_original.weights, an, bn, 2);
    vector<double> approx(fft.transformApproximation(an, bn, 2, data_original.weights));

    for (auto &element : ifft) {
        element /= ifft.size();
    }

    //on doit plotter data_copy où on a changé les valeurs des x associée aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(data_original.heights, mData.weights, "Approximation");
    sleep(2);
    g1.plot_xy(data_original.heights, ifft, "Inverse FFT");
    sleep(2);
    g1.plot_xy(data_original.heights, data_original.weights, "Default points");
    sleep(2);
    g1.plot_xy(data_original.heights, approx, "Fourier");
    sleep(20);
}
