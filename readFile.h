/**
 * \file readFile.h
 * \brief This is a simple positions accessor
 * \class Reafile
 * This accessor gets the position
 */

#ifndef PCSC2017_GROUP5_READFILE_H
#define PCSC2017_GROUP5_READFILE_H

#include <string>
#include <fstream>

class ReadFile
{

public:
    ///@constructor
    ReadFile (std::string const& filename);
    ///@method
    std::string loadFromFile();
    ///@method
    std::string getFilename();

private:
    ///@variable
    std::string mFilename;
};

#endif //PCSC2017_GROUP5_READFILE_H
