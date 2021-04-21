#ifndef _PARALLAX_H
#define _PARALLAX_H

#include<string>
#include<GL/gl.h>
#include<_texture.h>
#include<_common.h>

using namespace std;

class _parallax
{
    public:
        _parallax();
        virtual ~_parallax();

        vec3 plxPos;

        void renderBack(float, float);              //This renders BackGround
        void parallaxInit(char *);
        void parallaxInit(char *, float, float);
        void scroll(float);

        float xMax, xMin, yMax, yMin;
        bool lFlag, rFlag, uFlag, dFlag;
        bool lHitFlag, rHitFlag, uHitFlag, dHitFlag;
        bool isDodging, isAttacking, isHit;
        _texture *plxTexture = new _texture;

    protected:

    private:
};

#endif // _PARALLAX_H
