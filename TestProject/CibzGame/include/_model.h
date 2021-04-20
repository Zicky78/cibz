#ifndef _MODEL_H
#define _MODEL_H

#include <windows.h>
#include <GL/glut.h>
#include <iostream>

class _model
{
    public:
        _model();
        virtual ~_model();
        void drawModel();

        float rotateX;
        float rotateY;
        float rotateZ;

        float zoom;
        float xPos;
        float yPos;
        //float zPos;



    protected:

    private:
};

#endif // _MODEL_H
