#include "_menu.h"

_menu::_menu()
{
    //ctor
    xMax =1.0;
    yMax =0.0;
    xMin =0.0;
    yMin =1.0;
}

_menu::~_menu()
{
    //dtor
}
void _menu::drawSquare(float width, float height)
{
    glColor3f(1.0,1.0,1.0);
    bTex->TextureBinder();
    glBegin(GL_POLYGON);
    glTexCoord2f(xMin,yMin);
    glVertex3f(-width/height, -1, -12.0); //glVertex3f(-width/height, -1, -3.0);
    glTexCoord2f(xMax,yMin);
    glVertex3f(width/height, -1, -12.0); //glVertex3f(width/height, -1, -3.0);
    glTexCoord2f(xMax,yMax);
    glVertex3f(width/height, 1, -12.0); //glVertex3f(width/height, 1, -3.0);
    glTexCoord2f(xMin,yMax);
    glVertex3f(-width/height, 1, -12.0); //glVertex3f(-width/height, 1, -3.0);

    glEnd();
}

void _menu::menuInit(char* fileName)
{
    bTex->loadTexture(fileName);
}
