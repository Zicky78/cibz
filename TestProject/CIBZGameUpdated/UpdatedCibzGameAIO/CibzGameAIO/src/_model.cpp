#include "_model.h"

_model::_model()
{
    //ctor
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    xPos = 0.0;
    yPos = 0.0;
    zoom = -8.0;
}

_model::~_model()
{
    //dtor
}
void _model::drawModel()
{
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(xPos, yPos, zoom);
        glRotatef(rotateX, 1, 0, 0);
        glRotatef(rotateY, 0, 1, 0);
        glRotatef(rotateZ, 0, 0, 1);

        glutSolidSphere(0.4,20,20);
        //glutSolidTeapot(0.5);


    glPopMatrix();
}
