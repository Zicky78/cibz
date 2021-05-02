#include "_arrow.h"

_arrow::_arrow()
{
    //ctor
    vert[0].x = -0.5; vert[0].y = -0.5; vert[0].z = -1.0;
    vert[1].x = 0.5; vert[1].y = -0.5; vert[1].z = -1.0;
    vert[2].x = 0.5; vert[2].y = 0.5; vert[2].z = -1.0;
    vert[3].x = -0.5; vert[3].y = 0.5; vert[3].z = -1.0;

    xMin = yMin = 0.0;
    xMax = yMax = 1.0;
}

_arrow::~_arrow()
{
    //dtor
}

void _arrow::arrowInit()
{
    arrowPos.x = 0.0;
    arrowPos.y = 0.0;
    arrowPos.z = -1.0;

    arrowScale.x = 0.3;
    arrowScale.y = 0.3;
    arrowScale.z = 1.0;

    arrowRot.x = 0.0;
    arrowRot.y = 0.0;
    arrowRot.z = 0.0;
}

void _arrow::drawArrow()
{
    glTranslatef(arrowPos.x, arrowPos.y, arrowPos.z);
    glScalef(arrowScale.x, arrowScale.y, arrowScale.z);
    glRotatef(arrowRot.z, 0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
        glTexCoord2f(xMin, yMax);
        glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glTexCoord2f(xMax, yMax);
        glVertex3f(vert[1].x, vert[1].y, vert[1].z);
        glTexCoord2f(xMax, yMin);
        glVertex3f(vert[2].x, vert[2].y, vert[2].z);
        glTexCoord2f(xMin, yMin);
        glVertex3f(vert[3].x, vert[3].y, vert[3].z);
    glEnd();
}
