#include "_particles.h"

_particles::_particles()
{
    //ctor
}

_particles::~_particles()
{
    //dtor
}

void _particles::projectileScroll(float speed, pts part[])
{
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                part->xProjDest += speed * 200.0;
                part->xDir += speed * 200.0;
                isDodging = false;
            }
            else{
                part->xProjDest += speed;
                part->xDir += speed;
            }

            if(lFlag && uFlag && isDodging){
                part->yProjDest -= speed * 200.0;
                part->yDir -= speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                part->yProjDest += speed * 200.0;
                part->yDir += speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                part->yProjDest -= speed;
                part->yDir -= speed;

            }
            else if(lFlag && dFlag){
                part->yProjDest += speed;
                part->yDir += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                part->xProjDest -= speed * 200.0;
                part->xDir -= speed * 200.0;
                isDodging = false;
            }
            else{
                part->xProjDest -= speed;
                part->xDir -= speed;
            }

            if(rFlag && uFlag && isDodging){
                part->yProjDest -= speed * 200.0;
                part->yDir -= speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                part->yProjDest += speed * 200.0;
                part->yDir += speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                part->yProjDest -= speed;
                part->yDir -= speed;
            }
            else if(rFlag && dFlag){
                part->yProjDest += speed;
                part->yDir += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                part->yProjDest -= speed * 200.0;
                part->yDir -= speed * 200.0;
                isDodging = false;
            }
            else{
                part->yProjDest -= speed;
                part->yDir -= speed;
            }

            if(uFlag && lFlag && isDodging){
                part->xProjDest += speed * 200.0;
                part->xDir += speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                part->xProjDest -= speed * 200.0;
                part->xDir -= speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                part->xProjDest += speed;
                part->xDir += speed;
            }
            else if(uFlag && rFlag){
                part->xProjDest -= speed;
                part->xDir -= speed;
            }
        }
        else if(dFlag){
            //uFlag = false;
            if(dFlag && isDodging){
                part->yProjDest += speed * 200.0;
                part->yDir += speed * 200.0;
                isDodging = false;
            }
            else{
                part->yProjDest += speed;
                part->yDir += speed;
            }

            if(dFlag && lFlag && isDodging){
                part->xProjDest += speed * 200.0;
                part->xDir += speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                part->xProjDest -= speed * 200.0;
                part->xDir -= speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                part->xProjDest += speed;
                part->xDir += speed;
            }
            else if(dFlag && rFlag){
                part->xProjDest -= speed;
                part->xDir -= speed;
            }
        }
    }
}

//*
void _particles::scroll(float speed, pts part[])
{
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                part->posX += speed * 200.0;
                isDodging = false;
            }
            else{
                part->posX += speed;
            }

            if(lFlag && uFlag && isDodging){
                part->posY -= speed * 200.0;
                part->movedFloor -= speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                part->posY += speed * 200.0;
                part->movedFloor += speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                part->posY -= speed;
                part->movedFloor -= speed;
            }
            else if(lFlag && dFlag){
                part->posY += speed;
                part->movedFloor += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                part->posX -= speed * 200.0;
                isDodging = false;
            }
            else{
                part->posX -= speed;
            }

            if(rFlag && uFlag && isDodging){
                part->posY -= speed * 200.0;
                part->movedFloor -= speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                part->posY += speed * 200.0;
                part->movedFloor += speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                part->posY -= speed;
                part->movedFloor -= speed;
            }
            else if(rFlag && dFlag){
                part->posY += speed;
                part->movedFloor += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                part->posY -= speed * 200.0;
                part->movedFloor -= speed * 200.0;
                isDodging = false;
            }
            else{
                part->posY -= speed;
                part->movedFloor -= speed;
            }

            if(uFlag && lFlag && isDodging){
                part->posX += speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                part->posX -= speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                part->posX += speed;
            }
            else if(uFlag && rFlag){
                part->posX -= speed;
            }
        }
        else if(dFlag){
            //uFlag = false;
            if(dFlag && isDodging){
                part->posY += speed * 200.0;
                part->movedFloor += speed * 200.0;
                isDodging = false;
            }
            else{
                part->posY += speed;
                part->movedFloor += speed;
            }

            if(dFlag && lFlag && isDodging){
                part->posX += speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                part->posX -= speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                part->posX += speed;
            }
            else if(dFlag && rFlag){
                part->posX -= speed;
            }
        }
    }
}

