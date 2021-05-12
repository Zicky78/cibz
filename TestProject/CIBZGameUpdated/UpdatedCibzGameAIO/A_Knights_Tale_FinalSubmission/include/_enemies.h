#ifndef _ENEMIES_H
#define _ENEMIES_H

#include<_common.h>
#include<_texture.h>
#include<_timer.h>
#include<GL/gl.h>
#include<string>
#include<_sounds.h>

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
        void summonEnms(float, float, bool);

        vec3 posE;                          //Position of enemies
        vec2 sizeE;                         //Size of the enemies
        vec2 calledPos;                     //Position of shouting enemy

        enum {STAND, LEFT, RIGHT, UP, DOWN, HIT, HUNT, CALLED};
        bool lFlag, rFlag, uFlag, dFlag;
        bool isDodging, isAttacking, isBlocking;
        bool plyAttacking, currDodging;
        bool shouted, isCalled, deaf, isHunting;
        int facingDirection;
        int randActTrigger;

        int xFrames, yFrames;               //Variables for the number of frames in the sprite sheets
        int actionTrigger;                  //Action trigger for enemies actions
        float enmySpd, enmyWlkSpd;          //Speed variables holding the default value that _Speed takes when chasing and walking respectively
        float plySpd, plyDdg, plyKnkBck;    //Speed variables holding the default value that _Speed2 takes
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
        int levelCount;

        _timer *eT = new _timer();          //For keeping animation at one speed
        _timer *timerRandAct = new _timer();

        _sounds *enmySnd = new _sounds();


    protected:

    private:
        float xMin, xMax, yMin, yMax;
};

#endif // _ENEMIES_H
