#ifndef _DOOR_H
#define _DOOR_H

#include<_common.h>
#include<_texture.h>
#include<_timer.h>
#include<GL/gl.h>

class _door
{
    public:
        _door();
        virtual ~_door();

        void drawEnms();                    //Render
        void placeEnms(vec3);               //Placement
        void scroll(float);

        vec3 posE;                          //Position of enemies
        vec2 sizeE;                         //Size of the enemies

        enum {STAND, LEFT, RIGHT, UP, DOWN, HIT};
        bool lFlag, rFlag, uFlag, dFlag;
        bool isDodging, isAttacking, isBlocking;

        float enemyRadius;                  //Radius for the Enemy physical collision

        GLuint tex;
        bool isAlive = true;

    protected:

    private:
        float xMin, xMax, yMin, yMax;
};

#endif // _DOOR_H
