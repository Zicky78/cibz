//#include "_glScene.h"
#include "_door.h"


_door::_door()
{
    //ctor
    posE.x = posE.y = 0.0;
    posE.z = -12.0;

    sizeE.x = 1.0;
    sizeE.y = 1.0;

    rotateE.x = rotateE.y = rotateE.z = 0.0;

    xFrames = 9.0;
    yFrames = 4.0;

    xMin = 0.0;
    xMax = 1.0;
    yMin = 0.0;
    yMax = 1.0;

    xSpeed  = 0.00;
    ySpeed  = 0.00;
    xSpeed2 = 0.0;
    ySpeed2 = 0.0;

    actionTrigger = STAND;
    facingDirection = DOWN;
    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = isAttacking = false;
    isBlocking = false;

    enemyRadius = 2.0;
    detectRadius = 4.0;
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
                posE.x += speed * 20.0;     //200.0; //left
                isDodging = false;
            }
            else{
                posE.x += speed;
            }

            if(lFlag && uFlag && isDodging){
                posE.y -= speed * 20.0;     //200.0; //flip y signs
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                posE.y += speed * 20.0;     //200.0;
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
                posE.x -= speed * 20.0;     //200.0;
                isDodging = false;
            }
            else{
                posE.x -= speed;
            }

            if(rFlag && uFlag && isDodging){
                posE.y -= speed * 20.0;     //200.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                posE.y += speed * 20.0;     //200.0;
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
                posE.y -= speed * 20.0;     //200.0;
                isDodging = false;
            }
            else{
                posE.y -= speed;
            }

            if(uFlag && lFlag && isDodging){
                posE.x += speed * 20.0;     //200.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                posE.x -= speed * 20.0;     //200.0;
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
            //uFlag = false;
            if(dFlag && isDodging){
                posE.y += speed * 20.0;     //200.0;
                isDodging = false;
            }
            else{
                posE.y += speed;
            }

            if(dFlag && lFlag && isDodging){
                posE.x += speed * 20.0;     //200.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                posE.x -= speed * 20.0;     //200.0;
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
            //glRotatef(rotateE.x, 1.0, 0.0, 0.0);
            //glRotatef(rotateE.y, 0.0, 1.0, 0.0);
            //glRotatef(rotateE.z, 0.0, 0.0, 1.0);
            glScalef(sizeE.x, sizeE.y, 1.0);

            glBegin(GL_POLYGON);
                glTexCoord2f(xMax, yMin);
                glVertex3f(1.0, 1.0, -2.0);

                glTexCoord2f(xMin, yMin);
                glVertex3f(-1.0, 1.0, -2.0);

                glTexCoord2f(xMin, yMax);
                glVertex3f(-1.0, -1.0, -2.0);

                glTexCoord2f(xMax, yMax);
                glVertex3f(1.0, -1.0, -2.0);
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

    eT->startTimer();
    timerRandAct->startTimer();
}

void _door::randAction()
{
    if(timerRandAct->getTicks() > 3000){
        randActTrigger = (float)rand()/float(RAND_MAX) * 100.0;

        if(actionTrigger == STAND){                     //The Enemy is Standing still
            if(randActTrigger < 23){                    //23% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.004;
            }
            else if(randActTrigger < 46){               //23% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.004;
            }
            else if(randActTrigger < 78){               //22% chance to move Up
                actionTrigger == UP;
                facingDirection == UP;
                ySpeed = 0.004;
            }
            else if(randActTrigger < 90){               //22% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.004;
            }
            else if(randActTrigger < 100){              //10% chance to Stand
                actionTrigger = STAND;
            }
        }
        else if(facingDirection == LEFT){               //Enemy facing Left
            if(randActTrigger < 25){                    //25% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.004;
            }
            else if(randActTrigger < 35){               //10% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.004;
            }
            else if(randActTrigger < 60){               //25% chance to move Up
                actionTrigger == UP;
                facingDirection == UP;
                ySpeed = 0.004;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.004;
            }
            else if(randActTrigger < 100){              //15% chance to Stand
                actionTrigger = STAND;
                xSpeed = 0.0;
                ySpeed = 0.0;
            }
        }
        else if(facingDirection == RIGHT){              //Enemy facing Right
            if(randActTrigger < 10){                    //10% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.004;
            }
            else if(randActTrigger < 35){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.004;
            }
            else if(randActTrigger < 60){               //25% chance to move Up
                actionTrigger == UP;
                facingDirection == UP;
                ySpeed = 0.004;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.004;
            }
            else if(randActTrigger < 100){              //15% chance to Stand
                actionTrigger = STAND;
                xSpeed = 0.0;
                ySpeed = 0.0;
            }
        }
        else if(facingDirection == UP){                 //Enemy facing Up
            if(randActTrigger < 25){                    //25% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.004;
            }
            else if(randActTrigger < 50){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.004;
            }
            else if(randActTrigger < 75){               //25% chance to move Up
                actionTrigger == UP;
                facingDirection == UP;
                ySpeed = 0.004;
            }
            else if(randActTrigger < 85){               //10% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.004;
            }
            else if(randActTrigger < 100){              //15% chance to Stand
                actionTrigger = STAND;
                xSpeed = 0.0;
                ySpeed = 0.0;
            }
        }
        else if(facingDirection == DOWN){               //Enemy facing Down
            if(randActTrigger < 25){                    //25% chance to Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.004;
            }
            else if(randActTrigger < 50){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.004;
            }
            else if(randActTrigger < 60){               //10% chance to move Up
                actionTrigger == UP;
                facingDirection == UP;
                ySpeed = 0.004;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.004;
            }
            else if(randActTrigger < 100){              //15% chance to Stand
                actionTrigger = STAND;
                xSpeed = 0.0;
                ySpeed = 0.0;
            }
        }
        timerRandAct->resetTime();
    }
}


void _door::actionsEnms()
{
    switch(actionTrigger){
        case STAND:
            if(facingDirection == LEFT){
                xMin = 4.0/xFrames;
                xMax = 5.0/xFrames;
                yMin = 1.1/yFrames;
                yMax = 2.0/yFrames;
            }
            else if(facingDirection == RIGHT){
                xMin = 4.0/xFrames;
                xMax = 5.0/xFrames;
                yMin = 2.1/yFrames;
                yMax = 3.0/yFrames;
            }
            else if (facingDirection == UP){
                xMin = 4.0/xFrames;
                xMax = 5.0/xFrames;
                yMin = 3.1/yFrames;
                yMax = 4.0/yFrames;
            }
            else if(facingDirection == DOWN){
                xMin = 4.0/xFrames;
                xMax = 5.0/xFrames;
                yMin = 0.1/yFrames;
                yMax = 1.0/yFrames;
            }
            eT->resetTime();
            break;

        case LEFT:
            if(eT->getTicks() > 120){
                if(xMin > 5.0/xFrames){
                    xMin = 3.0/xFrames;
                    xMax = 4.0/xFrames;
                }
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                yMin = 1.1/yFrames;
                yMax = 2.0/yFrames;

                eT->resetTime();
            }
            break;

        case RIGHT:
            if(eT->getTicks() > 120){
                if(xMin > 5.0/xFrames){
                    xMin = 3.0/xFrames;
                    xMax = 4.0/xFrames;
                }
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                yMin = 2.1/yFrames;
                yMax = 3.0/yFrames;

                eT->resetTime();
            }
            break;

        case UP:
            if(eT->getTicks() > 120){
                if(xMin > 5.0/xFrames){
                    xMin = 3.0/xFrames;
                    xMax = 4.0/xFrames;
                }
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                yMin = 3.1/yFrames;
                yMax = 4.0/yFrames;

                eT->resetTime();
            }
            break;

        case DOWN:
            if(eT->getTicks() > 120){
                if(xMin > 5.0/xFrames){
                    xMin = 3.0/xFrames;
                    xMax = 4.0/xFrames;
                }
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                yMin = 0.1/yFrames;
                yMax = 1.0/yFrames;

                eT->resetTime();
            }
            break;
        case HIT:
            if(eT->getTicks() > 120){
                if(facingDirection == LEFT){
                    if(abs(posE.x) >= abs(posE.y)){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 1.1/yFrames;
                        yMax = 2.0/yFrames;

                        posE.x += 1.0;
                    }
 //                   else if()
                    /*
                    else if(posE.x < 0.0 && abs(posE.) < 0.5){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 1.1/yFrames;
                        yMax = 2.0/yFrames;

                        posE.x -= 1.0;
                    }
                    */
                }
                else if(facingDirection == RIGHT){
                    xMin = 4.0/xFrames;
                    xMax = 5.0/xFrames;
                    yMin = 2.1/yFrames;
                    yMax = 3.0/yFrames;
                }
                else if (facingDirection == UP){
                    xMin = 4.0/xFrames;
                    xMax = 5.0/xFrames;
                    yMin = 3.1/yFrames;
                    yMax = 4.0/yFrames;
                }
                else if(facingDirection == DOWN){
                    xMin = 4.0/xFrames;
                    xMax = 5.0/xFrames;
                    yMin = 0.1/yFrames;
                    yMax = 1.0/yFrames;
                }
                eT->resetTime();
            }
            break;
    }

}

void _door::moveCausedByPlayer()                 //Enemy movement based on Player movement
{
    if(facingDirection == LEFT){                      //Enemy moving Left
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.013;
            isDodging = false;
            //cout << "LFlag\n";
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.005;
            isDodging = false;
            //cout << "RFlag\n";
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.009;
            //cout << "LFlag\n";
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.009;
            //cout << "RFlag\n";
        }
        else
            xSpeed2 = 0.0;

        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.005;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.005;
            isDodging = false;
        }
        else if(uFlag){                             //Player moving Up
            ySpeed2 = -0.005;
        }
        else if(dFlag){                             //Player moving Down
            ySpeed2 =  0.005;
        }
        else
            ySpeed2 = 0.0;
    }
    else if(facingDirection == RIGHT){                //Enemy moving Right
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.005;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.013;
            isDodging = false;
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.009;
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.009;
        }
        else
            xSpeed2 = 0.0;

        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.005;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.005;
            isDodging = false;
        }
        else if(uFlag){                             //Player moving Up
            ySpeed2 = -0.005;
        }
        else if(dFlag){                             //Player moving Down
            ySpeed2 =  0.005;
        }
        else
            ySpeed2 = 0.0;
    }
    else if(facingDirection == UP){                   //Enemy moving Up
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.005;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.005;
            isDodging = false;
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.005;
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.005;
        }
        else
            xSpeed2 = 0.0;

        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.013;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.005;
            isDodging = false;
        }
        else if(uFlag){                             //Player moving Up
            ySpeed2 = -0.009;
        }
        else if(dFlag){                             //Player moving Down
            ySpeed2 =  0.009;
        }
        else
            ySpeed2 = 0.0;
    }
    else if(facingDirection == DOWN){
        //Enemy moving Down
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.005;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.005;
            isDodging = false;
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.005;
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.005;
        }
        else
            xSpeed2 = 0.0;

        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.005;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.013;
            isDodging = false;
        }
        else if(uFlag){                              //Player moving Up
            ySpeed2 = -0.009;
        }
        else if(dFlag){                         //Player moving Down
            ySpeed2 =  0.009;
        }
        else
            ySpeed2 = 0.0;
    }
}