//*/

/*
void _particles::scroll(float speed, float &xDest, float &yDest, float &xOri, float &yOrig)
{
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                xDest += speed * 200.0;
                xOri  += speed * 200.0;
                isDodging = false;
            }
            else{
                xDest += speed;
                xOri += speed;
            }

            if(lFlag && uFlag && isDodging){
                yDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                yDest += speed * 200.0;
                xOri += speed * 200.0;
                isDodging = false;
            }
            else if(lFlag && uFlag){
                yDest -= speed;
                xOri -= speed;
            }
            else if(lFlag && dFlag){
                yDest += speed;
                xOri += speed;
            }

        }
        else if(rFlag){
            //lFlag = false;
            if(rFlag && isDodging){
                xDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else{
                xDest -= speed;
                xOri -= speed;
            }

            if(rFlag && uFlag && isDodging){
                yDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                yDest += speed * 200.0;
                xOri += speed * 200.0;
                isDodging = false;
            }
            else if(rFlag && uFlag){
                yDest -= speed;
                xOri -= speed;
            }
            else if(rFlag && dFlag){
                yDest += speed;
                xOri += speed;
            }
        }
        else if(uFlag){
            //dFlag = false;
            if(uFlag && isDodging){
                yDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else{
                xDest -= speed;
                xOri -= speed;
            }

            if(uFlag && lFlag && isDodging){
                xDest += speed * 200.0;
                xOri += speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                xDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else if(uFlag && lFlag){
                xDest += speed;
                xOri += speed;
            }
            else if(uFlag && rFlag){
                xDest -= speed;
                xOri -= speed;
            }
        }
        else if(dFlag){
            //uFlag = false;
            if(dFlag && isDodging){
                yDest += speed * 200.0;
                xOri += speed * 200.0;
                isDodging = false;
            }
            else{
                yDest += speed;
                xOri += speed;

            }

            if(dFlag && lFlag && isDodging){
                xDest += speed * 200.0;
                xOri += speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                xDest -= speed * 200.0;
                xOri -= speed * 200.0;
                isDodging = false;
            }
            else if(dFlag && lFlag){
                xDest += speed;
                xOri += speed;
            }
            else if(dFlag && rFlag){
                xDest -= speed;
                xOri -= speed;
            }
        }
    }
}
*/

