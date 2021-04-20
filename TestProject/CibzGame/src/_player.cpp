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
    playerPos.z = -1.0;

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

    radiusPlayer = vert[1].x + vert[2].x;
}

void _player::drawPlayer()
{
    glTranslatef(playerPos.x, playerPos.y, playerPos.z);
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
            }
            else if(facingDirection == RIGHT){
                //Frame for Right Downward motion
                //Column 3, Row 4
                xMin = 3.5/xFrames;
                xMax = 2.6/xFrames;
            }
            else if(facingDirection == UP){
                //Frame for Up Downward motion
                //Column 3, Row 2
                xMin = 4.97/xFrames;
                xMax = 6.1/xFrames;
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
            }

            /*
            if(playerPos.y <= yFloor){
                isDodging = true;
                playerScale.z = 1.0;
            }
            else if(playerPos.y > yFloor){
                playerPos.y -= 0.02;
                if(facingDirection == LEFT){
                    //Frame for Left Downward motion
                    //Column 3, Row 3
                    xMin = 2.6/xFrames;
                    xMax = 3.5/xFrames;
                    yMin = 0.0/yFrames;
                    yMax = 1.0/yFrames;
                    playerPos.x -= 0.02;
                }
                else if(facingDirection == RIGHT){
                    //Frame for Right Downward motion
                    //Column 3, Row 4
                    xMin = 4.0/xFrames;
                    xMax = 3.0/xFrames;
                    yMin = 0.0/yFrames;
                    yMax = 1.0/yFrames;
                    playerPos.x += 0.02;
                }
                else if(facingDirection == UP){
                    //Frame for Up Downward motion
                    //Column 3, Row 2
                    xMin = 6.0/xFrames;
                    xMax = 7.0/xFrames;
                    yMin = 0.0/yFrames;
                    yMax = 1.0/yFrames;
                    //playerPos.x += 0.02;
                }
                else if(facingDirection == DOWN){
                    //Frame for Down Downward motion
                    //Column 3, Row 1
                    xMin = 0.0/xFrames;
                    xMax = 1.0/xFrames;
                    yMin = 0.0/yFrames;
                    yMax = 1.0/yFrames;
                    //playerPos.x += 0.02;
                }

            }
            /*
            if(playerPos.y > yFloor)
                playerPos.y -= 0.05;
            //*/
            break;

        //*
        //Walking animation using 2 frames
        case LWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
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
                /*
                //playerPos.x -= 0.02;                      //Leftward movement

                if(lFlag && dFlag){
                    //playerPos.y -= 0.02;                  // + Downward movement = Down Diagonal movement to the Left
                }
                else if(lFlag && rFlag){
                    //playerPos.x += 0.02;                  // + Right movement = NO movement

                }
                else if(lFlag && uFlag){
                    //playerPos.y += 0.02;                  // + Upward movement = Up Diagonal movement to the Left

                }
                */
            }
            break;

        case RWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
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
                /*
                //playerPos.x += 0.02;                      //Rightward movement

                if(rFlag && dFlag){
                    //playerPos.y -= 0.02;                  // + Downward movement = Down Diagonal movement to the Right
                }
                else if(rFlag && lFlag){
                    //playerPos.x -= 0.02;                  // + Leftward movement = NO movement

                }
                else if(rFlag && uFlag){
                    //playerPos.y += 0.02;                  // + Upward movement = Up Diagonal movement to the Right

                }
                */
            }
            break;

        case UWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 1.0/yFrames;
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
                /*
                //playerPos.y += 0.02;                      //Upward movement

                if(uFlag && dFlag){
                    //playerPos.y -= 0.02;                  // + Downward movement = NO movement
                }
                else if(uFlag && lFlag){
                    //playerPos.x -= 0.02;                  // + Leftward movement = Up Diagonal movement to the Left
                }
                else if(uFlag && rFlag){
                    //playerPos.x += 0.02;                  // + Rightward movement = Up Diagonal movement to the Right

                }
                */
            }
            break;

        case DWALK:
            if(!isAttacking){
                yMin = 0.0/yFrames;
                yMax = 0.96/yFrames;
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
                /*
                //playerPos.y -= 0.02;                      //Downward movement

                if(dFlag && uFlag){
                    //playerPos.y += 0.02;                  // + Upward movement = NO movement
                }
                else if(dFlag && lFlag){
                    //playerPos.x -= 0.02;                  // + Leftward movement = Down Diagonal movement to the Left

                }
                else if(dFlag && rFlag){
                    //playerPos.x += 0.02;                  // + Rightward movement = Down Diagonal movement to the Right

                }
                */
            }
            break;
        //*/

        /*
        //Walking animation using 3 frames
        case LWALK:
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;
            //6th column, 1st row frame
            if(xMax < 4.4/xFrames && xMin > 3.4/xFrames){
                xMin = 4.1/xFrames;
                xMax = 5.0/xFrames;
            }
            //5th column, 1st row frame
            else if(xMax < 3.6/xFrames && xMin > 2.5/xFrames){
                xMin = 3.5/xFrames;
                xMax = 4.2/xFrames;
            }

            //4th column, 1st row frame
            else{
                xMin = 2.6/xFrames;
                xMax = 3.5/xFrames;
            }
            break;

        case RWALK:
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;
            //6th column, 1st row frame Mirrored
            if(xMax > 3.4/xFrames && xMin < 4.4/xFrames){
                xMin = 5.0/xFrames;
                xMax = 4.1/xFrames;
            }
            //5th column, 1st row frame Mirrored
            else if(xMax > 2.5/xFrames && xMin < 3.6/xFrames){
                xMin = 4.2/xFrames;
                xMax = 3.5/xFrames;
            }

            //4th column, 1st row frame Mirrored
            else{
                xMin = 3.5/xFrames;
                xMax = 2.6/xFrames;
            }
            //cout << "walking\n";
            break;

        case UWALK:
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;
            //9th column, 1st row frame
            if(xMax < 6.99/xFrames && xMin > 6.02/xFrames){
                xMin = 6.85/xFrames;
                xMax = 7.85/xFrames;

            }
            //8th column, 1st row frame
            else if(xMax < 6.2/xFrames && xMin > 4.95/xFrames){
                xMin = 6.03/xFrames;
                xMax = 6.98/xFrames;
            }
            //7th column, 1st row frame
            else{
                xMin = 4.96/xFrames;
                xMax = 5.91/xFrames;
                //xMax = 6.1/xFrames;
            }
            break;

        case DWALK:
            yMin = 0.0/yFrames;
            yMax = 0.96/yFrames;
            //3rd column, 1st row frame
            if(xMax < 1.89/xFrames && xMin > 0.93/xFrames){
                xMin = 1.88/xFrames;
                xMax = 2.78/xFrames;
            }
            //2nd column, 1st row frame
            else if(xMax < 1.1/xFrames && xMin > -1.0/xFrames){
                xMin = 0.94/xFrames;
                xMax = 1.88/xFrames;
            }
            //1st column, 1st row frame
            else{
                xMin = 0.0/xFrames;
                xMax = 1.0/xFrames;
            }
            break;
        //*/

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
                    }
                    //1st column, second row frame
                    else{
                        xMin = 1.82/xFrames;
                        xMax = 2.75/xFrames;
                        yMin = 0.88/yFrames;
                        yMax = 1.8/yFrames;
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

            break;

        case HATK:
            switch(facingDirection)
            {
                case LEFT:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 5.09/xFrames && xMin > 4.22/xFrames){
                        //6th column, 3rd row frame
                        xMin = 5.0/xFrames;
                        xMax = 6.0/xFrames;

                        if(lFlag){
                            actionTrigger = LWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    else if(xMax < 4.24/xFrames && xMin > 3.22/xFrames){
                        //5th column, 2rd row frame
                        xMin = 4.23/xFrames;
                        xMax = 5.08/xFrames;
                    }
                    else{
                        //4th column, 3rd row frame
                        xMin = 3.23/xFrames;
                        xMax = 4.23/xFrames;
                    }
                    break;

                case RIGHT:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax > 4.22/xFrames && xMin < 5.09/xFrames){
                        //6th column, 3rd row frame MIRRORED
                        xMin = 6.0/xFrames;
                        xMax = 5.0/xFrames;

                        if(rFlag){
                            actionTrigger = RWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    else if(xMax > 3.22/xFrames && xMin < 4.24/xFrames){
                        //5th column, 2rd row frame MIRRORED
                        xMin = 5.08/xFrames;
                        xMax = 4.23/xFrames;
                    }
                    else{
                        //4th column, 3rd row frame MIRRORED
                        xMin = 4.23/xFrames;
                        xMax = 3.23/xFrames;
                    }
                    break;

                case UP:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 7.73/xFrames && xMin > 6.82/xFrames){
                        //9th column, 3rd row frame
                        xMin = 7.65/xFrames;
                        xMax = 8.85/xFrames;

                        if(uFlag){
                            actionTrigger = UWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    else if(xMax < 6.89/xFrames && xMin > 5.87/xFrames){
                        //8th column, 2rd row frame
                        xMin = 6.83/xFrames;
                        xMax = 7.72/xFrames;
                    }
                    else{
                        //7th column, 3rd row frame
                        xMin = 5.88/xFrames;
                        xMax = 6.88/xFrames;
                    }
                    break;

                case DOWN:
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    if(xMax < 1.88/xFrames && xMin > 0.9/xFrames){
                        //3rd column, 3rd row frame
                        xMin = 1.87/xFrames;
                        xMax = 3.2/xFrames;

                        if(dFlag){
                            actionTrigger = DWALK;
                        }
                        else
                            actionTrigger = STAND;
                        //isAttacking = false;
                    }
                    else if(xMax < 1.1/xFrames && xMin > -0.1/xFrames){
                        //2nd column, 2rd row frame
                        xMin = 1.0/xFrames;
                        xMax = 1.87/xFrames;
                    }
                    else{
                        //1st column, 3rd row frame
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                    }
                    break;
            }
            break;

        case DODGE:

            switch(facingDirection)
            {
                case LEFT:
                    xMin = 5.0/xFrames;
                    xMax = 6.0/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    //playerPos.x = playerPos.x - 0.15;                      //Leftward movement

                    /*
                    if(lFlag && rFlag){                                   //If both Left and Right Flag true then NO movement
                        playerPos.x = playerPos.x + 0.15;                  // Leftward + Right movement = NO movement
                    }
                    else */
                    if(lFlag && dFlag){
                        //playerPos.y = playerPos.y - 0.15;                  // Leftward + Downward movement = Down Diagonal movement to the Left
                        actionTrigger = LWALK;
                    }
                    else if(lFlag && uFlag){
                        //playerPos.y = playerPos.y + 0.15;                  // Leftward + Upward movement = Up Diagonal movement to the Left
                        actionTrigger = LWALK;
                    }
                    else if(lFlag){
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

                    //playerPos.x = playerPos.x + 0.15;                      //Right movement

                    /*
                    if(rFlag && lFlag){                                   //If both Right and Left Flag true then NO movement
                        playerPos.x = playerPos.x - 0.15;                  // Rightward + Leftward movement = NO movement
                    }
                    else */
                    if(rFlag && dFlag){
                        //playerPos.y = playerPos.y - 0.15;                  // Rightward + Downward movement = Down Diagonal movement to the Right
                        actionTrigger = RWALK;
                    }
                    else if(rFlag && uFlag){
                        //playerPos.y = playerPos.y + 0.15;                  // Rightward + Upward movement = Up Diagonal movement to the Right
                        actionTrigger = RWALK;
                    }
                    else if(rFlag){
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

                    //playerPos.y = playerPos.y + 0.15;                      //Upward movement

                    /*
                    if(uFlag && dFlag){                                   //If both Up and Down Flag true then NO movement
                        playerPos.y = playerPos.y - 0.15;                  // Upward + Downward movement = NO movement
                    }
                    else */
                    if(uFlag && lFlag){
                        //playerPos.x = playerPos.x - 0.15;                  // Upward + Leftward movement = Up Diagonal movement to the Left
                        actionTrigger = UWALK;
                    }
                    else if(uFlag && rFlag){
                        //playerPos.x = playerPos.x + 0.15;                  // Upward + Rightward movement = Up Diagonal movement to the Right
                        actionTrigger = UWALK;
                    }
                    else if(uFlag){
                        actionTrigger = UWALK;
                    }
                    else
                        actionTrigger = STAND;
                    break;

                case DOWN:
                    //3rd column, 3rd row frame
                    xMin = 1.87/xFrames;
                    xMax = 3.2/xFrames;
                    yMin = 2.0/yFrames;
                    yMax = 3.0/yFrames;

                    //playerPos.y = playerPos.y - 0.15;                      //Downward movement

                    /*
                    if(dFlag && uFlag){                                   //If both Up and Down Flag true then NO movement
                        playerPos.y = playerPos.y + 0.15;                  // Downward + Upward movement = NO movement
                    }
                    else */
                    if(dFlag && lFlag){
                        //playerPos.x = playerPos.x - 0.15;                  // Downward + Leftward movement = Down Diagonal movement to the Left
                        actionTrigger = DWALK;
                    }
                    else if(dFlag && rFlag){
                        //playerPos.x = playerPos.x + 0.15;                  // Downward + Rightward movement = Down Diagonal movement to the Right
                        actionTrigger = DWALK;
                    }
                    else if(dFlag){
                        actionTrigger = DWALK;
                    }
                    else
                        actionTrigger = STAND;
                    /*
                    //1st column, 3rd row frame
                    if(dodgePos.y - playerPos.y == 0.1){
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                    }
                    else{
                        if(dodgePos.y < playerPos.y){
                            //3rd column, 3rd row frame
                            xMin = 1.87/xFrames;
                            xMax = 3.2/xFrames;
                            yMin = 2.0/yFrames;
                            yMax = 3.0/yFrames;
                            playerPos.y -= 0.05;
                        }
                        else{
                            isDodging = false;
                            actionTrigger = STAND;
                        }

                    }
                    */
                    break;
            }
            break;
    }

}
