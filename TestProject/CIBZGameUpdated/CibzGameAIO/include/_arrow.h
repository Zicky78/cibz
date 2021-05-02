#ifndef _ARROW_H
#define _ARROW_H

#include <_common.h>
#include <_texture.h>
#include <GL/gl.h>
#include <math.h>


class _arrow
{
    public:
        _arrow();
        virtual ~_arrow();

        vec3 arrowPos;                     //For setting player position
        vec3 arrowScale;                   //For setting player scale
        vec3 arrowRot;

        vec3 vert[4];                       //Vertices for drawing the player

        void arrowInit();                  //Initializing the player
        void drawArrow();                  //Rendering the player

        float xMin, xMax, yMin, yMax;

        _texture *arwImage = new _texture();

    protected:

    private:
};

#endif // _ARROW_H
