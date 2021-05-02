#ifndef _ENEMIES_H
#define _ENEMIES_H

#include<_common.h>
#include<_texture.h>
#include<_timer.h>
#include<GL/gl.h>
#include<string>
//#include<_collision.h>                //Fails because causes cycled header calls

class _enemies
{
    public:
        _enemies();
        virtual ~_enemies();

        //Functions
        void drawEnms();                    //Render
        void enmsInit(char, float, float);
        void placeEnms(vec3);               //Placement
        void actionsEnms();                 //Movements
        void moveCausedByPlayer();          //Enemy movement in Relation to Player movement
        void randAction();
        void summonEnms(float, float);

        vec3 posE;                          //Position of enemies
        vec2 sizeE;                         //Size of the enemies
        vec3 rotateE;                       //Rotate enemies
        vec2 calledPos;                     //Position of shouting enemy

        enum {STAND, LEFT, RIGHT, UP, DOWN, HIT, HUNT, CALLED};
        bool lFlag, rFlag, uFlag, dFlag;
        bool isDodging, isAttacking, isBlocking;
        bool shouted, isCalled, deaf;
        int facingDirection;
        int randActTrigger;

        int xFrames, yFrames;               //
        int actionTrigger;                  //Action trigger for enemies actions
        float xSpeed, ySpeed;               //Speed of enemies movements
        float xSpeed2, ySpeed2;             //Speed of enemies movements because of player
        float enemyRadius;                  //Radius for the Enemy physical collision
        float detectRadius;                 //Radius for detecting Player
        float atkRadius;                    //Radius for melee Enemy with longer reach than physical body.

        GLuint tex;
        bool isAlive = true;
        bool alreadyHit;
        bool atkRange, charged;
        int dmgTaken;
        int enemyHealth;
        char id;
        int summonCap;

        _timer *eT = new _timer();          //For keeping animation at one speed
        _timer *timerRandAct = new _timer();

    protected:

    private:
        float xMin, xMax, yMin, yMax;
};

#endif // _ENEMIES_H
