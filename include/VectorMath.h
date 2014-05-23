#ifndef VECTORMATH_H
#define VECTORMATH_H

#include <cmath>
#include <iostream>
#include <vector>

class VectorMath
{
    public:
        VectorMath();
        static std::vector<float> project(float vec1[3], float vec2[3]);
        static float cosTheta(float vec1[3], float vec2[3]);
        static float magnitude(float vec1[3]);
        static float dotProduct(float vec1[3], float vec2[3]);
        static std::vector<float> crossProduct(float vec1[3], float vec2[3]);
        static std::vector<float> unitOf(float vec1[3]);
        virtual ~VectorMath();
    protected:
    private:
};

#endif // VECTORMATH_H
