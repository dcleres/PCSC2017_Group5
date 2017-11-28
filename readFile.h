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
#include <vector>

enum Gender {MALE, FEMALE};

struct Data {
    std::vector<Gender> genders;
    std::vector<double> heights;
    std::vector<double> weights;
};

class ReadFile
{

public:
    ///@constructor
    ReadFile (std::string const& filename);
    ///@method
    void loadFromFile(Data & data);
    ///@method
    std::string getFilename();

private:
    ///@variable
    std::string mFilename;
};

#endif //PCSC2017_GROUP5_READFILE_H
