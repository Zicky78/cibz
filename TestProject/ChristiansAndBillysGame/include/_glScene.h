#ifndef _GLSCENE_H
#define _GLSCENE_H

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

using namespace std;

class _glScene
{
    public:
        _glScene();
        virtual ~_glScene();

        GLint initGL();
        GLint drawScene();
        void resizeGLScene(int, int);

        float screenWidth, screenHeight;
        float xEye, yEye, xCam, yCam;
        int numOfEnms;

        _input *kbMs = new _input();
        _texture *modelTex = new _texture();
        _parallax *backGround = new _parallax();
        _parallax *backGround1 = new _parallax();
        _player *myPly = new _player();
        _timer *timer = new _timer();
        _collision *collided = new _collision();
        _sounds *snds = new _sounds();
        _door *door = new _door();
        _items *items = new _items();

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

        _parallax *backGroundLevel1 = new _parallax();
        _parallax *backGroundLevel2 = new _parallax();
        _parallax *backGroundLevel3 = new _parallax();

        _menu *menuImage = new _menu();
        _menu *helpImage = new _menu();
        _menu *pauseImage = new _menu();
        _menu *landingImage = new _menu();
        _menu *creditImage = new _menu();

        _texture *texEnms = new _texture();
        _enemies enms[20];

        _texture *texDoor = new _texture();

        _fonts *fnts = new _fonts();

        int winMsg(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

    protected:

    private:
};

#endif // _GLSCENE_H
