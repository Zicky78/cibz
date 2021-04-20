#ifndef _ENEMIES_H
#define _ENEMIES_H

#include<_common.h>
#include<_texture.h>
#include<_timer.h>
#include<GL/gl.h>

class _enemies
{
    public:
        _enemies();
        virtual ~_enemies();

        void drawEnms();                    //Render
        void placeEnms(vec3);               //Placement
        void actionsEnms();                 //Movements
        void moveCausedByPlayer();          //Enemy movement in Relation to Player movement
        void randAction();

        vec3 posE;                          //Position of enemies
        vec2 sizeE;                         //Size of the enemies
        vec3 rotateE;                       //Rotate enemies

        enum {STAND, LEFT, RIGHT, UP, DOWN, HIT};
        bool lFlag, rFlag, uFlag, dFlag;
        bool isDodging, isAttacking;
        int facingDirection;
        int randActTrigger;

        int xFrames, yFrames;               //
        int actionTrigger;                  //Action trigger for enemies actions
        float xSpeed, ySpeed;               //Speed of enemies movements
        float xSpeed2, ySpeed2;             //Speed of enemies movements because of player
        float enemyRadius;                  //Radius for the Enemy physical collision
        float detectRadius;                 //Radius for detecting Player

        GLuint tex;
        bool isAlive = true;

        _timer *eT = new _timer();          //For keeping animation at one speed
        _timer *timerRandAct = new _timer();

    protected:

    private:
        float xMin, xMax, yMin, yMax;
};

#endif // _ENEMIES_H
