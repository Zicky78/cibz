#ifndef _MENU_H
#define _MENU_H


#include<iostream>
#include<string>
#include<gl/gl.h>
#include<windows.h>
//#include<_textureLoader.h>
#include<_texture.h>

using namespace std;

class _menu
{
    public:
        _menu();
        virtual ~_menu();

        void drawSquare(float, float, char); // to draw a quad for the background
        void menuInit();     // Load images to the background

//        _textureLoader *bTex = new _textureLoader();
        _texture *bTex = new _texture();

        bool doneLoading;
        bool liveLevel1;
        bool liveLevel2;
        bool liveLevel3;
        bool liveLevel4;
        bool liveLevel5;                //Billy added this
        bool newGame;                   //Billy added this

        int lastLiveLivel;

        bool landingLevel;
        bool menuLevel;
        bool helpLevel;
        bool pauseLevel;
        bool creditLevel;
        bool newMenu;

        bool holding;
        int currLevel;

        bool landing = true;

        _texture *menuImage = new _texture();
        _texture *helpImage = new _texture();
        _texture *pauseImage = new _texture();
        _texture *landingImage = new _texture();
        _texture *creditImage = new _texture();
        _texture *newMenuImage = new _texture();

        float xMax,yMax,xMin,yMin;     //  For texture coordinates


    protected:

    private:
};

#endif // _MENU_H
