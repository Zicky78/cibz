//Billy Ayala
//ID: 108474009
//CSCI 191 - Game Development Midterm

#ifndef _ONSCREENBUTTONS_H
#define _ONSCREENBUTTONS_H

#include<GL/gl.h>
#include<_common.h>
#include<_texture.h>
#include<string>

class _onScreenButtons
{
    public:
        _onScreenButtons();
        virtual ~_onScreenButtons();

        vec3 vert[4];
        vec3 buttonPos;

        void buttonInit(char *, string);
        void drawButton();

        float xMax,xMin,yMax,yMin;
        string buttonID;
        bool pressed;
        bool hovered;
        _texture *buttonTexture = new _texture();

    protected:

    private:
};

#endif // _ONSCREENBUTTONS_H
