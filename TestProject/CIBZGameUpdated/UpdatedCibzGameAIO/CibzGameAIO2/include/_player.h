#ifndef _PLAYER_H
#define _PLAYER_H

#include<_common.h>
#include<_texture.h>
#include<GL/gl.h>
#include<iostream>
#include<_timer.h>
//#include<_particles.h>

using namespace std;

class _player
{
    public:
        _player();
        virtual ~_player();

        enum {STAND, LWALK, RWALK, UWALK, DWALK, ATK, HATK, DODGE, HIT, BLOCK};
        int actionTrigger;

        bool isDodging, isAttacking;
        bool uFlag, dFlag, rFlag, lFlag;
        enum {LEFT, RIGHT, UP, DOWN};
        int facingDirection;

        float radiusPlayer;
        float atkRadius;
        int health;
        int lightDmg;
        int HeavyDmg;
        float speedMulti;
        bool invulnerable, isBlocking;
        bool dodgingLimit;
        float slowed;

        vec2 dodgePos;
        vec3 playerPos;                     //For setting player position
        vec3 playerScale;                   //For setting player scale
        vec3 playerRot;

        vec3 vert[4];                       //Vertices for drawing the player

        //pass x # of frames and y # of frames
        void playerInit(float, float);      //Initializing the player
        void drawPlayer();                  //Rendering the player
        void actions();                     //actions

        float xMin, xMax, yMin, yMax;
        float xFrames, yFrames;

        _texture *plyImage = new _texture();            //Creates player image instance
        _timer *plyTimer = new _timer();
        _timer *slowedTimer = new _timer();

    protected:

    private:
};

#endif // _PLAYER_H
