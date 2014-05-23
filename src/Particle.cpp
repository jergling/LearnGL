#include "Particle.h"

std::vector<float> location;
std::vector<float> velocity;

//Move with xyz vector, optionally update heading velocity automatically
void Particle::move(float x, float y, float z, bool withVelocity){
    location[0]+=x;
    location[1]+=y;
    location[2]+=z;

    if (withVelocity){
        velocity[0] = x;
        velocity[1] = y;
        velocity[2] = z;
    }
}

Particle::Particle()
{
    //ctor
}

Particle::~Particle()
{
    //dtor
}
