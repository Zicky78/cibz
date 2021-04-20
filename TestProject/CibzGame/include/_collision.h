#ifndef _COLLISION_H
#define _COLLISION_H

#include <math.h>
#include <iostream>

using namespace std;

class _collision
{
    public:
        _collision();
        virtual ~_collision();

        //These detection functions should go in the timer function in glScene
        //Values passed in are X1, Y1, R1, X2, Y2, R2

        bool detectCollision(float, float, float, float, float, float);

        bool detectAggro(float, float, float, float, float, float);

        bool detectItem(float, float, float, float, float, float);

    protected:

    private:
};

#endif // _COLLISION_H
