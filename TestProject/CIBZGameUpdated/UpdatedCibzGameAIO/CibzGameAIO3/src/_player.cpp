#include "_player.h"

_player::_player()
{
    //ctor
    vert[0].x = -1.0; vert[0].y = -1.0; vert[0].z = -4.0;
    vert[1].x =  1.0; vert[1].y = -1.0; vert[1].z = -4.0;
    vert[2].x =  1.0; vert[2].y =  1.0; vert[2].z = -4.0;
    vert[3].x = -1.0; vert[3].y =  1.0; vert[3].z = -4.0;
}

_player::~_player()
{
    //dtor
}
void _player::playerInit(float X, float Y)
{
    playerPos.x = 0.0;
    playerPos.y = 0.0;
    playerPos.z = -4.0;

    dodgePos.x = playerPos.x;
    dodgePos.y = playerPos.y;

    //yFloor = playerPos.y;
    isDodging = false;
    isAttacking = false;
    //onGround = false;
    uFlag = dFlag = rFlag = lFlag = false;

    facingDirection = DOWN;
    //compTrigger = STAND;
    //prevTrigger = STAND;

    playerScale.x = 0.5;
    playerScale.y = 0.5;
    playerScale.z = 1.0;

    playerRot.x = 0.0;
    playerRot.y = 0.0;
    playerRot.z = 0.0;

    xFrames = X;
    yFrames = Y;

    xMin = 0.0;
    xMax = 1.0/xFrames;
    yMin = 0.0/yFrames;
    yMax = 0.96/yFrames;

    radiusPlayer = 0.3;
    atkRadius = 0.6;
    health = 10;
    lightDmg = 1;
    HeavyDmg = 2;
    speedMulti = 1.0;
    slowed = 1.0;
    invulnerable = false;
    plyTimer->startTimer();
    slowedTimer->startTimer();
}

