#ifndef _GLSCENE_H
#define _GLSCENE_H

#define GLEW_STATIC

#include<GL/glew.h>

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_input.h>
#include <_texture.h>
#include <_parallax.h>
#include <_player.h>
#include <_enemies.h>
#include <_timer.h>
#include <_fonts.h>
#include <_collision.h>
#include <_sounds.h>
#include <_menu.h>
#include <_door.h>
#include <_items.h>
#include <_onScreenButtons.h>
#include <_particles.h>
#include <_ui.h>
#include <cstring>
#include <_shaders.h>

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

        double posMX, posMY;

        void getOGLPos(int x, int y)        //Mouse map coordinates
        {
            GLint viewport[4];                  //To store veiwport values
            GLdouble modelview[16];             //To store Model values
            GLdouble projection[16];            //To store projection values

            GLfloat winX, winY, winZ;           //windows coordinates
            GLdouble posX, posY, posZ;          //Mapped mouse coordinates (output)

            glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
            glGetDoublev(GL_PROJECTION_MATRIX, projection);
            glGetIntegerv(GL_VIEWPORT, viewport);

            winX = (float)x;
            winY = (float)viewport[3] - (float)y;

            glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);                              //This is used for translation from 2D to 3D
            gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);               //This helps determine which coordinates to apply

            posMX = posX;
            posMY = posY;

        }

        float screenWidth, screenHeight;
        float xEye, yEye, xCam, yCam;
        int numOfEnms;                      //Number of Enemies Initially Spawned
        int numOfSumn;                      //Number of Enemies Summoned
        int i, j;
        int xPlayingField, yPlayingField;   //Dimensions of the level

        _input *kbMs = new _input();
        _texture *modelTex = new _texture();
        _parallax *backGround1 = new _parallax();
        _player *myPly = new _player();
        _timer *timer = new _timer();
        _collision *collided = new _collision();
        _sounds *snds = new _sounds();
        _door *door = new _door();
        _items *items = new _items();
        _menu *menu = new _menu();
        //_texture *menuPic = new _texture();

        _onScreenButtons *button = new _onScreenButtons();
        _onScreenButtons *newGameBtn = new _onScreenButtons();
        _onScreenButtons *helpBtn = new _onScreenButtons();
        _onScreenButtons *creditBtn = new _onScreenButtons();
        _onScreenButtons *exitBtn = new _onScreenButtons();

        _onScreenButtons *resumeBtn = new _onScreenButtons();
        _onScreenButtons *newHelpBtn = new _onScreenButtons();
        _onScreenButtons *newNewBtn = new _onScreenButtons();
        _onScreenButtons *newCreditBtn = new _onScreenButtons();
        _onScreenButtons *newExitBtn = new _onScreenButtons();

        _onScreenButtons *helpBackBtn = new _onScreenButtons();
        _onScreenButtons *creditsBackBtn = new _onScreenButtons();

        _onScreenButtons *pauseQuitBtn = new _onScreenButtons();
        _onScreenButtons *pauseHelpBtn = new _onScreenButtons();
        _onScreenButtons *pausePlayBtn = new _onScreenButtons();
        _onScreenButtons *pauseMenuBtn = new _onScreenButtons();

        string lastMenu;

        _ui hearts[10];
        _ui *ui = new _ui();
        _texture *texHearts = new _texture();
        _texture *texBorder = new _texture();
        _texture texItems[3];
        _fonts *eCounter = new _fonts();
        int eCount;

        _particles *part = new _particles();
        _shaders *shd = new _shaders();

/*
        bool doneLoading;
        bool liveLevel1;
        bool liveLevel2;
        bool liveLevel3;

        bool landingLevel;
        bool menuLevel;
        bool helpLevel;
        bool pauseLevel;
        bool creditLevel;

        bool landing = true;
*/
        _parallax *backGroundLevel1 = new _parallax();
/*
        _menu *menuImage = new _menu();
        _menu *helpImage = new _menu();
        _menu *pauseImage = new _menu();
        _menu *landingImage = new _menu();
        _menu *creditImage = new _menu();
*/
        _texture *texEnms = new _texture();
        _enemies enms[100];

        _texture *texDoor = new _texture();

        _fonts *fnts = new _fonts();

        _timer *swarmTimer = new _timer();
        float swarmRadius = 10.0;

        int winMsg(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

    protected:

    private:
};

#endif // _GLSCENE_H
