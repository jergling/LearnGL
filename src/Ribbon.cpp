//A Ribbon is a list of 3D points with velocities which can be turned into a quadstrip with some GL code.

#include "Ribbon.h"

std::vector< std::vector<float> > points;



Ribbon::Ribbon(std::vector< std::vector<float> > pointList)
{
    points = pointList;
}

Ribbon::Ribbon()
{
    //
}

Ribbon::~Ribbon()
{
    //dtor
}
