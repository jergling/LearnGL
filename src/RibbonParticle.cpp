#include "RibbonParticle.h"


//History of locations and headings
//std::vector< std::vector<float> > history;
std::vector< std::vector<float> > history;
float **hist;
int limit;
int index;
bool filledYet;

//local only.
void insertArrayElement(float x, float y, float z, float vx, float vy, float vz){
    hist[index][0] = x;
    hist[index][1] = y;
    hist[index][2] = z;
    hist[index][3] = vx;
    hist[index][4] = vy;
    hist[index][5] = vz;
}

void RibbonParticle::move(float x, float y, float z, bool withVelocity){

    location[0] += x;
    location[1] += y;
    location[2] += z;

    if (withVelocity){
        velocity[0] = x;
        velocity[1] = y;
        velocity[2] = z;
    }

    std::vector<float> lastStep;
    lastStep.insert( lastStep.end(), location.begin(), location.end());
    lastStep.insert( lastStep.end(), velocity.begin(), velocity.end());

    history.at(index)=lastStep;
    if (index + 1 < history.size() ){
        index++;
    }
    else{
        index = 0;
        filledYet = true;
    }
}

void RibbonParticle::setPos(float x, float y, float z, bool withVelocity){

    if (withVelocity){
        velocity[0] = x-location[0];
        velocity[1] = y-location[1];
        velocity[2] = z-location[2];
    }

    location[0] = x;
    location[1] = y;
    location[2] = z;

    std::vector<float> lastStep;
    lastStep.insert( lastStep.end(), location.begin(), location.end());
    lastStep.insert( lastStep.end(), velocity.begin(), velocity.end());

    history.at(index)=lastStep;
    if (index + 1 < history.size() )
        index++;
    else{
        index = 0;
        filledYet = true;
    }
}

RibbonParticle::RibbonParticle(float x, float y, float z, int maxSegments)
{
    limit = maxSegments;
    float hist[limit][6];
    index = 0;
    filledYet = false;
    history.resize(limit);

    std::vector<float> firstStep;
    firstStep.push_back(x);
    firstStep.push_back(y);
    firstStep.push_back(z);
    firstStep.push_back(0.0f);
    firstStep.push_back(0.0f);
    firstStep.push_back(0.0f);

    history.at(index)=firstStep;
//    insertArrayElement(x,y,z,0.0f,0.0f,0.0f);
    index++;

    location.push_back(x);
    location.push_back(y);
    location.push_back(z);

    velocity.push_back(0.0f);
    velocity.push_back(0.0f);
    velocity.push_back(0.0f);
}

RibbonParticle::~RibbonParticle()
{
    //dtor
}
