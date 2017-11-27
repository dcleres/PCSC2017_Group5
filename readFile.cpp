//
// Created by David Cleres on 27.11.17.
//

#include <stdexcept>
#include <iostream>
#include <fstream>
#include "readFile.h"

std::string ReadFile::loadFromFile()
{
    std::cerr << "Reloading world from file <" << mFilename << ">" << std::endl;
    std::string content("");
    std::ifstream in (mFilename);

    if (!in)
        throw std::runtime_error("Couldn't open file <" + mFilename + ">");

    while (!in.eof())
    {
        std::string buffer;
        getline(in, buffer);
        content += buffer + "\n";
    }

    if (!in.eof())
    {
        throw std::runtime_error("Failed to load values from file <" + mFilename + ">");
    }
    else
    {
        std::cerr << "Loaded all values from file <" << mFilename << ">" << std::endl << std::flush;
    }
    return content;
}

ReadFile::ReadFile (std::string const& filename)
    : mFilename(filename)
    {}

std::string ReadFile::getFilename() {
    return mFilename;
}


