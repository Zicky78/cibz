#ifndef _GLSCENE_H
#define _GLSCENE_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <_model.h>
#include <_input.h>
#include <_texture.h>
#include <_parallax.h>
#include <_player.h>
#include <_timer.h>
#include <_arrow.h>
#include <_fonts.h>

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

        _model *modelTeapot = new _model;
        _input *kbMs = new _input();
        _texture *modelTex = new _texture();
        _parallax *backGround = new _parallax();
        _parallax *backGround1 = new _parallax();
        _player *myPly = new _player();
        _timer *timer = new _timer();
        _fonts *fnts = new _fonts();

        _arrow *arrow = new _arrow();

        int winMsg(HWND, UINT, WPARAM, LPARAM);
        WPARAM wParam;

    protected:

    private:
};

#endif // _GLSCENE_H
