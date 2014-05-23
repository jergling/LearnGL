#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H
#include <Particle.h>
#include <vector>

class ParticleSystem
{
    public:
        ParticleSystem();
        std::vector<Particle> partcles;
        virtual ~ParticleSystem();
    protected:
    private:
};

#endif // PARTICLESYSTEM_H
