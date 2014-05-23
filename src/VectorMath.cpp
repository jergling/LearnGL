#include "VectorMath.h"

//Project vec1 onto vec2
std::vector<float> VectorMath::project(float vec1[3], float vec2[3]){
    //float magA = magnitude(vec1);
    //float magB = magnitude(vec2);
    //float dotAB = dotProduct(vec1, vec2);

    //float prod1 = dotAB/(magA * magB * magB);
    std::vector<float> outVec;

    float prod2 = dotProduct(vec1, vec2) / dotProduct(vec2, vec2);

    //vec2 * prod2
    outVec[0]=vec2[0]*prod2;
    outVec[1]=vec2[1]*prod2;
    outVec[2]=vec2[2]*prod2;

    return outVec;
}


float VectorMath::cosTheta(float vec1[3], float vec2[3]){
    return ( dotProduct(vec1,vec2) / (magnitude(vec1)*magnitude(vec2)) );
}


float VectorMath::dotProduct(float vec1[3], float vec2[3]){
    return (vec1[0]*vec2[0]+vec1[1]*vec2[1]+vec1[2]*vec2[2]);
}

std::vector<float> VectorMath::crossProduct(float vec1[3], float vec2[3]){
    std::vector<float> outVec;

    outVec.push_back(vec1[1]*vec2[2] - vec1[2]*vec2[1]);
    outVec.push_back(vec1[2]*vec2[0] - vec1[0]*vec2[2]);
    outVec.push_back(vec1[0]*vec2[1] - vec1[1]*vec2[0]);

    return outVec;
}

float VectorMath::magnitude(float vec1[3]){
    return sqrtf(pow(vec1[0],2) + pow(vec1[1],2) + pow(vec1[2],2));
}

std::vector<float> VectorMath::unitOf(float vec1[3]){
    float mag = magnitude(vec1);

    std::vector<float> outVec;

    outVec.push_back(vec1[0] / mag);
    outVec.push_back(vec1[1] / mag);
    outVec.push_back(vec1[2] / mag);


    return outVec;
}

VectorMath::VectorMath()
{
    //ctor
}

VectorMath::~VectorMath()
{
    //dtor
}
