#ifndef _PARTICLES_H
#define _PARTICLES_H

#include <math.h>

#define MAX_DROPS 50000
#define GRAVITY -0.001

class _particles
{
    public:
        _particles();
        virtual ~_particles();

        typedef struct{
            bool alive;
            float posX, posY, posZ;

            float xDir, yDir;

            float mass;

        }pts;

        pts drops[MAX_DROPS];

        void drawDrops();
        void update();
        void particleGenerator();


    protected:

    private:
};

#endif // _PARTICLES_H
