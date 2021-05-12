#include "_ui.h"

_ui::_ui()
{
    //ctor

    //Hearts initialization
    numOfHearts = 10;
    heartPos.x = 1.3;
    heartPos.y = 3.2;
    heartPos.z = -1.0;
    heartScale.x = 0.4;
    heartScale.y = 0.27;
    heartScale.z = 1.0;
    heartRot.x = heartRot.y = heartRot.z = 0.0;

    xMinH = 0.0;
    xMaxH = 1.0;
    yMinH = 0.0;
    yMaxH = 1.0;

    heartVert[0].x = -1.0; heartVert[0].y = -1.0; heartVert[0].z = -1.0;
    heartVert[1].x =  1.0; heartVert[1].y = -1.0; heartVert[1].z = -1.0;
    heartVert[2].x =  1.0; heartVert[2].y =  1.0; heartVert[2].z = -1.0;
    heartVert[3].x = -1.0; heartVert[3].y =  1.0; heartVert[3].z = -1.0;

    //Border initialization
    borderPos.x = 5.0;
    borderPos.y = 2.3;
    borderPos.z = -1.0;
    borderScale.x = 1.5;
    borderScale.y = 0.5;
    borderScale.z = 1.0;
    borderRot.x = borderRot.y = borderRot.z = 0.0;

    xMinB = 0.0;
    xMaxB = 1.0;
    yMinB = 0.0;
    yMaxB = 1.0;

    borderVert[0].x = -1.0; borderVert[0].y = -1.0; borderVert[0].z = -1.0;
    borderVert[1].x =  1.0; borderVert[1].y = -1.0; borderVert[1].z = -1.0;
    borderVert[2].x =  1.0; borderVert[2].y =  1.0; borderVert[2].z = -1.0;
    borderVert[3].x = -1.0; borderVert[3].y =  1.0; borderVert[3].z = -1.0;

    xFrames = 8.0;
    yFrames = 1.0;
    xMinI = 0.0;
    xMaxI = 1.0/xFrames;
    yMinI = 0.0;
    yMaxI = 1.0/yFrames;

    uiItemPos[0].x = 4.0;
    uiItemPos[0].y = 2.35;
    uiItemPos[1].x = 4.8;
    uiItemPos[1].y = 2.35;
    uiItemPos[2].x = 5.6;
    uiItemPos[2].y = 2.35;

    for(int i = 0; i < 3; i++) {
        uiItemPos[i].z = -1.0;
        uiItemScale[i].x = uiItemScale[i].y = uiItemScale[i].z = 0.15;
        uiItemRot[i].x = uiItemRot[i].y = uiItemRot[i].z = 0.0;
    }

    uiItemVert[0].x = -1.0; uiItemVert[0].y = -1.0; uiItemVert[0].z = -1.0;
    uiItemVert[1].x =  1.0; uiItemVert[1].y = -1.0; uiItemVert[1].z = -1.0;
    uiItemVert[2].x =  1.0; uiItemVert[2].y =  1.0; uiItemVert[2].z = -1.0;
    uiItemVert[3].x = -1.0; uiItemVert[3].y =  1.0; uiItemVert[3].z = -1.0;

    uiT->startTimer();
}

_ui::~_ui()
{
    //dtor
}

void _ui::drawHearts()
{
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 1.0, 1.0);


    glBindTexture(GL_TEXTURE_2D, texH);
    glPushMatrix();
    glTranslatef(heartPos.x, heartPos.y, heartPos.z);
    glScalef(heartScale.x, heartScale.y, heartScale.z);
    glRotatef(heartRot.x, 1.0, 0.0, 0.0);
    glRotatef(heartRot.y, 0.0, 1.0, 0.0);
    glRotatef(heartRot.z, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glTexCoord2f(xMinH, yMaxH);
        glVertex3f(heartVert[0].x, heartVert[0].y, heartVert[0].z);
        glTexCoord2f(xMaxH, yMaxH);
        glVertex3f(heartVert[1].x, heartVert[1].y, heartVert[1].z);
        glTexCoord2f(xMaxH, yMinH);
        glVertex3f(heartVert[2].x, heartVert[2].y, heartVert[2].z);
        glTexCoord2f(xMinH, yMinH);
        glVertex3f(heartVert[3].x, heartVert[3].y, heartVert[3].z);
    glEnd();
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
}

void _ui::drawBorder()
{
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 1.0, 1.0);

    glBindTexture(GL_TEXTURE_2D, texB);
    glPushMatrix();
    glTranslatef(borderPos.x, borderPos.y, borderPos.z);
    glScalef(borderScale.x, borderScale.y, borderScale.z);
    glRotatef(borderRot.x, 1.0, 0.0, 0.0);
    glRotatef(borderRot.y, 0.0, 1.0, 0.0);
    glRotatef(borderRot.z, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glTexCoord2f(xMinB, yMaxB);
        glVertex3f(borderVert[0].x, borderVert[0].y, borderVert[0].z);
        glTexCoord2f(xMaxB, yMaxB);
        glVertex3f(borderVert[1].x, borderVert[1].y, borderVert[1].z);
        glTexCoord2f(xMaxB, yMinB);
        glVertex3f(borderVert[2].x, borderVert[2].y, borderVert[2].z);
        glTexCoord2f(xMinB, yMinB);
        glVertex3f(borderVert[3].x, borderVert[3].y, borderVert[3].z);
    glEnd();
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
}

void _ui::drawUIItems()
{
    for(int i = 0; i < 3; i++){
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1.0, 1.0, 1.0);

    glBindTexture(GL_TEXTURE_2D, texI[i]);
    glPushMatrix();
    glTranslatef(uiItemPos[i].x, uiItemPos[i].y, uiItemPos[i].z);
    glScalef(uiItemScale[i].x, uiItemScale[i].y, uiItemScale[i].z);

    glRotatef(uiItemRot[i].x, 1.0, 0.0, 0.0);
    glRotatef(uiItemRot[i].y, 0.0, 1.0, 0.0);
    glRotatef(uiItemRot[i].z, 0.0, 0.0, 1.0);

    glBegin(GL_QUADS);
        glTexCoord2f(xMinI, yMaxI);
        glVertex3f(uiItemVert[0].x, uiItemVert[0].y, uiItemVert[0].z);
        glTexCoord2f(xMaxI, yMaxI);
        glVertex3f(uiItemVert[1].x, uiItemVert[1].y, uiItemVert[1].z);
        glTexCoord2f(xMaxI, yMinI);
        glVertex3f(uiItemVert[2].x, uiItemVert[2].y, uiItemVert[2].z);
        glTexCoord2f(xMinI, yMinI);
        glVertex3f(uiItemVert[3].x, uiItemVert[3].y, uiItemVert[3].z);
    glEnd();
    glPopMatrix();
    glDisable(GL_COLOR_MATERIAL);
    }
}

