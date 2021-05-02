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

            float xProjDest, yProjDest;
            float t;

            float partFloor, movedFloor;
            float xImpactDir, yImpactDir;
            float xSpeed, ySpeed;

            bool lethal;

            _timer *particleTimer = new _timer();

        }pts;

        void scroll(float, pts*);
        void projectileScroll(float, pts*);
        //void scroll(float, float&, float&, float&, float&);
        bool lFlag, rFlag, uFlag, dFlag;
        bool isAttacking, isDodging, isBlocking;


        //Blood
        int numBldDrops;

        pts bldDrops[MAX_DROPS];

        void drawBlood();
        void updateBlood();
        void plyrBldGenerator(_player*, _enemies*);
        void enmyBldGenerator(_enemies*);

        //void bloodGenerator(float, float);

        //Projectile
        int numProjDrops;
        int numTrailDrops;

        pts projectile[MAX_DROPS];
        pts trail[MAX_DROPS];

        void drawProjectile();
        void updateProjectile(_player*, _enemies*, int, int &);
        void projectileGenerator(_enemies*);

        void drawTrail();
        void updateTrail();
        void trailGenerator(int);

        _collision* collChkr = new _collision();

    protected:

    private:
};

#endif // _PARTICLES_H
