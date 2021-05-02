#include "_enemies.h"

_enemies::_enemies()
{
    //ctor
    posE.x = posE.y = 0.0;
    posE.z = -2.0;

    sizeE.x = 0.1;
    sizeE.y = 0.1;

    rotateE.x = rotateE.y = rotateE.z = 0.0;

    //xFrames = 9.0;
    //yFrames = 4.0;

    //xMin = 3.0/xFrames;
    //xMax = 4.0/xFrames;
    //yMin = 2.0/yFrames;
    //yMax = 3.0/yFrames;

    xSpeed  = 0.00;
    ySpeed  = 0.00;
    xSpeed2 = 0.0;
    ySpeed2 = 0.0;

    actionTrigger = STAND;
    facingDirection = DOWN;
    lFlag = rFlag = uFlag = dFlag = false;
    isDodging = isAttacking = false;
    alreadyHit = false;
    charged = atkRange = false;
    shouted = deaf = isCalled = false;                  //Bools for shouting enemy to attract
    summonCap = 0;


    //enemyHealth = 3;
    //enemyRadius = 0.3;
    //detectRadius = 1.5;
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

void _enemies::summonEnms(float xSpwnPos, float ySpwnPos)
{
    string fileName;
    char ID;
    float xFrm, yFrm;
    //vec3 tempPos;
    _texture* tempTex = new _texture();

    int ranVal;
    srand(time(NULL));
    ranVal = rand() % 100;

    if(ranVal < 25){                    //25% chance to move Left
        tempTex->loadTexture("images/zombie_n_skeleton2.png");
        ID = 's';
        xFrm = 9.0;
        yFrm = 4.0;
        cout << "Skeleton\n";
    }
    else if(ranVal < 50){               //25% chance to move Right
        tempTex->loadTexture("images/mage.png");
        ID = 'm';
        xFrm = 6.0;
        yFrm = 4.0;
        cout << "Mage\n";
    }
    else if(ranVal < 75){               //25% chance to move Up
        tempTex->loadTexture("images/wolf4.png");
        ID = 'w';
        xFrm = 5.0;
        yFrm = 13.0;
        cout << "Wolf\n";
    }
    else if(ranVal < 100){               //25% chance to move Down
        tempTex->loadTexture("images/alarmEnemy.png");
        ID = 'z';
        xFrm = 9.0;
        yFrm = 4.0;
        cout << "Alarm\n";
    }


    tex = tempTex->tex;
    enmsInit(ID, xFrm, yFrm);

    posE.x = xSpwnPos;
    posE.y = ySpwnPos;

    sizeE.x = sizeE.y = 0.3;
}

void _enemies::enmsInit(char ID, float xFrm, float yFrm)
{
    id = ID;
    xFrames = xFrm;
    yFrames = yFrm;

    switch(id)
    {
        case 'f':                   //Fairy Enemy, xFrames should be 6.0, yFrames should be 5.0
            xMin = 0.0/xFrames;
            xMax = 1.0/xFrames;
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;

            enemyHealth = 3;
            enemyRadius = 0.3;
            detectRadius = 3.0;
            summonCap = 0;
            break;

        case 'm':                   //Mage enemy, xFrames should be 6.0, yFrames should be 4.0
            xMin = 0.0/xFrames;
            xMax = 1.0/xFrames;
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;

            enemyHealth = 3;
            enemyRadius = 0.3;
            detectRadius = 3.0;
            break;

        case 'o':                   //Ogre enemy, xFrames should be 9.0, yFrames should be 4.0
            xMin = 0.0/xFrames;
            xMax = 1.0/xFrames;
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;

            enemyHealth = 10;
            enemyRadius = 0.3;
            detectRadius = 1.5;
            atkRadius = 1.5;
            break;

        case 's':                   //Green Skeleton Enemy, xFrames should be 9.0, yFrames should be 4.0
            xMin = 3.0/xFrames;
            xMax = 4.0/xFrames;
            yMin = 2.0/yFrames;
            yMax = 3.0/yFrames;

            enemyHealth = 3;
            enemyRadius = 0.3;
            detectRadius = 1.5;
            break;

        case 'w':                   //Wolf Enemy, xFrames should be 5.0, yFrames should 13.0
            xMin = 0.0/xFrames;
            xMax = 1.0/xFrames;
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;

            enemyHealth = 5;
            enemyRadius = 0.3;
            detectRadius = 1.5;
            break;

        case 'z':                   //Mouth Enemy, xFrames should be 9.0, yFrames should be 4.0
            xMin = 0.0/xFrames;
            xMax = 1.0/xFrames;
            yMin = 0.0/yFrames;
            yMax = 1.0/yFrames;

            enemyHealth = 3;
            enemyRadius = 0.3;
            detectRadius = 2.0;
            break;


    }
}


void _enemies::randAction()
{
    deaf = false;
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
                switch(id)
                {
                    case 'f':                   //Fairy Enemy
                        if(eT->getTicks() > 120){
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 0.0/yFrames;
                            yMax = 1.0/yFrames;

                            if(xMin > 3.0/xFrames){
                                xMin = 2.0/xFrames;
                                xMax = 3.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        break;

                    case 'm':                   //Mage Enemy
                        xMin = 0.9/xFrames;
                        xMax = 1.9/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 'o':                   //Ogre Enemy
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 's':                   //Green Skeleton Enemy
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 1.1/yFrames;
                        yMax = 2.0/yFrames;
                        break;

                    case 'w':                   //Wolf Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 5.1/yFrames;
                        yMax = 6.1/yFrames;

                        break;

                    case 'z':                   //MouthEnemy
                        xMin = 2.8/xFrames;
                        xMax = 3.8/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;
                }
            }
            else if(facingDirection == RIGHT){
                switch(id)
                {
                    case 'f':                   //Fairy Enemy
                        if(eT->getTicks() > 120){
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 0.0/yFrames;
                            yMax = 1.0/yFrames;

                            if(xMax > 3.0/xFrames){
                                xMin = 3.0/xFrames;
                                xMax = 2.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        break;

                    case 'm':                   //Mage Enemy
                        xMin = 1.9/xFrames;
                        xMax = 0.9/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 'o':                   //Ogre Enemy
                        xMin = 5.0/xFrames;
                        xMax = 4.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 's':                   //Green Skeleton Enemy
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 2.1/yFrames;
                        yMax = 3.0/yFrames;
                        break;

                    case 'w':                   //Wolf Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 7.25/yFrames;
                        yMax = 8.25/yFrames;

                        break;

                    case 'z':                   //Mouth Enemy
                        xMin = 3.8/xFrames;
                        xMax = 2.8/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;
                }
            }
            else if (facingDirection == UP){
                switch(id)
                {
                    case 'f':                   //Fairy Enemy
                        if(eT->getTicks() > 120){
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 0.0/yFrames;
                            yMax = 1.0/yFrames;

                            if(xMin > 5.0/xFrames){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        break;

                    case 'm':                   //Mage Enemy
                        xMin = 2.0/xFrames;
                        xMax = 3.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 'o':                   //Ogre Enemy
                        xMin = 6.0/xFrames;
                        xMax = 7.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 's':                   //Green Skeleton Enemy
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;
                        break;

                    case 'w':                   //Wolf Enemy
                        yMin = 3.15/yFrames;
                        yMax = 4.15/yFrames;

                        if(xMin < 0.1){
                            xMin = 1.0/xFrames;
                            xMax = 2.0/xFrames;
                        }
                        else{
                            xMin = 0.0/xFrames;
                            xMax = 1.0/xFrames;
                        }

                        break;

                    case 'z':                   //Mouth Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;
                }
            }
            else if(facingDirection == DOWN){
                switch(id)
                {
                    case 'f':                   //Fairy Enemy
                        if(eT->getTicks() > 120){
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 0.0/yFrames;
                            yMax = 1.0/yFrames;

                            if(xMin > 1.0/xFrames){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        break;

                    case 'm':                   //Mage Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 'o':                   //Ogre Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 's':                   //Green Skeleton Enemy
                        xMin = 4.0/xFrames;
                        xMax = 5.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;

                    case 'w':                   //Wolf Enemy
                        xMin = 0.0/xFrames;
                        xMax = 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        break;

                    case 'z':                   //Mouth Enemy
                        xMin = 6.0/xFrames;
                        xMax = 7.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;
                        break;
                }
            }
            eT->resetTime();
            //Stand's Break
            break;

        case LEFT:
            switch(id)
            {
                case 'f':                   //Fairy Enemy
                    if(eT->getTicks() > 180){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 3.0/xFrames){
                            xMin = 2.0/xFrames;
                            xMax = 3.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'm':                   //Mage Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 3.0/xFrames){
                            xMin = 2.0/xFrames;
                            xMax = 3.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'o':                   //Ogre Enemy
                    if(eT->getTicks() > 240){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 5.1/xFrames){
                            xMin = 4.0/xFrames;
                            xMax = 5.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 's':                   //Green Skeleton Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.1/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 5.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 4.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'w':                   //Wolf Enemy
                    if(eT->getTicks() > 180){               //Walking Animation
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 5.1/yFrames;
                        yMax = 6.1/yFrames;

                        if(xMin > 4.0/xFrames){
                            xMin = 1.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'z':                   //Mouth Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 5.0/xFrames || xMin < 2.7/xFrames){
                            xMin = 2.8/xFrames;
                            xMax = 3.8/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;
            }
            //Left's Break
            break;

        case RIGHT:
            switch(id)
            {
                case 'f':                   //Fairy Enemy
                    if(eT->getTicks() > 180){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMax > 3.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'm':                   //Mage Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMax > 3.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'o':                   //Ogre Enemy
                    if(eT->getTicks() > 240){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMax > 5.1/xFrames){
                            xMin = 5.0/xFrames;
                            xMax = 4.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 's':                   //Green Skeleton Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 2.1/yFrames;
                        yMax = 3.0/yFrames;

                        if(xMin > 5.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 4.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'w':                   //Wolf Enemy
                    if(eT->getTicks() > 180){               //Walking Animation
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 7.2/yFrames;
                        yMax = 8.2/yFrames;

                        if(xMin > 4.0/xFrames){
                            xMin = 1.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'z':                   //Mouth Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMax > 5.0/xFrames || xMax < 2.7/xFrames){
                            xMin = 3.8/xFrames;
                            xMax = 2.8/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;
            }
            //Right's Break
            break;

        case UP:
            switch(id)
            {
                case 'f':                   //Fairy Enemy
                    if(eT->getTicks() > 180){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 4.9/xFrames){
                            xMin = 3.9/xFrames;
                            xMax = 4.9/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'm':                   //Mage Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 4.9/xFrames){
                            xMin = 3.9/xFrames;
                            xMax = 4.9/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'o':                   //Ogre Enemy
                    if(eT->getTicks() > 240){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 8.1/xFrames){
                            xMin = 7.0/xFrames;
                            xMax = 8.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 's':                   //Green Skeleton Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 3.1/yFrames;
                        yMax = 4.0/yFrames;

                        if(xMin > 5.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 4.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'w':                   //Wolf Enemy
                    if(eT->getTicks() > 180){               //Walking Animation
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 3.15/yFrames;
                        yMax = 4.15/yFrames;

                        if(xMin > 4.0/xFrames){
                            xMin = 2.0/xFrames;
                            xMax = 3.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'z':                   //Mouth Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 8.0/xFrames || xMin < 5.9/xFrames){
                            xMin = 6.0/xFrames;
                            xMax = 7.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;
            }
            //Up's Break
            break;

        case DOWN:
            switch(id)
            {
                case 'f':                   //Fairy Enemy
                    if(eT->getTicks() > 180){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 1.0/yFrames;
                        yMax = 2.0/yFrames;

                        if(xMin > 1.1/xFrames){
                            xMin = 0.0/xFrames;
                            xMax = 1.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'm':                   //Mage Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.9/yFrames;
                        yMax = 1.9/yFrames;

                        if(xMin > 1.0/xFrames){
                            xMin = -0.1/xFrames;
                            xMax = 0.9/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'o':                   //Ogre Enemy
                    if(eT->getTicks() > 240){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 2.1/xFrames){
                            xMin = 1.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 's':                   //Green Skeleton Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.1/yFrames;
                        yMax = 1.1/yFrames;

                        if(xMin > 5.0/xFrames){
                            xMin = 3.0/xFrames;
                            xMax = 4.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;

                case 'w':                   //Wolf Enemy
                    if(eT->getTicks() > 180){               //Walking Animation
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 2.0/xFrames){
                            xMin = 1.0/xFrames;
                            xMax = 2.0/xFrames;
                        }

                        eT->resetTime();
                    }

                case 'z':                   //Mouth Enemy
                    if(eT->getTicks() > 120){
                        xMin += 1.0/xFrames;
                        xMax += 1.0/xFrames;
                        yMin = 0.0/yFrames;
                        yMax = 1.0/yFrames;

                        if(xMin > 2.0/xFrames){
                            xMin = 0.0/xFrames;
                            xMax = 1.0/xFrames;
                        }

                        eT->resetTime();
                    }
                    break;
            }
            //Down's Break
            break;
        case HIT:
            if(eT->getTicks() > 240 && alreadyHit){
                switch(id)
                {
                    case 'f':                                           //Fairy Enemy
                        if(facingDirection == LEFT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if(facingDirection == RIGHT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if (facingDirection == UP){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        else if(facingDirection == DOWN){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        break;

                    case 'm':                                           //Mage Enemy
                        if(facingDirection == LEFT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if(facingDirection == RIGHT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if (facingDirection == UP){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        else if(facingDirection == DOWN){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        break;

                    case 'o':                                           //Ogre Enemy
                        if(facingDirection == LEFT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if(facingDirection == RIGHT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else{
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                        }
                        else if (facingDirection == UP){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y += 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        else if(facingDirection == DOWN){
                            if(abs(posE.x) <= abs(posE.y)){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(posE.x >= 0.0){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }
                                else{
                                    xMin = 1.0/xFrames;
                                    xMax = 0.0/xFrames;
                                }

                                posE.y -= 1.0;
                            }
                            else if(posE.x > 0.0){
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;
                                xMin = 1.0/xFrames;
                                xMax = 0.0/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        break;

                    case 's':                                           //Skeleton Enemy
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
                        break;

                    case 'w':                                           //Wolf Enemy
                        if(facingDirection == LEFT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 6.15/yFrames;
                                yMax = 7.15/yFrames;

                                posE.x += 1.0;
                            }
                            else if(posE.y > 0.0){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 12.1/yFrames;
                                yMax = 13.1/yFrames;

                                posE.y += 1.0;
                            }
                            else{
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 4.1/yFrames;
                                yMax = 5.1/yFrames;

                                posE.y -= 1.0;
                            }
                        }
                        else if(facingDirection == RIGHT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 8.25/yFrames;
                                yMax = 9.25/yFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 12.1/yFrames;
                                yMax = 13.1/yFrames;

                                posE.y += 1.0;
                            }
                            else{
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 4.1/yFrames;
                                yMax = 5.1/yFrames;

                                posE.y -= 1.0;
                            }
                        }
                        else if (facingDirection == UP){
                            if(abs(posE.x) <= abs(posE.y)){
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 4.1/yFrames;
                                yMax = 5.1/yFrames;

                                posE.y -= 1.0;
                            }
                            else if(posE.x > 0.0){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 6.15/yFrames;
                                yMax = 7.15/yFrames;

                                posE.x += 1.0;
                            }
                            else{
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 8.25/yFrames;
                                yMax = 9.25/yFrames;

                                posE.x -= 1.0;
                            }
                        }
                        else if(facingDirection == DOWN){
                            if(abs(posE.x) <= abs(posE.y)){
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 4.1/yFrames;
                                yMax = 5.1/yFrames;

                                posE.y += 1.0;
                            }
                            else if(posE.x > 0.0){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 6.15/yFrames;
                                yMax = 7.15/yFrames;

                                posE.x += 1.0;
                            }
                            else{
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 8.25/yFrames;
                                yMax = 9.25/yFrames;

                                posE.x -= 1.0;
                            }
                        }
                        break;

                    case 'z':                                           //Mouth Enemy
                        yMin = 2.0/yFrames;
                        yMax = 3.0/yFrames;
                        if(facingDirection == LEFT){
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 2.9/xFrames;
                                xMax = 1.9/xFrames;

                                posE.x -= 1.0;
                            }
                            else if(posE.y > 0.0){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.y += 1.0;
                            }
                            else{
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;

                                posE.y -= 1.0;
                            }
                        }
                        else if(facingDirection == RIGHT){
                            //yMin = 2.0/yFrames;
                            //yMax = 3.0/yFrames;
                            if(abs(posE.x) >= abs(posE.y)){
                                xMin = 1.9/xFrames;
                                xMax = 2.9/xFrames;

                                posE.x += 1.0;
                            }
                            else if(posE.y > 0.0){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.y += 1.0;
                            }
                            else{
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;

                                posE.y -= 1.0;
                            }
                        }
                        else if (facingDirection == UP){
                            //yMin = 2.0/yFrames;
                            //yMax = 3.0/yFrames;
                            if(abs(posE.x) <= abs(posE.y)){
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;

                                posE.y += 1.0;
                            }
                            else if(posE.x > 0.0){
                                xMin = 1.9/xFrames;
                                xMax = 2.9/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                xMin = 2.9/xFrames;
                                xMax = 1.9/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        else if(facingDirection == DOWN){
                            //yMin = 2.0/yFrames;
                            //yMax = 3.0/yFrames;
                            if(abs(posE.x) <= abs(posE.y)){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;

                                posE.y -= 1.0;
                            }
                            else if(posE.x > 0.0){
                                xMin = 1.9/xFrames;
                                xMax = 2.9/xFrames;

                                posE.x += 1.0;
                            }
                            else{
                                xMin = 2.9/xFrames;
                                xMax = 1.9/xFrames;

                                posE.x -= 1.0;
                            }
                        }
                        break;
                }

                alreadyHit = false;
                eT->resetTime();

                enemyHealth -= dmgTaken;
                //cout << "Enemy Healt: " << enemyHealth << endl;
                if(enemyHealth <= 0){
                    //cout << "Enemy is Dead\n";
                    isAlive = false;
                }
            }
            //Hit's Break
            break;

        case HUNT:                              //The case where the Enemy has Detected the Player
            //deaf = true;
            switch(id)                          //Deaf so that it enemies already aggro on player won't be affected by shout
            {
                case 'f':                       //Fairy Enemy
                    if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0))) < 2.5 && !(sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 2.0)){
                        xSpeed = 0.0;
                        ySpeed = 0.0;
                        atkRange = true;

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?
                            if(abs(posE.x) >= abs(posE.y)){                     //If Enemy is closer to the X axis then the Y axis
                                if(posE.x >= 0.0){                              //If Enemy is to the Right of the Player, use Left Aniamation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 3.0/xFrames;
                                        xMax = 4.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        if(summonCap < 5)
                                            summonCap++;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 2.0/xFrames;
                                        xMax = 3.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = true;
                                    }
                                }
                                else{                                           //If Enemy is to the Left of the Player, use Right Animation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 4.0/xFrames;
                                        xMax = 3.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        if(summonCap < 5)
                                            summonCap++;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 3.0/xFrames;
                                        xMax = 2.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = true;
                                    }
                                }

                            }
                            else if(posE.y >= 0.0){                             //If Enemy is closer to the Y axis then check if the Enemy is Above the Player, use Down Animation
                                if(charged){
                                        //Firing Shot
                                        xMin = 1.0/xFrames;
                                        xMax = 2.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        if(summonCap < 5)
                                            summonCap++;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 0.0/xFrames;
                                        xMax = 1.0/xFrames;
                                        yMin = 4.0/yFrames;
                                        yMax = 5.0/yFrames;
                                        charged = true;
                                    }
                            }
                            else{                                               //If Enemy is Below the Player, use Up Animation
                                if(charged){
                                    //Firing Shot
                                    calledPos.x = 0.0;
                                    calledPos.y = 0.0;
                                    xMin = 5.0/xFrames;
                                    xMax = 6.0/xFrames;
                                    yMin = 4.0/yFrames;
                                    yMax = 5.0/yFrames;
                                    charged = false;
                                    shouted = true;
                                    if(summonCap < 5)
                                        summonCap++;
                                }
                                else{
                                    //Charging Shot
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                    yMin = 4.0/yFrames;
                                    yMax = 5.0/yFrames;
                                    charged = true;
                                }
                            }

                            timerRandAct->resetTime();
                        }
                    }
                    else if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 1.9999)){                //If the Player is too close
                        atkRange = false;
                        if(posE.x >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 180){                   //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.004;
                        }
                        else if(posE.x < 0.0){              //Will move away from Player if too close
                            if(eT->getTicks() > 180){                   //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.004;
                        }

                        if(posE.y >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 180){                   //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.004;
                        }
                        else if(posE.y < 0.0){         //Will move away from Player if too close
                            if(eT->getTicks() > 180){                   //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.004;
                        }

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?

                            timerRandAct->resetTime();
                        }
                    }
                    else{                                       //Is between 3.0 and 2.5 and will walk closer to the Player, until within 2.5 to 2.0 range
                        atkRange = false;
                        if(posE.x >= 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 180){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;

                                if(yMax > 4.0/yFrames || yMin < 3.0/yFrames || xMax > 4.0/xFrames || xMin < 2.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.004;
                        }
                        else if(posE.x < -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 180){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;

                                if(yMax > 4.0/yFrames || yMin < 3.0/yFrames || xMin > 4.0/xFrames || xMax < 2.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.004;
                        }

                        if(posE.y >= 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 180){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;

                                if(yMax > 2.0/yFrames || yMin < 1.0/yFrames || xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.004;
                        }
                        else if(posE.y < -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 180){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;

                                if(yMax > 4.0/yFrames || yMin < 3.0/yFrames || xMax > 6.0/xFrames || xMin < 4.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.004;
                        }
                    }
                    break;

                case 'm':                       //Mage Enemy
                    if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0))) < 2.5 && !(sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 2.0)){
                        xSpeed = 0.0;
                        ySpeed = 0.0;
                        atkRange = true;

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?
                            if(abs(posE.x) >= abs(posE.y)){                     //If Enemy is closer to the X axis then the Y axis
                                if(posE.x >= 0.0){                              //If Enemy is to the Right of the Player, use Left Aniamation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 2.8/xFrames;
                                        xMax = 3.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 1.8/xFrames;
                                        xMax = 2.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                                }
                                else{                                           //If Enemy is to the Left of the Player, use Right Animation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 3.8/xFrames;
                                        xMax = 2.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 2.8/xFrames;
                                        xMax = 1.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                                }

                            }
                            else if(posE.y >= 0.0){                             //If Enemy is closer to the Y axis then check if the Enemy is Above the Player, use Down Animation
                                if(charged){
                                        //Firing Shot
                                        xMin = 1.0/xFrames;
                                        xMax = 1.9/xFrames;
                                        yMin = 2.9/yFrames;
                                        yMax = 3.9/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 0.0/xFrames;
                                        xMax = 0.9/xFrames;
                                        yMin = 2.9/yFrames;
                                        yMax = 3.9/yFrames;
                                        charged = true;
                                    }
                            }
                            else{                                               //If Enemy is Below the Player, use Up Animation
                                if(charged){
                                    //Firing Shot
                                    xMin = 4.9/xFrames;
                                    xMax = 5.9/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = false;
                                    shouted = true;
                                }
                                else{
                                    //Charging Shot
                                    xMin = 3.9/xFrames;
                                    xMax = 4.9/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = true;
                                }
                            }

                            timerRandAct->resetTime();
                        }
                    }
                    else if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 1.999)){
                        atkRange = false;
                        if(posE.x >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }
                        else if(posE.x < 0.0){              //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }

                        if(posE.y >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                        else if(posE.y < 0.0){         //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?

                            timerRandAct->resetTime();
                        }
                    }
                    else{                                       //Is between 2.0 and 1.5 and will walk closer to the Player, until within 1.5 to 1.4 range
                        atkRange = false;
                        if(posE.x >= 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }
                        else if(posE.x < -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }

                        if(posE.y >= 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }
                        else if(posE.y < -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                    }
                    break;

                case 'o':                       //Ogre Enemy
                    //STILL WORKING ON THIS, CURRENTLY OGRE ONLY PHYSICALLY COLLIDES WITH PLAYER
                    /*
                    if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0))) < atkRadius ){
                        xSpeed = 0.0;
                        ySpeed = 0.0;
                        atkRange = true;

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?
                            if(abs(posE.x) >= abs(posE.y)){                     //If Enemy is closer to the X axis then the Y axis
                                if(posE.x >= 0.0){                              //If Enemy is to the Right of the Player, use Left Aniamation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 2.8/xFrames;
                                        xMax = 3.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 2.0/xFrames;
                                        xMax = 3.0/xFrames;
                                        yMin = 2.0/yFrames;
                                        yMax = 3.0/yFrames;

                                        if(eT->getTicks() > 3000){
                                            charged = true;

                                            eT->resetTime();
                                        }
                                    }
                                }
                                else{                                           //If Enemy is to the Left of the Player, use Right Animation
                                    if(charged){
                                        //Firing Shot
                                        xMin = 3.8/xFrames;
                                        xMax = 2.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 2.8/xFrames;
                                        xMax = 1.8/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                                }

                            }
                            else if(posE.y >= 0.0){                             //If Enemy is closer to the Y axis then check if the Enemy is Above the Player, use Down Animation
                                if(charged){
                                        //Firing Shot
                                        xMin = 1.0/xFrames;
                                        xMax = 1.9/xFrames;
                                        yMin = 2.9/yFrames;
                                        yMax = 3.9/yFrames;
                                        charged = false;
                                        shouted = true;
                                    }
                                    else{
                                        //Charging Shot
                                        xMin = 0.0/xFrames;
                                        xMax = 0.9/xFrames;
                                        yMin = 2.9/yFrames;
                                        yMax = 3.9/yFrames;
                                        charged = true;
                                    }
                            }
                            else{                                               //If Enemy is Below the Player, use Up Animation
                                if(charged){
                                    //Firing Shot
                                    xMin = 4.9/xFrames;
                                    xMax = 5.9/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = false;
                                    shouted = true;
                                }
                                else{
                                    //Charging Shot
                                    xMin = 3.9/xFrames;
                                    xMax = 4.9/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = true;
                                }
                            }

                            timerRandAct->resetTime();
                        }
                    }
                    else if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 1.9999)){
                        atkRange = false;
                        if(posE.x >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }
                        else if(posE.x < 0.0){              //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }

                        if(posE.y >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                        else if(posE.y < 0.0){         //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Firing Particle?

                            timerRandAct->resetTime();
                        }
                    }
                    else{                                       //Is between 2.0 and 1.5 and will walk closer to the Player, until within 1.5 to 1.4 range
                        atkRange = false;
                        if(posE.x >= 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }
                        else if(posE.x < -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }

                        if(posE.y >= 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }
                        else if(posE.y < -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                    }


                    if(atkRange && eT->getTicks() > 60 && !charged){            //Enemy is winding up
                        xSpeed = 0.0;
                        ySpeed = 0.0;

                        switch(facingDirection)
                        {
                            case LEFT:

                                break;

                            case RIGHT:
                                xMin = 3.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(eT->getTicks() > 3000){
                                    charged = true;

                                    eT->resetTime();
                                }
                                break;

                            case UP:
                                xMin = 4.0/xFrames;
                                xMax = 5.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(eT->getTicks() > 3000){
                                    charged = true;

                                    eT->resetTime();
                                }
                                break;

                            case DOWN:
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;

                                if(eT->getTicks() > 3000){
                                    charged = true;

                                    eT->resetTime();
                                }
                                break;
                        }
                    }
                    else if(atkRange && eT->getTicks() > 60 && charged){            //Enemy is Attacking
                        xSpeed = 0.0;
                        ySpeed = 0.0;
                        switch(facingDirection)
                        {
                            case LEFT:
                                xMin = 3.0/xFrames;
                                xMax = 4.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                charged = false;

                                eT->resetTime();
                                break;

                            case RIGHT:
                                xMin = 4.0/xFrames;
                                xMax = 3.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                charged = false;

                                eT->resetTime();
                                break;

                            case UP:
                                xMin = 5.0/xFrames;
                                xMax = 6.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                charged = false;

                                eT->resetTime();
                                break;

                            case DOWN:
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                                yMin = 2.0/yFrames;
                                yMax = 3.0/yFrames;
                                charged = false;

                                eT->resetTime();
                                break;
                        }
                    }
                    else
                    if(eT->getTicks() > 240){
                        atkRange = false;
                        charged = false;

                    */
                        if(posE.x < 0.012 && posE.x > -0.012){      //Enemy within an acceptable X range, will no longer move the X axis
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= 0.012){                   //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 240){               //Enemy moves to the Left, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 4.1/xFrames){
                                    xMin = 2.1/xFrames;
                                    xMax = 3.1/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.008;
                        }
                        else if(posE.x <= -0.012){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 240){           //Enemy moves to the Right, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMax > 4.1/xFrames){
                                    xMin = 3.1/xFrames;
                                    xMax = 2.1/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed = 0.008;
                        }

                        if(posE.y < 0.012 && posE.y > -0.012){      //Enemy within an acceptable Y range, will no longer move the Y axis
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= 0.012){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 240){               //Enemy moves Down, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 1.1/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.008;
                        }
                        else if(posE.y <= -0.012){              //If Enemy is Below the Player
                            if(eT->getTicks() > 240){           //Enemy moves Up, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 6.3/xFrames){
                                    xMin = 5.2/xFrames;
                                    xMax = 6.2/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed = 0.008;
                        }
                    break;

                case 's':                       //Skeleton Enemy
                    if(posE.x < 0.005 && posE.x > -0.005){      //Enemy within an acceptable X range, will no longer move along the X axis
                        xSpeed = 0.0;
                    }
                    else if(posE.x >= 0.005){                   //If Enemy is to the Right of the Player
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
                        xSpeed = -0.005;
                    }
                    else if(posE.x <= -0.005){              //Else Enemy is to the Left of the Player
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
                        xSpeed = 0.005;
                    }

                    if(posE.y < 0.005 && posE.y > -0.005){      //Enemy within an acceptable Y range, will no longer move along the Y axis
                        ySpeed = 0.0;
                    }
                    else if(posE.y >= 0.005){                   //If Enemy is Above the Player
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
                        ySpeed = -0.005;
                    }
                    else if(posE.y <= -0.005){              //If Enemy is Below the Player
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
                        ySpeed = 0.005;
                    }
                    break;

                case 'w':                       //Wolf Enemy
                    if(posE.x < 0.015 && posE.x > -0.015){      //Enemy within an acceptable X range, will no longer move the X axis
                        xSpeed = 0.0;
                    }
                    else if(posE.x >= 0.015){                   //If Enemy is to the Right of the Player
                        if(eT->getTicks() > 180){               //Enemy moves to the Left, Running Animation
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 6.15/yFrames;
                            yMax = 7.15/yFrames;

                            if(xMin > 4.0/xFrames){
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        facingDirection = LEFT;
                        xSpeed = -0.01;
                    }
                    else if(posE.x <= -0.015){              //Else Enemy is to the Left of the Player
                        if(eT->getTicks() > 180){           //Enemy moves to the Right, Running Animation
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 8.25/yFrames;
                            yMax = 9.25/yFrames;

                            if(xMin > 4.0/xFrames){
                                xMin = 1.0/xFrames;
                                xMax = 2.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        facingDirection = RIGHT;
                        xSpeed = 0.01;
                    }

                    if(posE.y < 0.015 && posE.y > -0.015){      //Enemy within an acceptable Y range, will no longer move the Y axis
                        ySpeed = 0.0;
                    }
                    else if(posE.y >= 0.015){                   //If Enemy is Above the Player
                        if(eT->getTicks() > 180){               //Enemy moves Down, Running Animation
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 1.1/yFrames;
                            yMax = 2.1/yFrames;

                            if(xMin > 3.0/xFrames){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        facingDirection = DOWN;
                        ySpeed = -0.01;
                    }
                    else if(posE.y <= -0.015){              //If Enemy is Below the Player
                        if(eT->getTicks() > 180){           //Enemy moves Up, Running Animation
                            xMin += 1.0/xFrames;
                            xMax += 1.0/xFrames;
                            yMin = 4.15/yFrames;
                            yMax = 5.15/yFrames;

                            if(xMin > 3.0/xFrames){
                                xMin = 0.0/xFrames;
                                xMax = 1.0/xFrames;
                            }

                            eT->resetTime();
                        }
                        facingDirection = UP;
                        ySpeed = 0.01;
                    }
                    break;

                case 'z':                       //Mouth Enemy
                    if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0))) < 1.5 && !(sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 1.4)){
                        xSpeed = 0.0;
                        ySpeed = 0.0;

                        if(timerRandAct->getTicks() > 3000){
                            //Monster Call?
                            //deaf = true;
                            //shouted = true;                     //Flag to start calling other enemies
                            if(abs(posE.x) >= abs(posE.y)){                     //If Enemy is closer to the X axis then the Y axis
                                if(posE.x >= 0.0){                              //If Enemy is to the Right of the Player
                                    if(charged){
                                        //Firing Shout
                                        xMin = 3.0/xFrames;
                                        xMax = 4.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        //cout << "SHOUTED!\n";
                                    }
                                    else{
                                        //Charging Shout
                                        xMin = 2.0/xFrames;
                                        xMax = 3.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                                }
                                else{                                           //If Enemy is to the Left of the Player
                                    if(charged){
                                        //Firing Shout
                                        xMin = 4.0/xFrames;
                                        xMax = 3.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        //cout << "SHOUTED!\n";
                                    }
                                    else{
                                        //Charging Shout
                                        xMin = 3.0/xFrames;
                                        xMax = 2.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                                }

                            }
                            else if(posE.y >= 0.0){                             //If Enemy is closer to the Y axis then check if the Enemy is Above the Player
                                if(charged){
                                        //Firing Shout
                                        xMin = 1.0/xFrames;
                                        xMax = 2.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = false;
                                        shouted = true;
                                        //cout << "SHOUTED!\n";
                                    }
                                    else{
                                        //Charging Shout
                                        xMin = 0.0/xFrames;
                                        xMax = 1.0/xFrames;
                                        yMin = 3.0/yFrames;
                                        yMax = 4.0/yFrames;
                                        charged = true;
                                    }
                            }
                            else{                                               //If Enemy is Below the Player
                                if(charged){
                                    //Firing Shout
                                    xMin = 5.0/xFrames;
                                    xMax = 6.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = false;
                                    shouted = true;
                                    //cout << "SHOUTED!\n";
                                }
                                else{
                                    //Charging Shout
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                    yMin = 3.0/yFrames;
                                    yMax = 4.0/yFrames;
                                    charged = true;
                                }
                            }

                            timerRandAct->resetTime();
                        }
                        else
                            shouted = false;
                    }
                    else if((sqrt(powf(posE.x, 2.0) + powf(posE.y, 2.0)) < 1.3999)){            //Enemy is too close to the Player
                        if(posE.x >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMax > 5.0/xFrames){
                                    xMin = 3.8/xFrames;
                                    xMax = 2.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }
                        else if(posE.x < 0.0){              //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 2.8/xFrames;
                                    xMax = 3.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }

                        if(posE.y >= 0.0){          //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 8.0/xFrames){
                                    xMin = 6.0/xFrames;
                                    xMax = 7.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                        else if(posE.y < 0.0){         //Will move away from Player if too close
                            if(eT->getTicks() > 120){                   //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 2.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }

                        if(timerRandAct->getTicks() > 3000){
                            //How to implement Monster Call?

                            timerRandAct->resetTime();
                        }
                    }
                    else{                                       //Is between 2.0 and 1.5 and will walk closer to the Player, until within 1.5 to 1.4 range
                        if(posE.x >= 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 2.8/xFrames;
                                    xMax = 3.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }
                        else if(posE.x < -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMax > 5.0/xFrames){
                                    xMin = 3.8/xFrames;
                                    xMax = 2.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }

                        if(posE.y >= 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 2.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }
                        else if(posE.y < -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 8.0/xFrames){
                                    xMin = 6.0/xFrames;
                                    xMax = 7.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                    }
                    break;
            }
            //Hunt's Break
            break;

        case CALLED:
            if(isCalled){
                switch(id)
                {
                    case 'f':
                        if(posE.x < calledPos.x + 0.005 && posE.x > calledPos.x + -0.005){
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.005;
                        }
                        else if(posE.y < calledPos.y + -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.005;
                        }

                        if(posE.y < calledPos.y + 0.005 && posE.y > calledPos.y + -0.005){
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.005;
                        }
                        else if(posE.y < calledPos.y + -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.005;
                        }
                        break;

                    case 'm':                   //Mage Enemy
                        if(posE.x < calledPos.x + 0.005 && posE.x > calledPos.x + -0.005){
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 2.0/xFrames;
                                    xMax = 3.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }
                        else if(posE.x < calledPos.x + -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){          //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMax > 3.0/xFrames){
                                    xMin = 3.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }

                        if(posE.y < calledPos.y + 0.005 && posE.y > calledPos.y + -0.005){
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){          //Animation for going Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 1.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }
                        else if(posE.y < calledPos.y + -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){          //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.0/yFrames;
                                yMax = 2.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 4.0/xFrames;
                                    xMax = 5.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                        break;

                    case 'o':                       //Ogre Enemy
                        if(posE.x < calledPos.x + 0.012 && posE.x > calledPos.x + -0.012){      //Enemy within an acceptable X range, will no longer move the X axis
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.012){                   //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 240){               //Enemy moves to the Left, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 4.1/xFrames){
                                    xMin = 2.1/xFrames;
                                    xMax = 3.1/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.008;
                        }
                        else if(posE.x <= calledPos.x + -0.012){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 240){           //Enemy moves to the Right, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMax > 4.1/xFrames){
                                    xMin = 3.1/xFrames;
                                    xMax = 2.1/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed = 0.008;
                        }

                        if(posE.y < calledPos.y + 0.012 && posE.y > calledPos.y + -0.012){      //Enemy within an acceptable Y range, will no longer move the Y axis
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.012){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 240){               //Enemy moves Down, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 1.1/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.008;
                        }
                        else if(posE.y <= calledPos.y + -0.012){              //If Enemy is Below the Player
                            if(eT->getTicks() > 240){           //Enemy moves Up, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 3.0/yFrames;
                                yMax = 4.0/yFrames;

                                if(xMin > 6.3/xFrames){
                                    xMin = 5.2/xFrames;
                                    xMax = 6.2/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed = 0.008;
                        }
                        break;

                    case 's':                   //Skeleton Enemy
                        if(posE.x < calledPos.x + 0.005 && posE.x > calledPos.x + -0.005){
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.005){                   //If Enemy is to the Right of the Player
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
                            xSpeed = -0.005;
                        }
                        else if(posE.x <= calledPos.x + -0.005){              //Else Enemy is to the Left of the Player
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
                            xSpeed = 0.005;
                        }

                        if(posE.y < calledPos.y + 0.005 && posE.y > calledPos.y + -0.005){
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.005){                   //If Enemy is Above the Player
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
                            ySpeed = -0.005;
                        }
                        else if(posE.y <= calledPos.y + -0.005){              //If Enemy is Below the Player
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
                            ySpeed = 0.005;
                        }
                        break;

                    case 'w':                   //Wolf Enemy
                        if(posE.x < calledPos.x + 0.015 && posE.x > calledPos.x + -0.015){      //Enemy within an acceptable X range, will no longer move the X axis
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.015){                   //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 180){               //Enemy moves to the Left, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 6.15/yFrames;
                                yMax = 7.15/yFrames;

                                if(xMin > 4.0/xFrames){
                                    xMin = 1.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.01;
                        }
                        else if(posE.x <= calledPos.x + -0.015){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 180){           //Enemy moves to the Right, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 8.25/yFrames;
                                yMax = 9.25/yFrames;

                                if(xMin > 4.0/xFrames){
                                    xMin = 1.0/xFrames;
                                    xMax = 2.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed = 0.01;
                        }

                        if(posE.y < calledPos.y + 0.015 && posE.y > calledPos.y + -0.015){      //Enemy within an acceptable Y range, will no longer move the Y axis
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.015){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 180){               //Enemy moves Down, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 1.1/yFrames;
                                yMax = 2.1/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.01;
                        }
                        else if(posE.y <= calledPos.y + -0.015){              //If Enemy is Below the Player
                            if(eT->getTicks() > 180){           //Enemy moves Up, Running Animation
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 4.15/yFrames;
                                yMax = 5.15/yFrames;

                                if(xMin > 3.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed = 0.01;
                        }
                        break;

                    case 'z':                   //Mouth Enemy
                        if(posE.x < calledPos.x + 0.005 && posE.x > calledPos.x + -0.005){
                            xSpeed = 0.0;
                        }
                        else if(posE.x >= calledPos.x + 0.005){                    //If Enemy is to the Right of the Player
                            if(eT->getTicks() > 120){           //Animation for going Left
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 5.0/xFrames){
                                    xMin = 2.8/xFrames;
                                    xMax = 3.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = LEFT;
                            xSpeed = -0.003;
                        }
                        else if(posE.x < calledPos.x + -0.005){              //Else Enemy is to the Left of the Player
                            if(eT->getTicks() > 120){                        //Animation for going Right
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMax > 5.0/xFrames){
                                    xMin = 3.8/xFrames;
                                    xMax = 2.8/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = RIGHT;
                            xSpeed =  0.003;
                        }

                        if(posE.y < calledPos.y + 0.005 && posE.y > calledPos.y + -0.005){
                            ySpeed = 0.0;
                        }
                        else if(posE.y >= calledPos.y + 0.005){                   //If Enemy is Above the Player
                            if(eT->getTicks() > 120){                             //Animation for going to Down
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 2.0/xFrames){
                                    xMin = 0.0/xFrames;
                                    xMax = 1.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = DOWN;
                            ySpeed = -0.003;
                        }
                        else if(posE.y < calledPos.y + -0.005){              //If Enemy is Below the Player
                            if(eT->getTicks() > 120){                        //Animation for going Up
                                xMin += 1.0/xFrames;
                                xMax += 1.0/xFrames;
                                yMin = 0.0/yFrames;
                                yMax = 1.0/yFrames;

                                if(xMin > 8.0/xFrames){
                                    xMin = 6.0/xFrames;
                                    xMax = 7.0/xFrames;
                                }

                                eT->resetTime();
                            }
                            facingDirection = UP;
                            ySpeed =  0.003;
                        }
                        break;
                }
            }

            if(timerRandAct->getTicks() > 6000){
                isCalled = false;
                xSpeed = 0.0;
                ySpeed = 0.0;
                actionTrigger = STAND;
                cout << "No longered Called\n";

                timerRandAct->resetTime();
            }
            //Called Break
            break;
    }
}

void _enemies::moveCausedByPlayer()                 //Enemy movement based on Player movement
{
    if(!isBlocking){
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
}


