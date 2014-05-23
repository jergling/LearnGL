#ifndef RIBBONPARTICLE_H
#define RIBBONPARTICLE_H

#include <vector>
#include <Particle.h>
#include <stdio.h>

class RibbonParticle : public Particle
{
    public:
        RibbonParticle(float x, float y, float z, int maxSegments);
        std::vector< std::vector<float> > history;
        int limit;
        int index;
        bool filledYet;
        void move(float x, float y, float z, bool withVelocity);
        void setPos(float x, float y, float z, bool withVelocity);
        virtual ~RibbonParticle();
    protected:
    private:
};

#endif // RIBBONPARTICLE_H
