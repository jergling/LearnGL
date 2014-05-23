#ifndef RIBBON_H
#define RIBBON_H
#include <vector>
#include <stdio.h>

class Ribbon
{
    public:
        std::vector< std::vector<float> > points;

        Ribbon(std::vector< std::vector<float> > pointList);
        Ribbon();
        virtual ~Ribbon();
    protected:
    private:
};

#endif // RIBBON_H
