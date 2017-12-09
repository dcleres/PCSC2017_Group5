//
// Created by pcsc on 12/9/17.
//



#ifndef PCSC2017_GROUP5_POINT_H
#define PCSC2017_GROUP5_POINT_H

#include <vector>
using namespace std ;

class Point {

public:
    Point(int taille);
    Point(vector<double>x,vector<double>y);
    vector<double> get_x();
    vector<double> get_y();
    void set_x(int index,double value);
    void set_y(int index,double value);
private:
    vector<double>x;
    vector<double>y;

};

#endif //PCSC2017_GROUP5_POINT_H
