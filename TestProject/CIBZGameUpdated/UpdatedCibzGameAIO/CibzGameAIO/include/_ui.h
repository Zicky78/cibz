#ifndef _UI_H
#define _UI_H

#include <_common.h>
#include<_texture.h>
#include<GL/gl.h>
#include<_timer.h>

class _ui
{
    public:
        _ui();
        virtual ~_ui();

        int numOfHearts;
        vec3 heartPos;
        vec3 heartScale;
        vec3 heartRot;
        vec3 heartVert[4];

        vec3 borderPos;
        vec3 borderScale;
        vec3 borderRot;
        vec3 borderVert[4];

        float xMinH, yMinH, xMaxH, yMaxH;
        float xMinB, yMinB, xMaxB, yMaxB;

        float xMinI, xMaxI, yMinI, yMaxI, xFrames, yFrames;

        vec3 uiItemPos[3];
        vec3 uiItemScale[3];
        vec3 uiItemRot[3];
        vec3 uiItemVert[4];

        _timer *uiT = new _timer();

        GLuint texH;
        GLuint texB;
        GLuint texI[3];

        void drawHearts();
        void drawBorder();
        void drawUIItems();

    protected:

    private:
};

#endif // _UI_H
