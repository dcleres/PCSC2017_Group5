//
// Created by David Cleres on 27.11.17.
//

#include <stdexcept>
#include <iostream>
#include <fstream>
#include "readFile.h"

using namespace std;

void ReadFile::loadFromFile(Data& data)
{
    std::cerr << "Reloading world from file <" << mFilename << ">" << std::endl;
    std::ifstream in (mFilename);

    if (!in)
        throw std::runtime_error("Couldn't open file <" + mFilename + ">");

    string firstline("");
    getline(in, firstline);
    cout << firstline << endl;
    while (!in.eof())
    {
        std::string bufferGender;
        double bufferWeight;
        double bufferHeight;

        in >> bufferGender;
        in >> bufferHeight;
        in >> bufferWeight;

        if (bufferGender == "Male")
            data.genders.push_back(MALE);
        else data.genders.push_back(FEMALE);

        data.heights.push_back(bufferHeight);
        data.weights.push_back(bufferWeight);
    }

    if (!in.eof())
    {
        throw std::runtime_error("Failed to load values from file <" + mFilename + ">");
    }
    else {
        std::cerr << "Loaded all values from file <" << mFilename << ">" << std::endl << std::flush;
    }
}

ReadFile::ReadFile (std::string const& filename)
    : mFilename(filename)
    {}

std::string ReadFile::getFilename() {
    return mFilename;
}

void ReadFile::show(Data& data) {
    for (size_t i(0); i < data.heights.size(); i++) {
        if (data.genders[i] == MALE) {
            std::cout << "Male\t";
        }
        else
        {
            std::cout << "Female\t";
        }
        cout << "Height: " << data.heights[i] << "\t";
        cout << "Weight:" << data.weights[i] << endl;
    }
}




