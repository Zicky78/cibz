//Billy Ayala
//ID: 108474009
//CSCI 191 - Game Development Midterm
#include "_onScreenButtons.h"

_onScreenButtons::_onScreenButtons()
{
    //ctor
    vert[0].x = -0.1; vert[0].y = -0.05; vert[0].z = -1.0;
    vert[1].x =  0.1; vert[1].y = -0.05; vert[1].z = -1.0;
    vert[2].x =  0.1; vert[2].y =  0.05; vert[2].z = -1.0;
    vert[3].x = -0.1; vert[3].y =  0.05; vert[3].z = -1.0;

    xMin = yMin = 0.0;
    xMax = yMax = 1.0;

    buttonPos.x = 0.0;
    buttonPos.y = 0.0;
    buttonPos.z = 0.5;

    pressed = false;
    hovered = false;
}

_onScreenButtons::~_onScreenButtons()
{
    //dtor
}

void _onScreenButtons::buttonInit(char* fileName, string id)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    buttonTexture->loadTexture(fileName);
    buttonID = id;
}

void _onScreenButtons::buttonInit(string id)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    buttonID = id;
}

void _onScreenButtons::drawButton()
{
    if(hovered){
        glColor3f(0.7, 0.7, 0.7);
        if(pressed){
            glColor3f(1.0, 1.0, 1.0);
        }
    }
    else{
        glColor3f(0.5,0.5,0.5);
    }
    glTranslatef(buttonPos.x, buttonPos.y, buttonPos.z);

    glBegin(GL_POLYGON); // type I want to draw
        glTexCoord2f(xMin,yMax); glVertex3f(vert[0].x, vert[0].y, vert[0].z);
        glTexCoord2f(xMax,yMax); glVertex3f(vert[1].x, vert[1].y, vert[1].z);
        glTexCoord2f(xMax,yMin); glVertex3f(vert[2].x, vert[2].y, vert[2].z);
        glTexCoord2f(xMin,yMin); glVertex3f(vert[3].x, vert[3].y, vert[3].z);
    glEnd();
}
