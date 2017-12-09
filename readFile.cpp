//
// Created by David Cleres on 27.11.17.
//

#include <stdexcept>
#include <iostream>
#include <fstream>
#include<cassert>
#include "readFile.h"

using namespace std;

void ReadFile::loadFromFile(Data& data)
{
    std::cerr << "Reloading world from file <" << mFilename << ">" << std::endl;
    std::ifstream in (mFilename);

    assert(in.is_open());

    vector<point_t> Points;

    if (!in)
        throw std::runtime_error("Couldn't open file <" + mFilename + ">");

    //string firstline("");
    //getline(in, firstline);
    //cout << firstline << endl;
    while (!in.eof())
    {
        std::string bufferGender;
        double bufferWeight;
        double bufferHeight;

        in >> bufferHeight;
        in >> bufferWeight;
        data.heights.push_back(bufferHeight);
        data.weights.push_back(bufferWeight);

        point_t onePoint{};
        onePoint.x=bufferHeight;
        onePoint.y=bufferWeight;
        Points.push_back(onePoint);
    }

    if (!in.eof()) {
        throw std::runtime_error("Failed to load values from file <" + mFilename + ">");
    }
    else {
        std::cerr << "Loaded all values from file <" << mFilename << ">" << std::endl << std::flush;
    }
    in.close();
}

ReadFile::ReadFile (std::string const& filename)
    : mFilename(filename)
    {}

std::string ReadFile::getFilename() {
    return mFilename;
}

void ReadFile::show(Data const& data) {
    for (size_t i(0); i < data.heights.size(); i++) {
        cout << "Height: " << data.heights[i] << "\t";
        cout << "Weight:" << data.weights[i] << endl;
    }
}

void ReadFile::writeFile(Data const& data) {
    ofstream myfile;
    myfile.open ("output.txt");

    for (size_t i(0); i < data.heights.size(); i++) {
        myfile << data.heights[i];
        myfile << data.weights[i];
    }
    myfile.close();
}

