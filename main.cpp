/*! \mainpage Data Approximation
 *
 * This project helps user to approximate data that he can her-/himself plug into the program using the data.dat file.
 * Currently two types of shapes can be drawn:
 * - \subpage LagrangePolynomial Functions "How to use the Lagrange method?"
 *
 * - \subpage FourierTransforms "How to does the Fourier Approximation works?"
 *
 */

/*! \page LagrangePolynomial How to use the Lagrange method?
 *
 * Lorem ipsum dolor sit amet
 *
 */

/*! \page FourierTransforms How to does the Fourier Approximation works?
 *
 * This page is about how to draw a circle.
 * Following sections describe circle:
 * - \ref groupCircleDefinition "Definition of Circle"
 * - \ref groupCircleClass "Circle Class"
 */


/**
 * \file main.cpp
 * \brief This is the function to call to run the script of the project
 */

#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>
#include <complex>
#include "readFile.h"
#include "gnuplot_i.hpp"
#include "Polynomial.h"
#include "Lagrange.h"
#include "Graph.h"
#include "FFTreal.h"

using namespace std;

enum ApproxiamtionMethod {LEASTSQUARES, FOURIER, LAGRANGE,PIECEWISELEASTSQUARE,PIECEWISELAGRANGE};

int main()
{
    std::string fname("/home/pcsc/Desktop/PCSC2017_Group5/data/data.dat");
    ReadFile readFile(fname);

    std::string fnameTest("/home/pcsc/Desktop/PCSC2017_Group5/data/testData.dat");
    ReadFile readFileTest(fnameTest);

    //TRAINING VALUES
    vector<double> xs;
    vector<double> ys;
    Data data = {xs, ys};
    readFile.loadFromFile(data);
    //readFile.show(data); //SHOWS THE IMPORTED DATA

    //TEST VALUES
    vector<double> xsTest;
    vector<double> ysTest;
    Data dataTest = {xsTest, ysTest};
    readFileTest.loadFromFileTest(dataTest);
    //readFile.show(data); //SHOWS THE IMPORTED DATA

    //Makes a copy of the input data since it is taken by reference in the rest of the program
    Data data_original = data;
    size_t degree;
    int intervalle;

    Graph graph(data); // use to make all the graph
    ////////////////////////////////////////////Least Square/////////////////////////////////////////////////
    //graph.make_graph_least_square(data,7);
    ///////////////////////////////////PieceWise Least Square////////////////////////////////////////////////
    //graph.make_graph_piece_wise_least_squares(data,2,4);
    /////////////////////////////////////Lagrange///////////////////////////////////////////////////////////
    //graph.make_graph_lagrange(data);
    //////////////////////////////////PieceWise Lagrange////////////////////////////////////////////////////
    //graph.make_graph_piece_wise_lagrange(data,10);



    int choice;
    cout << "Welcome to David Cleres and Nicolas Lesimple data approximation tool. YOu have the choice between using three";
    cout << " different approximation method which are:" << endl;
    cout << "1. Least Squares approximation" << endl;
    cout << "2. Fourier Approximation" << endl;
    cout << "3. Lagrange polynomial approximation" << endl;
    cout << "4. PieceWise Least Square approximation" << endl;
    cout << "5. PieceWise Lagrange approximation" << endl;
    cout << endl;
    cout << "Please select your approximation method by typing a number between 1 and 5" << endl;
    cout << "your choice is: " << flush;
    cin >> choice;

    ApproxiamtionMethod usersApproxChoice;

    try {
        //Convert the given Number to enum type
        switch(choice)
        {
            case 1: usersApproxChoice = LEASTSQUARES;
                break;
            case 2: usersApproxChoice = FOURIER;
                break;
            case 3: usersApproxChoice = LAGRANGE;
                break;
            case 4: usersApproxChoice = PIECEWISELEASTSQUARE;
                break;
            case 5: usersApproxChoice = PIECEWISELAGRANGE;
                break;

            default: throw string("ERREUR: The user did not specified a number in the given boundaries");
        }
    } catch (string const& e) {
        usersApproxChoice = FOURIER;
        cout << "The approximation method has been set to: Fourier Approximation";
    }

    switch(usersApproxChoice) {
        case LEASTSQUARES: {
            cout << "LEAST SQUARES" << endl;
            cout << "Choose the degree of approximation you want. It must be an integer :  " <<flush;
            cin>> degree;
            graph.make_graph_least_square(degree);
        } break;

        case LAGRANGE: {
            cout << "LAGRANGE" << endl;
            graph.make_graph_lagrange();
        } break;

        case FOURIER: {
            cout << "FOURIER" << endl;
            graph.make_graph_FFT(dataTest);
        }   break;

        case PIECEWISELEASTSQUARE: {
            cout << "PIECEWISE LEAST SQUARE" << endl;
            cout << "Choose the degree of approximation you want. It must be an integer :  " <<flush;
            cin>> degree;
            cout << "Choose the number of interval for your approximation you want. It must be an even integer :  " <<flush;
            cin>>intervalle;
            graph.make_graph_piece_wise_least_squares(degree,intervalle);
        }   break;

        case PIECEWISELAGRANGE: {
            cout << "PIECEWISE LAGRANGE" << endl;
            cout << "Choose the number of interval for your approximation you want. It must be an even integer :  " <<flush;
            cin>>intervalle;
            graph.make_graph_piece_wise_lagrange(intervalle);
        }   break;

    }
    return 0;
}