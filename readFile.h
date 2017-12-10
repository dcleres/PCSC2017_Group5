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
struct Data
{
    std::vector<double> heights;
    std::vector<double> weights;
};



typedef struct {
    double x;
    double y;
} point_t;


class ReadFile
{

public:
    /** \brief Constructor
     * \param filename is the name and path of the file to open
     */
    explicit ReadFile (std::string const& filename);

    /** \brief Reads in the file and save the data in the data variable
     * \param data is taken by reference to contain all the values in the file
     */
    void loadFromFile(Data& data) const;

    /** \brief Reads in the file and save the data in the data variable
     * \param data is taken by reference to contain all the values in the file
     */
    void loadFromFileTest(Data& data) const;

    /** \brief gives the name of the file to open
     */
    std::string getFilename() const;

    /** \brief diplay all the read values in the terminal
     * \param data contains the values to display
     */
    void show(Data const& data) const;

    /** \brief writes in a file
     * \param data data to write in a file
     */    void writeFile(Data const& data) const;

private:
    std::string mFilename;
};

#endif //PCSC2017_GROUP5_READFILE_H