///////////////////////////////////////////Blood////////////////////////////////////////////
void _particles::drawBlood()
{
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(3);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numBldDrops; i++){
            if(bldDrops[i].alive){
                glVertex3f(bldDrops[i].posX, bldDrops[i].posY, bldDrops[i].posZ);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateBlood()
{
    for(int i = 0; i < numBldDrops; i++){
        if(bldDrops[i].alive){
            scroll(0.007, &bldDrops[i]);
            //bldDrops[i].movedFloor += bldDrops[i].ySpeed;

            bldDrops[i].posY + GRAVITY * bldDrops[i].mass < bldDrops[i].partFloor + bldDrops[i].movedFloor?
            bldDrops[i].yDir = 0.0, bldDrops[i].xDir = 0.0:bldDrops[i].yDir += GRAVITY * bldDrops[i].mass;
            //bldDrops[i].yDir = -bldDrops[i].yDir/1.3:bldDrops[i].yDir += GRAVITY * bldDrops[i].mass;

            bldDrops[i].posX += (bldDrops[i].xDir);         //+ bldDrops[i].xSpeed);
            bldDrops[i].posY += (bldDrops[i].yDir);          //+ bldDrops[i].ySpeed);

            if(bldDrops[i].particleTimer->getTicks() > 6000){      //If enough time has passed
                bldDrops[i].alive = false;
            }
        }
    }
}
/*
void _particles::bloodGenerator(float x, float y)
{
    int i = 0;          //iterator

    srand(time(NULL));
    int newDrops = (rand() % 5) + 5;

    if(numBldDrops + newDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numBldDrops;
    }

    for(i = numBldDrops; i < numBldDrops + newDrops; i++){
        bldDrops[i].alive = true;
        bldDrops[i].posX = x;
        bldDrops[i].posY = y + 0.05; // + (rand() % 1000)/10000.0;

        bldDrops[i].xDir = (rand() % 10) * 0.0001;       //0.0075 + (rand() % 1000) * 25/100000.0;
        bldDrops[i].yDir = 0.0;

        bldDrops[i].mass = 0.005 + (rand()%10)/500;
        bldDrops[i].particleTimer->startTimer();
    }

    numBldDrops += newDrops;

    numBldDrops >=MAX_DROPS?numBldDrops=0:NULL;
}
*/


void _particles::plyrBldGenerator(_player* ply, _enemies enmy[])
{
    int i = 0;          //iterator

    srand(time(NULL));
    int newDrops = ((rand() % 5) + 5);

    if(numBldDrops + newDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numBldDrops;
    }

    for(i = numBldDrops; i < numBldDrops + newDrops; i++){
        if(enmy->posE.x >= 0.0)
            bldDrops[i].xImpactDir = -1.0;
        else
            bldDrops[i].xImpactDir = 1.0;

        bldDrops[i].movedFloor = 0;

        bldDrops[i].alive = true;
        bldDrops[i].posX = ply->playerPos.x;
        bldDrops[i].posY = ply->playerPos.y + 0.05; // + (rand() % 1000)/10000.0;
        bldDrops[i].posZ = -8.0;

        bldDrops[i].partFloor = ply->playerPos.y - 0.5;

        bldDrops[i].xDir =(rand() % 10) * 0.0001 * bldDrops[i].xImpactDir;       //0.0075 + (rand() % 1000) * 25/100000.0;
        bldDrops[i].yDir = 0.0;

        bldDrops[i].mass = 0.005 + (rand()%10)/500;
        bldDrops[i].particleTimer->startTimer();
    }

    numBldDrops += newDrops;

    numBldDrops >=MAX_DROPS?numBldDrops=0:NULL;
}

void _particles::enmyBldGenerator(_enemies enmy[])
{
    if(!enmy->alreadyHit){
    int i = 0;          //iterator

    srand(time(NULL));
    int newDrops = (rand() % 5) + 5;

    if(numBldDrops + newDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numBldDrops;
    }

    for(i = numBldDrops; i < numBldDrops + newDrops; i++){
        if(enmy->posE.x >= 0.0)
            bldDrops[i].xImpactDir = 1.0;
        else
            bldDrops[i].xImpactDir = -1.0;

        bldDrops[i].movedFloor = 0;


        bldDrops[i].alive = true;
        bldDrops[i].posX = enmy->posE.x;
        bldDrops[i].posY = enmy->posE.y + 0.05; // + (rand() % 1000)/10000.0;
        bldDrops[i].posZ = -8.0;

        bldDrops[i].partFloor = enmy->posE.y - 0.35;

        bldDrops[i].xDir = (rand() % 10) * 0.0001 * bldDrops[i].xImpactDir;       //0.0075 + (rand() % 1000) * 25/100000.0;
        bldDrops[i].yDir = 0.0;

        bldDrops[i].mass = 0.005 + (rand()%10)/500;
        bldDrops[i].particleTimer->startTimer();
    }

    numBldDrops += newDrops;

    numBldDrops >=MAX_DROPS?numBldDrops=0:NULL;
    }
}
/////////////////////////////////End of Blood/////////////////////////////////////////////

//////////////////////////////////Projectile//////////////////////////////////////////////

void _particles::drawProjectile()
{
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(10);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numProjDrops; i++){
            if(projectile[i].alive){
                glVertex3f(projectile[i].posX, projectile[i].posY, -1.0);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateProjectile(_player* ply, _enemies enmy[], int numEnmy, int &sumnNum)
{

    for(int i = 0; i < numProjDrops; i++){
        if(projectile[i].alive){
            //cout << "Before - XProjDest: " << projectile[i].xProjDest << " YProjDest: " << projectile[i].yProjDest  << endl;
            projectileScroll(0.007, &projectile[i]);
            //cout << "After - XProjDest: " << projectile[i].xProjDest << " YProjDest: " << projectile[i].yProjDest  << endl;
            /*
            projectile[i].xProjDest += projectile[i].xSpeed;
            projectile[i].yProjDest += projectile[i].ySpeed;
            projectile[i].xDir += projectile[i].xSpeed;
            projectile[i].yDir += projectile[i].ySpeed;
            //*/



            projectile[i].posX = ((projectile[i].xDir + projectile[i].t * (projectile[i].xProjDest - projectile[i].xDir)));
            projectile[i].posY = ((projectile[i].yDir + projectile[i].t * (projectile[i].yProjDest - projectile[i].yDir)));

            if(projectile[i].particleTimer->getTicks() > 30){
                projectile[i].t += 0.03;

                //Drawing Trail
                trailGenerator(i);
                //cout << "PosX: " << projectile[i].posX << " PosY: " << projectile[i].posY  << " t: " << projectile[i].t << endl;

                projectile[i].particleTimer->resetTime();
            }

            glPushMatrix();
            drawTrail();
            glPopMatrix();
            updateTrail();

            if(projectile[i].lethal && collChkr->detectCollision(ply->playerPos.x, ply->playerPos.y, ply->radiusPlayer, projectile[i].posX, projectile[i].posY, 0.0)){
                projectile[i].alive = false;
                ply->actionTrigger = ply->HIT;
            }
            else if(!projectile[i].lethal && collChkr->detectCollision(projectile[i].xProjDest, projectile[i].yProjDest, 0.1, projectile[i].posX, projectile[i].posY, 0.1)){
                projectile[i].alive = false;
                enmy[numEnmy + sumnNum].summonEnms(projectile[i].xProjDest, projectile[i].yProjDest);
                sumnNum++;
            }
            else if(projectile[i].posX > 8.0 || projectile[i].posX < -8.0 || projectile[i].posY > 5.0 || projectile[i].posY < -5.0){      //If outside of the screen or collides with player
                projectile[i].alive = false;
                //cout << "Dead Projectile\n";

            }
        }

    }
}

void _particles::projectileGenerator(_enemies enmy[])
{
    int i = 0;          //iterator
    float xOffset = 0.0;                    //Variable used to position generated projectile correctly to look like it came from the mage's wand
    float yOffset = 0.0;                    //Variable used to position generated projectile correctly to look like it came from the mage's wand

    srand(time(NULL));
    int newDrops = 1;

    if(numProjDrops + newDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numProjDrops;
    }

    for(i = numProjDrops; i < numProjDrops + newDrops; i++){
        projectile[i].alive = true;

        switch(enmy->id){
        case 'f':
            if(abs(enmy->posE.x) >= abs(enmy->posE.y)){
                if(enmy->posE.x >= 0.0){
                    xOffset = -0.3;
                    yOffset = 0.05;
                }
                else{
                    xOffset = 0.3;
                    yOffset = 0.05;
                }
                projectile[i].yImpactDir = 0.0;
            }
            else if(enmy->posE.y >= 0.0){
                yOffset = -0.2;
                xOffset = 0.05;
            }
            else{
                yOffset = 0.2;
                xOffset = -0.05;
            }

            if(enmy->summonCap >= 5){
                projectile[i].lethal = true;
                projectile[i].xProjDest = 0.0;                                      //Projectile's destination should be Player's position
                projectile[i].yProjDest = 0.0;                                      //Projectile's destination should be Player's position
            }
            else{
                projectile[i].lethal = false;
                projectile[i].xProjDest = (float)rand()/float(RAND_MAX) * 6.0 - 3.0;                                      //Projectile's destination should be Player's position
                projectile[i].yProjDest = (float)rand()/float(RAND_MAX) * 6.0 - 3.0;                                      //Projectile's destination should be Player's position
            }
            break;

        case 'm':
            if(abs(enmy->posE.x) >= abs(enmy->posE.y)){
                if(enmy->posE.x >= 0.0){
                    xOffset = -0.3;
                    yOffset = 0.05;
                }
                else{
                    xOffset = 0.3;
                    yOffset = 0.05;
                }
                projectile[i].yImpactDir = 0.0;
            }
            else if(enmy->posE.y >= 0.0){
                yOffset = -0.2;
                xOffset = -0.08;
            }
            else{
                yOffset = 0.2;
            }

            projectile[i].lethal = true;
            projectile[i].xProjDest = 0.0;                                      //Projectile's destination should be Player's position
            projectile[i].yProjDest = 0.0;                                      //Projectile's destination should be Player's position
            break;
        }


        //projectile[i].posX = 0.0;
        //projectile[i].posY = 0.0;

        projectile[i].xDir = enmy->posE.x + xOffset;                    //Particle is generated near Enemy's Position
        projectile[i].yDir = enmy->posE.y + yOffset;                    //Particle is generated near Enemy's Position
        projectile[i].posZ = -8.0;

        //projectile[i].partFloor = enmy->posE.y - 0.35;

        projectile[i].t = 0.0;


        //projectile[i].mass = 0.005 + (rand()%10)/500;
        projectile[i].particleTimer->startTimer();
    }

    numProjDrops += newDrops;

    numProjDrops >=MAX_DROPS?numProjDrops=0:NULL;
}
///////////////////////////////////End of Projectile///////////////////////////////////////

/////////////////////////////////Projectile Trail//////////////////////////////////////////
void _particles::drawTrail()
{
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(5);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numTrailDrops; i++){
            if(trail[i].alive){
                glVertex3f(trail[i].posX, trail[i].posY, trail[i].posZ);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateTrail()
{
    for(int i = 0; i < numTrailDrops; i++){
        if(trail[i].alive){
            //trail[i].movedFloor += ySpeed;

            //trail[i].posX += trail[i].xSpeed;
            //trail[i].posY += trail[i].ySpeed;

            scroll(0.0001, &trail[i]);
            //trail[i].posX += trail[i].xSpeed;
            //trail[i].posY += trail[i].ySpeed;

            if(trail[i].particleTimer->getTicks() > 50 ){      //If enough time has passed Trail particle dies
                trail[i].alive = false;

                trail[i].particleTimer->resetTime();
            }
        }
    }
}

void _particles::trailGenerator(int projIndex)
{
    ///*
    int i = 0;          //iterator

    srand(time(NULL));
    int newDrops = 5;//(rand() % 5);

    if(numTrailDrops + newDrops > MAX_DROPS){
        newDrops = MAX_DROPS - numTrailDrops;
    }

    for(i = numTrailDrops; i < numTrailDrops + newDrops; i++){
        /*
        //This is for correct trail orientation
        if(projectile[projIndex].xImpactDir != 0)
            trail[i].xImpactDir = projectile[projIndex].xImpactDir;
        else
            trail[i].yImpactDir = projectile[projIndex].yImpactDir;
        */

        trail[i].alive = true;
        trail[i].posX = projectile[projIndex].posX;                 //Trail particles X pos = projectile's X pos at that moment
        trail[i].posY = projectile[projIndex].posY;                 //Trail particles Y pos = projectile's Y pos at that moment
        trail[i].posZ = -8.0;

        //trail[i].partFloor = projectile[projIndex].posY - 0.35;

        //trail[i].xDir = (rand() % 10) * 0.0001 * trail[i].xImpactDir;
        //trail[i].yDir = (rand() % 10) * 0.0001 * trail[i].yImpactDir;

        //trail[i].mass = 0.005 + (rand()%10)/500;
        trail[i].particleTimer->startTimer();
    }

    numTrailDrops += newDrops;

    numTrailDrops >=MAX_DROPS?numTrailDrops=0:NULL;
    //*/
}
//////////////////////////////////End of Projectile Trail////////////////////////////////////////
