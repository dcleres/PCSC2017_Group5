/**
 * \file readFile.h
 * \class Reafile
 * \brief This is a simple positions accessor
 */

#ifndef PCSC2017_GROUP5_READFILE_H
#define PCSC2017_GROUP5_READFILE_H

#include <string>
#include <fstream>
#include <vector>

///\enum
enum Gender {MALE, FEMALE};

///\struct
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
    ///@method
    void show(Data& data);

private:
    ///@variable
    std::string mFilename;
};

#endif //PCSC2017_GROUP5_READFILE_H
