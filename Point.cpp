//
// Created by pcsc on 12/9/17.
//


#include <assert.h>
#include "Point.h"

Point :: Point(int taille)
{
    vector<double>x(taille);
    vector<double>y(taille);
}
Point :: Point(vector<double>x_copy,vector<double>y_copy){
    assert (x_copy.size()==y_copy.size());
    vector<double>x(x_copy);
    vector<double>y(y_copy);

}
vector<double> Point :: get_x(){
    return x;
};
vector<double> Point :: get_y(){
    return y;
};
void Point :: set_x(int index,double value){
    x[index]=value;
};
void Point :: set_y(int index,double value){
    y[index]=value;
};