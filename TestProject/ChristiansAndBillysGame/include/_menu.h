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

        void drawSquare(float, float); // to draw a quad for the background
        void menuInit(char *);     // Load images to the background

//        _textureLoader *bTex = new _textureLoader();
        _texture *bTex = new _texture();

        float xMax,yMax,xMin,yMin;     //  For texture coordinates


    protected:

    private:
};

#endif // _MENU_H
