#ifndef _FONTS_H
#define _FONTS_H

#include <iostream>
#include <string.h>
#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>

using namespace std;

class _fonts
{
    public:
        _fonts();
        virtual ~_fonts();

        void initFonts(char *);
        void buildFont(char *, float);
        void setPosition(int, int);
        void drawFonts();

        //vec2 vert[4];
        charSet chr[1024];
        int chrCount;

        float frames;

        float xRotate;
        float yRotate;
        float zRotate;

        float xPos, yPos, zPos;

        _texture *charTex = new _texture();
    protected:

    private:
};

#endif // _FONTS_H
