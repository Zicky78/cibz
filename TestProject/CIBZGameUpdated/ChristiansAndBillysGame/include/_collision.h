#ifndef _COLLISION_H
#define _COLLISION_H

#include <math.h>
#include <iostream>
#include <_player.h>
#include <_enemies.h>
#include <_parallax.h>

using namespace std;

class _collision
{
    public:
        _collision();
        virtual ~_collision();

        enum{LEFT, RIGHT, UP, DOWN};
        //These detection functions should go in the timer function in glScene
        //Values passed in are X1, Y1, R1, X2, Y2, R2

        bool detectCollision(float, float, float, float, float, float);
        bool detectCollision(_player*, _enemies);

        bool detectAggro(float, float, float, float, float, float);
        bool detectAggro(_player*, _enemies);

        bool detectItem(float, float, float, float, float, float);

        bool atkCollision(_player*, _enemies);

        bool collisionOrientation(_player*, _enemies);
        int enemyHitPlayer(_player*, _enemies*, _parallax*);

    protected:

    private:
};

#endif // _COLLISION_H
