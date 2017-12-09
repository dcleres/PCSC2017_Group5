//
// Created by pcsc on 12/9/17.
//


#include <assert.h>
#include "Point.h"

Point::Point(size_t const& taille)
:mx (vector<double>(taille))
,my (vector<double>(taille))
{}

Point :: Point(vector<double> const& x_copy,vector<double> const& y_copy)
: mx(x_copy)
, my(y_copy)
{
    assert (x_copy.size()==y_copy.size());
}

vector<double> Point :: get_x() const
{
    return mx;
}
vector<double> Point :: get_y() const
{
    return my;
}

void Point :: set_x(size_t const& index,double const& value)
{
    mx[index]=value;
}
void Point :: set_y(size_t const& index,double const& value){
    my[index]=value;
}