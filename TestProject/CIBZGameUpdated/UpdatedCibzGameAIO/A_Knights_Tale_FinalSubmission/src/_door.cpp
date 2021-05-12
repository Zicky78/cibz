#include "_door.h"
//#include "_glScene.h"

_door::_door()
{
    //ctor
    posE.x = posE.y = 0.0;
    posE.z = -8.0;

    sizeE.x = 0.5;
    sizeE.y = 0.5;

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;

    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = isAttacking = false;
    isBlocking = false;

    enemyRadius = 0.5;
}

_door::~_door()
{
    //dtor
}

void _door::scroll(float speed)
{
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                posE.x += speed * 20.0; //left
                isDodging = false;
            }
            else{
                posE.x += speed;
            }

            if(lFlag && uFlag && isDodging){
                posE.y -= speed * 20.0; //flip y signs
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                posE.y += speed * 20.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                posE.y -= speed;
            }
            else if(lFlag && dFlag){
                posE.y += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                posE.x -= speed * 20.0;
                isDodging = false;
            }
            else{
                posE.x -= speed;
            }

            if(rFlag && uFlag && isDodging){
                posE.y -= speed * 20.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                posE.y += speed * 20.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                posE.y -= speed;
            }
            else if(rFlag && dFlag){
                posE.y += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                posE.y -= speed * 20.0;
                isDodging = false;
            }
            else{
                posE.y -= speed;
            }

            if(uFlag && lFlag && isDodging){
                posE.x += speed * 20.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                posE.x -= speed * 20.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                posE.x += speed;
            }
            else if(uFlag && rFlag){
                posE.x -= speed;
            }
        }
        else if(dFlag){
            if(dFlag && isDodging){
                posE.y += speed * 20.0;
                isDodging = false;
            }
            else{
                posE.y += speed;
            }

            if(dFlag && lFlag && isDodging){
                posE.x += speed * 20.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                posE.x -= speed * 20.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                posE.x += speed;
            }
            else if(dFlag && rFlag){
                posE.x -= speed;
            }
        }
    }
}


void _door::drawEnms()
{
    if(isAlive){
        glEnable(GL_COLOR_MATERIAL);
        glColor3f(1.0, 1.0, 1.0);

        glBindTexture(GL_TEXTURE_2D, tex);
        glPushMatrix();
            glTranslatef(posE.x, posE.y, posE.z);
            glScalef(sizeE.x, sizeE.y, 1.0);

            glBegin(GL_POLYGON);
                glTexCoord2f(xMax, yMin);
                glVertex3f(1.0, 1.0, posE.z);

                glTexCoord2f(xMin, yMin);
                glVertex3f(-1.0, 1.0, posE.z);

                glTexCoord2f(xMin, yMax);
                glVertex3f(-1.0, -1.0, posE.z);

                glTexCoord2f(xMax, yMax);
                glVertex3f(1.0, -1.0, posE.z);
            glEnd();
        glPopMatrix();
        glDisable(GL_COLOR_MATERIAL);
    }
}

void _door::placeEnms(vec3 inPos)
{
    //Initialization process of enemies
    posE.x = inPos.x;
    posE.y = inPos.y;
    posE.z = inPos.z;

}

