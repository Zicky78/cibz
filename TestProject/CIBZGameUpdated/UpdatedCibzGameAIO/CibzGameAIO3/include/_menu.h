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
        bool liveLevel1; //flags for levels
        bool liveLevel2;
        bool liveLevel3;

        bool liveLevel4;
        bool liveLevel5;
        bool newGame;

        int lastLiveLivel;

        bool landingLevel; //flags for menus
        bool menuLevel;
        bool helpLevel;
        bool pauseLevel;
        bool creditLevel;
        bool newMenu;

        bool tran1; //flags for transitions
        bool tran2;
        bool tran3;
        bool tran4;
        bool tran5;

        bool holding;
        int currLevel;
        bool gameOver = false;
        bool gameWin = false;

        bool landing = true;

        _texture *menuImage = new _texture();
        _texture *helpImage = new _texture();
        _texture *pauseImage = new _texture();
        _texture *landingImage = new _texture();
        _texture *creditImage = new _texture();
        _texture *newMenuImage = new _texture();

        _texture *transition1 = new _texture();
        _texture *transition2 = new _texture();
        _texture *transition3 = new _texture();
        _texture *transition4 = new _texture();
        _texture *transition5 = new _texture();
        _texture *gameOverImage = new _texture();
        _texture *gameWinImage = new _texture();

        float xMax,yMax,xMin,yMin;     //  For texture coordinates


    protected:

    private:
};

#endif // _MENU_H
