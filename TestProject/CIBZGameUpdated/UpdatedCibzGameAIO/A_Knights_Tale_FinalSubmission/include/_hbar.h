#ifndef _HBAR_H
#define _HBAR_H

#include <_common.h>
#include<GL/gl.h>
#include<_texture.h>

class _hbar
{
    public:
        _hbar();
        virtual ~_hbar();

        vec3 hbPos;
        vec3 hbScale;
        vec3 hbRot;
        vec3 vert[4];

        float xMin, xMax, yMin, yMax;

        void drawHB();

         _texture *hbImage = new _texture();

    protected:

    private:
};

#endif // _HBAR_H
