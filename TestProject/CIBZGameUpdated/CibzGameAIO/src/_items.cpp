#include "_items.h"

_items::_items()
{
    //ctor

    vert[0].x = -1.0; vert[0].y = -1.0; vert[0].z = -3.9;
    vert[1].x =  1.0; vert[1].y = -1.0; vert[1].z = -3.9;
    vert[2].x =  1.0; vert[2].y =  1.0; vert[2].z = -3.9;
    vert[3].x = -1.0; vert[3].y =  1.0; vert[3].z = -3.9;


}

_items::~_items()
{
    //dtor

}

void _items::itemInit(float xFrames, float yFrames)
{
    xMin = 0.0;
    xMax = 1.0/xFrames;
    yMin = 0.0;
    yMax = 1.0/yFrames;

    itemPos.x = rand() % 5;
    itemPos.y = rand() % 5;
    //itemPos.x = 1.0;
    //itemPos.y = 1.0;
    itemPos.z = -3.9;

    itemScale.x = itemScale.y = itemScale.z = 0.15;
    itemRot.x = itemRot.y = itemRot.z = 0.0;

    itemRadius = 0.1;

    notPickedUp = true;

    itemType = rand() % 3;
    //itemType = 2;

    iT->startTimer();

    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = false;
    isAttacking = false;
}



void _items::drawItem()
{
    glTranslatef(itemPos.x, itemPos.y, itemPos.z);
    glScalef(itemScale.x, itemScale.y, itemScale.z);
    glRotatef(itemRot.x, 1.0, 0.0, 0.0);
    glRotatef(itemRot.y, 0.0, 1.0, 0.0);
    glRotatef(itemRot.z, 0.0, 0.0, 1.0);

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

void _items::itemScroll(float speed)
{
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                itemPos.x += speed * 200.0;
                isDodging = false;
            }
            else{
                itemPos.x += speed;
            }

            if(lFlag && uFlag && isDodging){
                itemPos.y -= speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                itemPos.y += speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                itemPos.y -= speed;
            }
            else if(lFlag && dFlag){
                itemPos.y += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                itemPos.x -= speed * 200.0;
                isDodging = false;
            }
            else{
                itemPos.x -= speed;
            }

            if(rFlag && uFlag && isDodging){
                itemPos.y -= speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                itemPos.y += speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                itemPos.y -= speed;
            }
            else if(rFlag && dFlag){
                itemPos.y += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                itemPos.y -= speed * 200.0;
                isDodging = false;
            }
            else{
                itemPos.y -= speed;
            }

            if(uFlag && lFlag && isDodging){
                itemPos.x += speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                itemPos.x -= speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                itemPos.x += speed;
            }
            else if(uFlag && rFlag){
                itemPos.x -= speed;
            }
        }
        else if(dFlag){
            //uFlag = false;
            if(dFlag && isDodging){
                itemPos.y += speed * 200.0;
                isDodging = false;
            }
            else{
                itemPos.y += speed;
            }

            if(dFlag && lFlag && isDodging){
                itemPos.x += speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                itemPos.x -= speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                itemPos.x += speed;
            }
            else if(dFlag && rFlag){
                itemPos.x -= speed;
            }
        }
    }
}

