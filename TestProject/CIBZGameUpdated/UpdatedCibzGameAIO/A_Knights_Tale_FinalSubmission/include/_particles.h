#ifndef _PARTICLES_H
#define _PARTICLES_H

#include <math.h>
#include <GL/gl.h>
#include <_timer.h>
#include <stdlib.h>
#include <_player.h>
#include <_enemies.h>
#include <_collision.h>

#define MAX_DROPS 10000
#define GRAVITY -0.005

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

            float xProjDest, yProjDest;
            float t;

            float partFloor, movedFloor;
            float xImpactDir, yImpactDir;
            float xSpeed, ySpeed;

            bool lethal;
            char id;

            _timer *particleTimer = new _timer();

        }pts;

        void scroll(float, pts*);
        void projectileScroll(float, pts*);
        bool lFlag, rFlag, uFlag, dFlag;
        bool isAttacking, isDodging, isBlocking;


        //Blood
        int numBldDrops;

        pts bldDrops[MAX_DROPS];

        void drawBlood();
        void updateBlood(float, float);
        void plyrBldGenerator(_player*, _enemies*);
        void enmyBldGenerator(_enemies*);

        //Projectile
        int numProjDrops;
        int numTrailDrops;

        pts projectile[MAX_DROPS];
        pts trail[MAX_DROPS];

        void drawProjectile();
        void updateProjectile(_player*, _enemies*, int, int &, bool, float , float);
        void projectileGenerator(_enemies*);

        void drawTrail();
        void updateTrail(float, float);
        void trailGenerator(int);

        _collision* collChkr = new _collision();

    protected:

    private:
};

#endif // _PARTICLES_H
