#include "_parallax.h"

_parallax::_parallax()
{
    //ctor
    xMax = yMax = 1.0f;
    xMin = yMin = 0.0f;

    plxPos.x = 0.0;
    plxPos.y = 0.0;

    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = false;
    isAttacking = false;
}

_parallax::~_parallax()
{
    //dtor
}

void _parallax::renderBack(float width, float height)                //This renders BackGround
{
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(plxPos.x, plxPos.y, -12.0);

    glBegin(GL_POLYGON);         //Type I want to draw
        //*
        glTexCoord2f(xMin, yMax);
        glVertex3f(-width/height, -1.0, -12.0);              //Bottom Left Vertex. Coordinates x, y, z
        glTexCoord2f(xMax, yMax);
        glVertex3f(width/height, -1.0, -12.0);               //Bottom right Vertex
        glTexCoord2f(xMax, yMin);
        glVertex3f(width/height, 1.0, -12.0);                //Top Right Vertex
        glTexCoord2f(xMin, yMin);
        glVertex3f(-width/height, 1.0, -12.0);               //Top Left Vertex
        //*/

        /*
        glTexCoord2f(xMin, yMax);
        glVertex3f(-width/2.0, -height/2.0, -12.0);              //Bottom Left Vertex. Coordinates x, y, z
        glTexCoord2f(xMax, yMax);
        glVertex3f(width/2.0, -height/2.0, -12.0);               //Bottom right Vertex
        glTexCoord2f(xMax, yMin);
        glVertex3f(width/2.0, height/2.0, -12.0);                //Top Right Vertex
        glTexCoord2f(xMin, yMin);
        glVertex3f(-width/2.0, height/2.0, -12.0);               //Top Left Vertex
        */
    glEnd();

}

void _parallax::parallaxInit(char* fileName)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    plxTexture->loadTexture(fileName);
}

//This is used for Repeatable textures
void _parallax::parallaxInit(char* fileName, float xRepeat, float yRepeat)
{
    xMax = xRepeat;
    yMax = yRepeat;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    plxTexture->loadTexture(fileName);
}

void _parallax::scroll(float speed)
{
    if(!isAttacking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                xMax -= speed * 100.0;
                xMin -= speed * 100.0;
                isDodging = false;
            }
            else{
                xMax -= speed;
                xMin -= speed;
            }

            if(lFlag && uFlag && isDodging){
                yMax -= speed * 100.0;
                yMin -= speed * 100.0;
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                yMax += speed * 100.0;
                yMin += speed * 100.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                yMax -= speed;
                yMin -= speed;
            }
            else if(lFlag && dFlag){
                yMax += speed;
                yMin += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                xMax += speed * 100.0;
                xMin += speed * 100.0;
                isDodging = false;
            }
            else{
                xMax += speed;
                xMin += speed;
            }

            if(rFlag && uFlag && isDodging){
                yMax -= speed * 100.0;
                yMin -= speed * 100.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                yMax += speed * 100.0;
                yMin += speed * 100.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                yMax -= speed;
                yMin -= speed;
            }
            else if(rFlag && dFlag){
                yMax += speed;
                yMin += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                yMax -= speed * 100.0;
                yMin -= speed * 100.0;
                isDodging = false;
            }
            else{
                yMax -= speed;
                yMin -= speed;
            }

            if(uFlag && lFlag && isDodging){
                xMax -= speed * 100.0;
                xMin -= speed * 100.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                xMax += speed * 100.0;
                xMin += speed * 100.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                xMax -= speed;
                xMin -= speed;
            }
            else if(uFlag && rFlag){
                xMax += speed;
                xMin += speed;
            }
        }
        else if(dFlag){
            //uFlag = false;
            if(dFlag && isDodging){
                yMax += speed * 100.0;
                yMin += speed * 100.0;
                isDodging = false;
            }
            else{
                yMax += speed;
                yMin += speed;
            }

            if(dFlag && lFlag && isDodging){
                xMax -= speed * 100.0;
                xMin -= speed * 100.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                xMax += speed * 100.0;
                xMin += speed * 100.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                xMax -= speed;
                xMin -= speed;
            }
            else if(dFlag && rFlag){
                xMax += speed;
                xMin += speed;
            }
        }
    }
}

void _parallax::scroll(bool autoScroll, string dir, float speed)
{
    if(autoScroll){
        if(dir == "up"){
            yMin -= speed;
            yMax -= speed;
        }
        else if(dir == "down"){
            yMin += speed;
            yMax += speed;
        }
        else if(dir == "left"){
            xMin -= speed;
            xMax -= speed;
        }
        else if(dir == "right"){
            xMin += speed;
            xMax += speed;
        }

    }
}
