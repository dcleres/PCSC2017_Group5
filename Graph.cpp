#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Polynomial.h"
#include "gnuplot_i.hpp"
#include "PieceWise_Continue_Polynomial.h"
#include "Lagrange.h"
#include "FFTreal.h"

Graph :: Graph(Data data)
{

}

////////////////LeastSquare//////////////////////////////
void Graph :: make_graph_least_square(Data data, int degree){

    Polynomial poly;
    vector <double> a (poly.solve(data.heights,data.weights, degree));                  // we found the coefficient by the least square method minimizibg the loss. a is a vector with the coefficients searched.
    vector<double>y(10*data.heights.size());                                            //y will have the polynomial approximation thanks to the coefficients we found

    cout<< "The interpolation polynome is : ";
    for (size_t i(0); i < (degree+1);i++){
        cout<<" + ("<<a[i]<<")"<<"x^"<<i;
    }
    cout<<endl;
    vector<double>x(10*data.heights.size());                                            //We choose to put 10 points of approximation between each point we have in the data set
    for(int count(0);count< (data.heights.size()-1);++count) {                          //The for loop help us to augment the number of point on which we will apply our approximation
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((data.heights[count]-data.heights[count+1])/ 10) * d) + data.heights[count];
        }
    }
    for (size_t j(0); j<10*data.heights.size(); ++j)
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
    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(2);
}


/////////////////////////Lagrange/////////////////////////////
void Graph :: make_graph_lagrange(Data data){
    vector<double>x(10*data.heights.size());
    for(int count(0);count< (data.heights.size()-1);++count) {                          //The for loop help us to augment the number of point on which we will apply our approximation
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((data.heights[count]-data.heights[count+1])/ 10) * d) + data.heights[count];
        }
    }
    vector<double>y(10*data.heights.size());                                            //y is the vector where we keep the approximation of each points
    Lagrange lagrange;
    for (size_t j(0); j<10*data.heights.size(); ++j)
    {
        y[j]+=lagrange.solve(data.heights,data.weights,x[j]);                           //we apply the lagrange formula to each augmented set of x points.
    }

    ///Plot///
    PieceWise_Continue_Polynomial piece;
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(20);


}

void Graph :: make_graph_piece_wise_least_squares(Data data, int degree, int Intervalle){

    vector<double>x(10*data.heights.size());                                            //The for loop help us to augment the number of point on which we will apply our approximation
    for(int count(0);count< (data.heights.size()-1);++count) {
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((data.heights[count]-data.heights[count+1])/ 10) * d) + data.heights[count];
        }
    }
    PieceWise_Continue_Polynomial piece;
    vector<double>y(piece.solve_least_square(data,degree,Intervalle,x));                //We apply piece wise least square method.
    ///Plot///
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(20);

}

void Graph :: make_graph_piece_wise_lagrange(Data data, int intervalle){
    vector<double>x(10*data.heights.size());                                            //The for loop help us to augment the number of point on which we will apply our approximation
    for(int count(0);count< (data.heights.size()-1);++count) {
        for (size_t d(0); d < 10; ++d) {
            x[count*10+d] = (((data.heights[count]-data.heights[count+1])/ 10) * d) + data.heights[count];
        }
    }
    PieceWise_Continue_Polynomial piece;
    vector<double>y(piece.solve_lagrange(data,intervalle,x));                           //We apply piece wise Lagrange method.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(x,y,"Approximation");
    sleep(2);
    g1.plot_xy(data.heights,data.weights,"Default points");
    sleep(20);
}

void Graph :: make_graph_FFT(Data data, Data data_original){

    //////////////////////// COMPUTE THE FFT /////////////////////////////////////////////////
    FFTreal fft;
    vector<double> imaginary_part(data.heights.size(), 0.0);
    fft.transform(data.weights, imaginary_part);

    vector<double> ifft(data.weights);
    fft.inverseTransform(ifft, imaginary_part);

    //////////////////////// COMPUTE THE FOURIER APPROXIMATION ////////////////////////////////
    size_t nbK(data.weights.size()); //number of ak and bk to compute
    vector<double> an(nbK, 0.0);
    vector<double> bn(nbK, 0.0);

    //we used cos(pi*x which has a period of 2
    fft.transformCoefs(data_original.weights, an, bn, 2);
    vector<double> approx(fft.transformApproximation(an, bn, 2, data_original.weights));

    //cout << "WORD" << endl;
    /*for (auto& element : data.weights)
    {
        element /= 10; //(2*M_PI); //F = 1/(2*PI) * F-¹
    }*/
    /*for (auto element : data.heights)
    {
        cout << element << endl;
    }*/

    /*FourierApproximation approx;
    int n (10);
    vector<double> v = approx.fourierCoefficients(f1, n);

    vector<double> weightsApprox(data.heights.size());
    for(size_t i(0); i < weightsApprox.size(); i++)
    {
        weightsApprox[i] = approx.fourierApproximation(v, data.heights[i], n);
    }*/

    //FAIRE AVEC DES COSINUS ET SINUS ET PUIS PAS DES COMPLEXES ET C'EST CHILL

    /*double a(0);
    double b(0);

    double* a_ptr(&a);
    double* b_ptr(&b);

    double t1(0);
    double t2(2*M_PI);

    vector<double> ans(5);
    vector<double> bns(5);

    for (int n(0); n < 6; n++)
    {
        AnalyticFourierHn(t1,t2, n, a_ptr, b_ptr);
        ans[n] = *a_ptr;
        bns[n] = *b_ptr;
    }

    vector<double> results(data.heights.size());
    for (int i(0); i < data.heights.size(); i++)
    {
        results[i] = approxFunction (data.heights[i], ans, bns);
    }*/

    for (auto &element : ifft) {
        element /= ifft.size();
    }

    //on doit plotter data_copy où on a changé les valeurs des x associée aux y.
    Gnuplot g1 = Gnuplot("lines");
    g1.set_style("points");
    g1.plot_xy(data_original.heights, data.weights, "Approximation");
    sleep(2);
    g1.plot_xy(data_original.heights, ifft, "Inverse FFT");
    sleep(2);
    g1.plot_xy(data_original.heights, data_original.weights, "Default points");
    sleep(2);
    g1.plot_xy(data_original.heights, approx, "Fourier");
    sleep(20);
}
