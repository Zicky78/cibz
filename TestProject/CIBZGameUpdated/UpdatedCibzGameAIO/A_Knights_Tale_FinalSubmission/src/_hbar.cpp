#include "_hbar.h"

_hbar::_hbar()
{
    //ctor

    vert[0].x = -1.0; vert[0].y = -1.0; vert[0].z = -3.9;
    vert[1].x =  1.0; vert[1].y = -1.0; vert[1].z = -3.9;
    vert[2].x =  1.0; vert[2].y =  1.0; vert[2].z = -3.9;
    vert[3].x = -1.0; vert[3].y =  1.0; vert[3].z = -3.9;

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;

    hbPos.x = 0.0; hbPos.y = 0.0; hbPos.z = -3.9;
    hbScale.x = hbScale.z = 0.2;
    hbScale.y = 0.02;
    hbRot.x = hbRot.y = hbRot.z = 0.0;
}

_hbar::~_hbar()
{
    //dtor
}

void _hbar::drawHB()
{
    glTranslatef(hbPos.x, hbPos.y, hbPos.z);
    glScalef(hbScale.x, hbScale.y, hbScale.z);
    glRotatef(hbRot.x, 1.0, 0.0, 0.0);
    glRotatef(hbRot.y, 0.0, 1.0, 0.0);
    glRotatef(hbRot.z, 0.0, 0.0, 1.0);

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
