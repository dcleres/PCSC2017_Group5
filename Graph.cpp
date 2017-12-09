#include <iostream>
#include <cmath>
#include "Graph.h"
#include "Polynomial.h"
#include "gnuplot_i.hpp"
#include "PieceWise_Continue_Polynomial.h"
#include "Lagrange.h"

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
