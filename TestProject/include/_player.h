#ifndef _PLAYER_H
#define _PLAYER_H

#include<_common.h>
#include<_texture.h>
#include<GL/gl.h>
#include<iostream>

using namespace std;
/*
typedef struct{
    float x;
    float y;
    float z;
}vec3;
*/
class _player
{
    public:
        _player();
        virtual ~_player();

        enum {STAND, LWALK, RWALK, UWALK, DWALK, ATK, HATK, DODGE};
        int actionTrigger;
        int compTrigger;
        int prevTrigger;
        bool isDodging, isAttacking;
        //bool onGround;
        bool uFlag, dFlag, rFlag, lFlag;
        enum {LEFT, RIGHT, UP, DOWN};
        int facingDirection;

        vec2 dodgePos;
        vec3 playerPos;                     //For setting player position
        vec3 playerScale;                   //For setting player scale
        vec3 playerRot;

        vec3 vert[4];                       //Vertices for drawing the player

        void playerInit(float, float);                  //Initializing the player
                                                        //pass x # of frames and y # of frames
        void drawPlayer();                  //Rendering the player
        void actions();                     //actions

        float xMin, xMax, yMin, yMax;
        //float yFloor;
        float xFrames, yFrames;

        _texture *plyImage = new _texture();            //Creates player image instance

    protected:

    private:
};

#endif // _PLAYER_H