void _player::drawPlayer()
{
    //glTranslatef(playerPos.x, playerPos.y, playerPos.z);
    glScalef(playerScale.x, playerScale.y, playerScale.z);
    glRotatef(playerRot.z, 0.0, 0.0, 1.0);

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

void _player::actions()
{
    switch(actionTrigger){
        case STAND:
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;
            if(facingDirection == LEFT){
                //Frame for Left Downward motion
                //Column 3, Row 3
                xMin = 2.6/xFrames;
                xMax = 3.5/xFrames;

                //knight3
                //xMin = 3.0/xFrames;
                //xMax = 4.0/xFrames;
            }
            else if(facingDirection == RIGHT){
                //Frame for Right Downward motion
                //Column 3, Row 4
                xMin = 3.5/xFrames;
                xMax = 2.6/xFrames;

                //knight3
                //xMin = 4.0/xFrames;
                //xMax = 3.0/xFrames;
            }
            else if(facingDirection == UP){
                //Frame for Up Downward motion
                //Column 3, Row 2
                xMin = 4.97/xFrames;
                xMax = 6.1/xFrames;

                //knight3
                //xMin = 6.0/xFrames;
                //xMax = 7.0/xFrames;
            }
            else if(facingDirection == DOWN){
                //Frame for Down Downward motion
                //*
                //Column 3, Row 1
                xMin = 0.0/xFrames;
                xMax = 1.0/xFrames;
                yMin = 0.0/yFrames;
                yMax = 0.96/yFrames;
                //*/

                //knight3
                //xMin = 0.0/xFrames;
                //xMax = 1.0/xFrames;
            }
            break;

        //*
        //Walking animation using 2 frames
        case LWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
                //*
                //6th frame
                if(xMax < 4.4/xFrames && xMin > 3.4/xFrames){
                    xMin = 4.1/xFrames;
                    xMax = 5.0/xFrames;
                }
                //5th frame
                else{
                    xMin = 3.5/xFrames;
                    xMax = 4.2/xFrames;
                }
                //*/

                /*
                //knight3
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                if(xMin > 4.1/xFrames){
                    xMin = 3.0/xFrames;
                    xMax = 4.0/xFrames;
                }
                */
            }
            break;

        case RWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
                //*
                //6th frame
                if(xMax > 3.4/xFrames && xMin < 4.4/xFrames){
                    xMin = 5.0/xFrames;
                    xMax = 4.1/xFrames;
                }
                //5th frame
                else{
                    xMin = 4.2/xFrames;
                    xMax = 3.5/xFrames;
                }
                //*/

                /*
                //knight3
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                if(xMax > 4.1/xFrames){
                    xMin = 4.0/xFrames;
                    xMax = 3.0/xFrames;
                }
                */
            }
            break;

        case UWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
                //*
                //9th frame
                if(xMax < 6.99/xFrames && xMin > 6.02/xFrames){
                    xMin = 6.85/xFrames;
                    xMax = 7.85/xFrames;
                }
                //8th frame
                else{
                    xMin = 6.03/xFrames;
                    xMax = 6.98/xFrames;
                }
                //*/

                /*
                //knight3
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                if(xMin > 8.1/xFrames){
                    xMin = 7.0/xFrames;
                    xMax = 8.0/xFrames;
                }
                */
            }
            break;

        case DWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 0.96/yFrames;
                //*
                //3rd frame
                if(xMax < 1.89/xFrames && xMin > 0.93/xFrames){
                    xMin = 1.88/xFrames;
                    xMax = 2.78/xFrames;
                }
                //2nd frame
                else{
                    xMin = 0.94/xFrames;
                    xMax = 1.88/xFrames;
                }
                //*/

                /*
                //knight3
                xMin += 1.0/xFrames;
                xMax += 1.0/xFrames;
                if(xMin > 2.1/xFrames){
                    xMin = 1.0/xFrames;
                    xMax = 2.0/xFrames;
                }
                */
            }
            break;

        case ATK:
            switch(facingDirection)
            {
                case LEFT:
                    //2nd column, second row frame
                    if(xMax < 2.76/xFrames){
                        xMin = 2.59/xFrames;
                        xMax = 3.70/xFrames;
                        yMin = 1.14/yFrames;
                        yMax = 2.06/yFrames;

                        if(lFlag){
                            actionTrigger = LWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                        //cout << "Light Last Frame: " << plyTimer->getTicks() << endl;
                    }
                    //1st column, second row frame
                    else{
                        xMin = 1.82/xFrames;
                        xMax = 2.75/xFrames;
                        yMin = 0.88/yFrames;
                        yMax = 1.8/yFrames;

                        //cout << "Light 1st Frame: " << plyTimer->getTicks() << endl;
                    }
                    break;

                case RIGHT:
                    //2nd column, second row frame Mirrored
                    if(xMin < 2.76/xFrames){
                        xMin = 3.70/xFrames;
                        xMax = 2.59/xFrames;
                        yMin = 1.14/yFrames;
                        yMax = 2.06/yFrames;

                        if(rFlag){
                            actionTrigger = RWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    //1st column, second row frame Mirrored
                    else{
                        xMin = 2.75/xFrames;
                        xMax = 1.82/xFrames;
                        yMin = 0.88/yFrames;
                        yMax = 1.8/yFrames;
                    }
                    break;

                case UP:
                    //2nd column, second row frame Mirrored
                    if(xMax < 4.34/xFrames){
                        xMin = 4.21/xFrames;
                        xMax = 5.21/xFrames;
                        yMin = 1.08/yFrames;
                        yMax = 2.06/yFrames;

                        if(uFlag){
                            actionTrigger = UWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    //1st column, second row frame Mirrored
                    else{
                        xMin = 3.51/xFrames;
                        xMax = 4.33/xFrames;
                        yMin = 1.14/yFrames;
                        yMax = 2.08/yFrames;
                    }
                    break;

                case DOWN:
                    //2nd column, second row frame
                    if(xMax < 0.83/xFrames){
                        xMin = 0.82/xFrames;
                        xMax = 1.82/xFrames;
                        yMin = 1.14/yFrames;
                        yMax = 2.05/yFrames;

                        if(dFlag){
                            actionTrigger = DWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    //1st column, second row frame
                    else{
                        xMin = 0.0/xFrames;
                        xMax = 0.82/xFrames;
                        yMin = 0.88/yFrames;
                        yMax = 1.8/yFrames;

                    }
                    break;
            }
            plyTimer->resetTime();
            break;

        case HATK:
            switch(facingDirection)
            {
                case LEFT:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 5.09/xFrames && xMin > 4.22/xFrames && plyTimer->getTicks() > 60){
                        //6th column, 3rd row frame
                        xMin = 5.0/xFrames;
                        xMax = 6.0/xFrames;

                        if(lFlag){
                            actionTrigger = LWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                        //cout << "Heavy Last Frame: " << plyTimer->getTicks() << endl;
                        plyTimer->resetTime();
                    }
                    else if(xMax < 4.24/xFrames && xMin > 3.22/xFrames && plyTimer->getTicks() > 60){
                        //5th column, 2rd row frame
                        xMin = 4.23/xFrames;
                        xMax = 5.08/xFrames;

                        //cout << "Heavy 2nd Frame: " << plyTimer->getTicks() << endl;
                        plyTimer->resetTime();
                    }
                    else if(plyTimer->getTicks() > 60){
                        //4th column, 3rd row frame
                        xMin = 3.23/xFrames;
                        xMax = 4.23/xFrames;

                        //cout << "Heavy 1st Frames: " << plyTimer->getTicks() << endl;
                        plyTimer->resetTime();
                    }
                    break;

                case RIGHT:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax > 4.22/xFrames && xMin < 5.09/xFrames && plyTimer->getTicks() > 60){
                        //6th column, 3rd row frame MIRRORED
                        xMin = 6.0/xFrames;
                        xMax = 5.0/xFrames;

                        if(rFlag){
                            actionTrigger = RWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                        plyTimer->resetTime();
                    }
                    else if(xMax > 3.22/xFrames && xMin < 4.24/xFrames && plyTimer->getTicks() > 60){
                        //5th column, 2rd row frame MIRRORED
                        xMin = 5.08/xFrames;
                        xMax = 4.23/xFrames;

                        plyTimer->getTicks();
                    }
                    else if(plyTimer->getTicks() > 60){
                        //4th column, 3rd row frame MIRRORED
                        xMin = 4.23/xFrames;
                        xMax = 3.23/xFrames;

                        plyTimer->getTicks();
                    }
                    break;

                case UP:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 7.73/xFrames && xMin > 6.82/xFrames && plyTimer->getTicks() > 60){
                        //9th column, 3rd row frame
                        xMin = 7.65/xFrames;
                        xMax = 8.85/xFrames;

                        if(uFlag){
                            actionTrigger = UWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                        plyTimer->resetTime();
                    }
                    else if(xMax < 6.89/xFrames && xMin > 5.87/xFrames && plyTimer->getTicks() > 60){
                        //8th column, 2rd row frame
                        xMin = 6.83/xFrames;
                        xMax = 7.72/xFrames;

                        plyTimer->resetTime();
                    }
                    else if(plyTimer->getTicks() > 60){
                        //7th column, 3rd row frame
                        xMin = 5.88/xFrames;
                        xMax = 6.88/xFrames;
                        plyTimer->resetTime();
                    }
                    break;

                case DOWN:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 1.88/xFrames && xMin > 0.9/xFrames && plyTimer->getTicks() > 60){
                        //3rd column, 3rd row frame
                        xMin = 1.87/xFrames;
                        xMax = 3.2/xFrames;

                        if(dFlag){
                            actionTrigger = DWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                        plyTimer->resetTime();
                    }
                    else if(xMax < 1.1/xFrames && xMin > -0.1/xFrames && plyTimer->getTicks() > 60){
                        //2nd column, 2rd row frame
                        xMin = 1.0/xFrames;
                        xMax = 1.87/xFrames;
                        plyTimer->resetTime();
                    }
                    else if(plyTimer->getTicks() > 60){
                        //1st column, 3rd row frame
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        plyTimer->resetTime();
                    }
                    break;
            }
            plyTimer->resetTime();
            break;

        case DODGE:
            switch(facingDirection)
            {
                case LEFT:
                    if(plyTimer->getTicks() > 800){
                        //cout << "Player Setting dodgingLimit to True\n";
                        dodgingLimit = true;
                    }

                    xMin = 5.0/xFrames;
                    xMax = 6.0/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(lFlag){
                        actionTrigger = LWALK;
                    }
                    else
                        actionTrigger = STAND;

                    break;

                case RIGHT:
                    if(plyTimer->getTicks() > 800){
                        //cout << "Player Setting dodgingLimit to True\n";
                        dodgingLimit = true;
                    }

                    xMin = 6.0/xFrames;
                    xMax = 5.0/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(rFlag){
                        actionTrigger = RWALK;
                    }
                    else
                        actionTrigger = STAND;
                    break;

                case UP:
                    if(plyTimer->getTicks() > 800){
                        //cout << "Player Setting dodgingLimit to True\n";
                        dodgingLimit = true;
                    }

                    xMin = 7.65/xFrames;
                    xMax = 8.85/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(uFlag){
                        actionTrigger = UWALK;
                    }
                    else
                        actionTrigger = STAND;
                    break;

                case DOWN:
                    if(plyTimer->getTicks() > 800){
                        //cout << "Player Setting dodgingLimit to True\n";
                        dodgingLimit = true;
                    }

                    //3rd column, 3rd row frame
                    xMin = 1.87/xFrames;
                    xMax = 3.2/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(dFlag){
                        actionTrigger = DWALK;
                    }
                    else
                        actionTrigger = STAND;
                    break;
            }
            break;


        case HIT:
            if(!invulnerable){
                switch(facingDirection){
                    case LEFT:
                        xMin = 5.0/xFrames;
                        xMax = 6.0/xFrames;
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;

                        if(lFlag){
                            actionTrigger = LWALK;
                        }
                        else
                            actionTrigger = STAND;
                        break;

                    case RIGHT:
                        xMin = 6.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;

                        if(rFlag){
                            actionTrigger = RWALK;
                        }
                        else
                            actionTrigger = STAND;
                        break;

                    case UP:
                        xMin = 7.65/xFrames;
                        xMax = 8.85/xFrames;
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;

                        if(uFlag){
                            actionTrigger = UWALK;
                        }
                        else
                            actionTrigger = STAND;
                        break;

                    case DOWN:
                        xMin = 1.87/xFrames;
                        xMax = 3.2/xFrames;
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;

                        if(dFlag){
                            actionTrigger = DWALK;
                        }
                        else
                            actionTrigger = STAND;
                        break;


                }
                cout << "Player got hit\n";
                health--;
                cout << "Player health: " << health << endl;
                invulnerable = true;
                plyTimer->resetTime();
                plySnd->playSounds("sounds/damage.mp3");

                //if()
            }
            //Hit Break
            break;

        case BLOCK:
            if(!isAttacking && isBlocking){
                //invulnerable = true;
                switch(facingDirection)
                {
                    case LEFT:
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                        if(xMax < 4.24/xFrames && xMin > 3.22/xFrames && plyTimer->getTicks() > 60){
                            //5th column, 3rd row frame
                            xMin = 4.23/xFrames;
                            xMax = 5.08/xFrames;

                            //cout << "Heavy 2nd Frame: " << plyTimer->getTicks() << endl;
                            plyTimer->resetTime();
                        }
                        else if(plyTimer->getTicks() > 60){
                            //4th column, 3rd row frame
                            xMin = 3.23/xFrames;
                            xMax = 4.23/xFrames;
                        }
                        break;

                    case RIGHT:
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                        if(xMax > 3.22/xFrames && xMin < 4.24/xFrames && plyTimer->getTicks() > 60){
                            //5th column, 3rd row frame MIRRORED
                            xMin = 5.08/xFrames;
                            xMax = 4.23/xFrames;
                            plyTimer->resetTime();
                        }
                        else if(plyTimer->getTicks() > 60){
                            //4th column, 3rd row frame MIRRORED
                            xMin = 4.23/xFrames;
                            xMax = 3.23/xFrames;
                            plyTimer->resetTime();
                        }
                        break;

                    case UP:
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                        if(xMax < 6.89/xFrames && xMin > 5.87/xFrames && plyTimer->getTicks() > 60){
                        //8th column, 3rd row frame
                            xMin = 6.83/xFrames;
                            xMax = 7.72/xFrames;
                        }
                        else if(plyTimer->getTicks() > 60){
                            //7th column, 3rd row frame
                            xMin = 5.88/xFrames;
                            xMax = 6.88/xFrames;
                            plyTimer->resetTime();
                        }
                        break;

                    case DOWN:
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                        if(xMax < 1.1/xFrames && xMin > -0.1/xFrames && plyTimer->getTicks() > 60){
                            //2nd column, 3rd row frame
                            xMin = 1.0/xFrames;
                            xMax = 1.87/xFrames;
                            plyTimer->resetTime();
                        }
                        else if(plyTimer->getTicks() > 60){
                            //1st column, 3rd row frame
                            xMin = 0.0/xFrames;
                            xMax = 1.0/xFrames;
                            plyTimer->resetTime();
                        }
                        break;
                }
            }
            else
                actionTrigger = STAND;
            break;
    }
    if(plyTimer->getTicks() > 300){
        invulnerable = false;
        isAttacking = false;
    }

    if(slowedTimer->getTicks() > 840){
        slowed = 1.0;
        slowedTimer->resetTime();
    }
}
