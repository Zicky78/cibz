#include "_enemies.h"

_enemies::_enemies()
{
    //ctor
    posE.x = posE.y = 0.0;
    posE.z = -2.0;

    sizeE.x = 1.0;
    sizeE.y = 1.0;

    rotateE.x = rotateE.y = rotateE.z = 0.0;

    xFrames = 9.0;
    yFrames = 4.0;

    xMin = 3.0/xFrames;
    xMax = 4.0/xFrames;
    yMin = 2.0/yFrames;
    yMax = 3.0/yFrames;

    xSpeed  = 0.00;
    ySpeed  = 0.00;
    xSpeed2 = 0.0;
    ySpeed2 = 0.0;

    actionTrigger = STAND;
    facingDirection = DOWN;
    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = isAttacking = false;
    alreadyHit = false;

    enemyRadius = 0.3;
    detectRadius = 1.5;
}

_enemies::~_enemies()
{
    //dtor
}
void _enemies::drawEnms()
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

void _enemies::placeEnms(vec3 inPos)
{
    //Initialization process of enemies
    posE.x = inPos.x;
    posE.y = inPos.y;
    posE.z = inPos.z;

    eT->startTimer();
    timerRandAct->startTimer();
}

void _enemies::randAction()
{
    if(timerRandAct->getTicks() > 3000){
        randActTrigger = (float)rand()/float(RAND_MAX) * 100.0;
        //cout << "Random Action Trigger: " << randActTrigger << endl;

        if(actionTrigger == STAND){                     //The Enemy is Standing still
            if(randActTrigger < 23){                    //23% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.005;
            }
            else if(randActTrigger < 46){               //23% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.005;
            }
            else if(randActTrigger < 78){               //22% chance to move Up
                actionTrigger = UP;
                facingDirection = UP;
                ySpeed = 0.005;
            }
            else if(randActTrigger < 90){               //22% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.005;
            }
            else if(randActTrigger < 100){              //10% chance to Stand
                actionTrigger = STAND;
            }
        }
        else if(facingDirection == LEFT){               //Enemy facing Left
            if(randActTrigger < 25){                    //25% chance to move Left
                actionTrigger = LEFT;
                facingDirection = LEFT;
                xSpeed = -0.005;
            }
            else if(randActTrigger < 35){               //10% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.005;
            }
            else if(randActTrigger < 60){               //25% chance to move Up
                actionTrigger = UP;
                facingDirection = UP;
                ySpeed = 0.005;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.005;
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
                xSpeed = -0.005;
            }
            else if(randActTrigger < 35){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.005;
            }
            else if(randActTrigger < 60){               //25% chance to move Up
                actionTrigger = UP;
                facingDirection = UP;
                ySpeed = 0.005;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.005;
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
                xSpeed = -0.005;
            }
            else if(randActTrigger < 50){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.005;
            }
            else if(randActTrigger < 75){               //25% chance to move Up
                actionTrigger = UP;
                facingDirection = UP;
                ySpeed = 0.005;
            }
            else if(randActTrigger < 85){               //10% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.005;
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
                xSpeed = -0.005;
            }
            else if(randActTrigger < 50){               //25% chance to move Right
                actionTrigger = RIGHT;
                facingDirection = RIGHT;
                xSpeed = 0.005;
            }
            else if(randActTrigger < 60){               //10% chance to move Up
                actionTrigger = UP;
                facingDirection = UP;
                ySpeed = 0.005;
            }
            else if(randActTrigger < 85){               //25% chance to move Down
                actionTrigger = DOWN;
                facingDirection = DOWN;
                ySpeed = -0.005;
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


void _enemies::actionsEnms()
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
            if(eT->getTicks() > 120 && alreadyHit){
                if(facingDirection == LEFT){
                    if(abs(posE.x) >= abs(posE.y)){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 1.1/yFrames;
                        yMax = 2.0/yFrames;

                        posE.x += 1.0;
                    }
                    else if(posE.y > 0.0){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.0/yFrames;

                        posE.y += 1.0;
                    }
                    else{
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        posE.y -= 1.0;
                    }
                }
                else if(facingDirection == RIGHT){
                    if(abs(posE.x) >= abs(posE.y)){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 2.1/yFrames;
                        yMax = 3.0/yFrames;

                        posE.x -= 1.0;
                    }
                    else if(posE.y > 0.0){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.0/yFrames;

                        posE.y += 1.0;
                    }
                    else{
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        posE.y -= 1.0;
                    }
                }
                else if (facingDirection == UP){
                    if(abs(posE.x) <= abs(posE.y)){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        posE.y -= 1.0;
                    }
                    else if(posE.x > 0.0){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.0/yFrames;

                        posE.x += 1.0;
                    }
                    else{
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        posE.x -= 1.0;
                    }
                }
                else if(facingDirection == DOWN){
                    if(abs(posE.x) <= abs(posE.y)){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.0/yFrames;

                        posE.y += 1.0;
                    }
                    else if(posE.x > 0.0){
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.0/yFrames;

                        posE.x += 1.0;
                    }
                    else{
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        posE.x -= 1.0;
                    }
                }
                alreadyHit = false;
                eT->resetTime();

                enemyHealth -= dmgTaken;
                cout << "Enemy Healt: " << enemyHealth << endl;
                if(enemyHealth <= 0){
                    cout << "Enemy is Dead\n";
                    isAlive = false;
                }
            }
            break;

        case HUNT:                              //The case where the Enemy has Detected the Player
            if(posE.x >= 0.005){                   //If Enemy is to the Right of the Player
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
                facingDirection = LEFT;
                if(posE.x == 0.0){
                    xSpeed = 0.0;
                }
                else
                    xSpeed = -0.005;
            }
            else if(posE.x < -0.005){              //Else Enemy is to the Left of the Player
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
                facingDirection = RIGHT;
                if(posE.x == 0.0){
                    xSpeed = 0.0;
                }
                else
                    xSpeed = 0.005;
            }

            if(posE.y >= 0.005){                   //If Enemy is Above the Player
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
                facingDirection = DOWN;
                if(posE.y == 0.0){
                    ySpeed = 0.0;
                }
                else
                    ySpeed = -0.005;
            }
            else if(posE.y < -0.005){              //If Enemy is Below the Player
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
                facingDirection = UP;
                if(posE.y == 0.0){
                    ySpeed = 0.0;
                }
                else
                    ySpeed = 0.005;
            }
            break;
    }
}

void _enemies::moveCausedByPlayer()                 //Enemy movement based on Player movement
{
    if(facingDirection == LEFT){                      //Enemy moving Left
        //Effect on the X movement
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.515;
            isDodging = false;
            //cout << "LFlag\n";
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.505;
            isDodging = false;
            //cout << "RFlag\n";
        }
        else if(isAttacking){                       //Enemy Hits the Player from Right
            xSpeed2 = 1.0;
            isAttacking = false;
            //cout << "xSpeed2: " << xSpeed2 << endl;
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.01;
            //cout << "LFlag\n";
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.01;
            //cout << "RFlag\n";
        }
        else
            xSpeed2 = 0.0;

        //Effect on the Y movement
        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.505;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.505;
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
        //Effect on the X movement
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.505;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.515;
            isDodging = false;
        }
        else if(isAttacking){                       //Enemy Hit the Player from the Left
            xSpeed2 = -1.0;
            isAttacking = false;
            //cout << "xSpeed2: " << xSpeed2 << endl;
        }
        else if(lFlag){                             //Player moving Left
            xSpeed2 =  0.01;
        }
        else if(rFlag){                             //Player moving Right
            xSpeed2 = -0.01;
        }
        else
            xSpeed2 = 0.0;

        //Effect on the Y movement
        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.505;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.505;
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
        //Effect on the X movement
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.505;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.505;
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

        //Effect on the Y movement
        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.515;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.505;
            isDodging = false;
        }
        else if(isAttacking){                       //Enemy Hits the Player from Below
            ySpeed2 = -1.0;
            isAttacking = false;
            //cout << "ySpeed2: " << ySpeed2 << endl;
        }
        else if(uFlag){                             //Player moving Up
            ySpeed2 = -0.01;
        }
        else if(dFlag){                             //Player moving Down
            ySpeed2 =  0.01;
        }
        else
            ySpeed2 = 0.0;
    }
    else if(facingDirection == DOWN){               //Enemy moving Down
        //Effect on the X movement
        if(lFlag && isDodging){                     //Player moving Left and Dodging
            xSpeed2 =  1.505;
            isDodging = false;
        }
        else if(rFlag && isDodging){                //Player moving Right and Dodging
            xSpeed2 = -1.505;
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

        //Effect on the Y movement
        if(uFlag && isDodging){                     //Player moving Up and Dodging
            ySpeed2 = -1.505;
            isDodging = false;
        }
        else if(dFlag && isDodging){                //Player moving Down and Dodging
            ySpeed2 =  1.515;
            isDodging = false;
        }
        else if(isAttacking){                       //Enemy Hits the Player from Above
            ySpeed2 = 1.0;
            isAttacking = false;
            //cout << "ySpeed2: " << ySpeed2 << endl;
        }
        else if(uFlag){                              //Player moving Up
            ySpeed2 = -0.01;
        }
        else if(dFlag){                         //Player moving Down
            ySpeed2 =  0.01;
        }
        else
            ySpeed2 = 0.0;
    }
}
