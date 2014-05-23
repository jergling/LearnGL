#ifndef PARTICLE_H
#define PARTICLE_H

#include <vector>
#include <VectorMath.h>

class Particle
{
    public:
        std::vector<float> location;
        std::vector<float> velocity;
        void move(float x, float y, float z, bool withDirection);
        Particle();
        virtual ~Particle();
    protected:
    private:
};

#endif // PARTICLE_H
