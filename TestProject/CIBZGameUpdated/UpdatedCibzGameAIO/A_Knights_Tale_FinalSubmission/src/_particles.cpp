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
                part->xProjDest += (speed * 6.0);       //200.0;
                part->xDir += (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else{
                part->xProjDest += speed;
                part->xDir += speed;
            }

            if(lFlag && uFlag && isDodging){
                part->yProjDest -= (speed * 6.0);       //200.0;
                part->yDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                part->yProjDest += (speed * 6.0);       //200.0;
                part->yDir += (speed * 6.0);            //200.0;
                //isDodging = false;
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
                part->xProjDest -= (speed * 6.0);       //200.0;
                part->xDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else{
                part->xProjDest -= speed;
                part->xDir -= speed;
            }

            if(rFlag && uFlag && isDodging){
                part->yProjDest -= (speed * 6.0);       //200.0;
                part->yDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                part->yProjDest += (speed * 6.0);       //200.0;
                part->yDir += (speed * 6.0);            //200.0;
                //isDodging = false;
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
                part->yProjDest -= (speed * 6.0);       //200.0;
                part->yDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else{
                part->yProjDest -= speed;
                part->yDir -= speed;
            }

            if(uFlag && lFlag && isDodging){
                part->xProjDest += (speed * 6.0);       //200.0;
                part->xDir += (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                part->xProjDest -= (speed * 6.0);       //200.0;
                part->xDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
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
                part->yProjDest += (speed * 6.0);       //200.0;
                part->yDir += (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else{
                part->yProjDest += speed;
                part->yDir += speed;
            }

            if(dFlag && lFlag && isDodging){
                part->xProjDest += (speed * 6.0);       //200.0;
                part->xDir += (speed * 6.0);            //200.0;
                //isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                part->xProjDest -= (speed * 6.0);       //200.0;
                part->xDir -= (speed * 6.0);            //200.0;
                //isDodging = false;
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


void _particles::scroll(float speed, pts part[])
{
    //cout << "PosX Before: " << part->posX << endl;
    if(!isAttacking && !isBlocking){
        if(lFlag){
            //rFlag = false;
            if(lFlag && isDodging){
                part->posX += (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else{
                part->posX += speed;
            }

            if(lFlag && uFlag && isDodging){
                part->posY -= (speed * 6.0);       //200.0;
                part->movedFloor -= (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else if(lFlag && dFlag && isDodging){
                part->posY += (speed * 6.0);       //200.0;
                part->movedFloor += (speed * 6.0);       //200.0;
                //isDodging = false;
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
                part->posX -= (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else{
                part->posX -= speed;
            }

            if(rFlag && uFlag && isDodging){
                part->posY -= (speed * 6.0);       //200.0;
                part->movedFloor -= (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else if(rFlag && dFlag && isDodging){
                part->posY += (speed * 6.0);       //200.0;
                part->movedFloor += (speed * 6.0);       //200.0;
                //isDodging = false;
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
                part->posY -= (speed * 6.0);       //200.0;
                part->movedFloor -= (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else{
                part->posY -= speed;
                part->movedFloor -= speed;
            }

            if(uFlag && lFlag && isDodging){
                part->posX += (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else if(uFlag && rFlag && isDodging){
                part->posX -= (speed * 6.0);       //200.0;
                //isDodging = false;
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
                part->posY += (speed * 6.0);       //200.0;
                part->movedFloor += (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else{
                part->posY += speed;
                part->movedFloor += speed;
            }

            if(dFlag && lFlag && isDodging){
                part->posX += (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else if(dFlag && rFlag && isDodging){
                part->posX -= (speed * 6.0);       //200.0;
                //isDodging = false;
            }
            else if(dFlag && lFlag){
                part->posX += speed;
            }
            else if(dFlag && rFlag){
                part->posX -= speed;
            }
        }
    }
    //cout << "PosX After: " << part->posX << endl;
}

///////////////////////////////////////////Blood////////////////////////////////////////////
void _particles::drawBlood()
{

    //glScalef(0.5, 0.5, 1.0);
    glPointSize(3);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numBldDrops; i++){
            if(bldDrops[i].alive){
                switch(bldDrops[i].id)
                {
                    case 'f':
                        glColor3f(0.8, 0.0, 0.8);
                        break;

                    case 'm':
                        glColor3f(1.0, 1.0, 0.0);
                        break;

                    case 'o':
                        glColor3f(0.5, 0.0, 1.0);
                        break;

                    case 'p':
                        glColor3f(0.0, 1.0, 0.0);
                        break;

                    case 's':
                        glColor3f(1.0, 1.0, 1.0);
                        break;

                    case 'w':
                        glColor3f(0.0, 0.0, 0.8);
                        break;

                    default:
                        glColor3f(0.6, 0.0, 0.0);
                        break;
                }
                glVertex3f(bldDrops[i].posX, bldDrops[i].posY, bldDrops[i].posZ);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateBlood(float spdMult, float slowed)
{
    for(int i = 0; i < numBldDrops; i++){
        if(bldDrops[i].alive){
            //bldDrops[i].movedFloor += bldDrops[i].ySpeed;

            bldDrops[i].posY + GRAVITY * bldDrops[i].mass < bldDrops[i].partFloor + bldDrops[i].movedFloor?
            bldDrops[i].yDir = 0.0, bldDrops[i].xDir = 0.0:bldDrops[i].yDir += GRAVITY * bldDrops[i].mass;
            //bldDrops[i].yDir = -bldDrops[i].yDir/1.3:bldDrops[i].yDir += GRAVITY * bldDrops[i].mass;

            bldDrops[i].posX += (bldDrops[i].xDir);         //+ bldDrops[i].xSpeed);
            bldDrops[i].posY += (bldDrops[i].yDir);          //+ bldDrops[i].ySpeed);

            //cout << "Blood Drop Pos[" << i << "] Before: " << bldDrops[i].posX << endl;
            scroll(0.02 * spdMult * slowed, &bldDrops[i]);
            //scroll(0.02 * spdMult * slowed, &bldDrops[i]);
            //cout << "Blood Drop Pos[" << i << "] After:  " << bldDrops[i].posX << endl;

            if(bldDrops[i].particleTimer->getTicks() > 16000){      //If enough time has passed
                bldDrops[i].alive = false;
            }
        }
    }
}

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
        bldDrops[i].posZ = -4.0;

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
        bldDrops[i].id = enmy->id;

        if(enmy->posE.x >= 0.0)
            bldDrops[i].xImpactDir = 1.0;
        else
            bldDrops[i].xImpactDir = -1.0;

        bldDrops[i].movedFloor = 0;


        bldDrops[i].alive = true;
        bldDrops[i].posX = enmy->posE.x;
        bldDrops[i].posY = enmy->posE.y + 0.05; // + (rand() % 1000)/10000.0;
        bldDrops[i].posZ = -4.0;

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
    glPointSize(10);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numProjDrops; i++){
            switch(projectile[i].id)
            {
                case 'f':
                    glColor3f(0.8, 0.0, 0.8);
                    break;

                case 'm':
                    glColor3f(1.0, 1.0, 0.0);
                    break;

            }
            if(projectile[i].alive){
                glVertex3f(projectile[i].posX, projectile[i].posY, projectile[i].posZ);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateProjectile(_player* ply, _enemies enmy[], int numEnmy, int &sumnNum, bool level5, float spdMult, float slowed)
{
    for(int i = 0; i < numProjDrops; i++){
        if(projectile[i].alive){
            //cout << "Before - XProjDest: " << projectile[i].xProjDest << " YProjDest: " << projectile[i].yProjDest  << endl;
            projectileScroll(0.02 * spdMult * slowed, &projectile[i]);
            //cout << "After - XProjDest: " << projectile[i].xProjDest << " YProjDest: " << projectile[i].yProjDest  << endl;


            projectile[i].posX = ((projectile[i].xDir + projectile[i].t * (projectile[i].xProjDest - projectile[i].xDir)));
            projectile[i].posY = ((projectile[i].yDir + projectile[i].t * (projectile[i].yProjDest - projectile[i].yDir)));

            if(projectile[i].particleTimer->getTicks() > 30){
                projectile[i].t += 0.025;

                //Drawing Trail
                trailGenerator(i);

                projectile[i].particleTimer->resetTime();
            }

            glPushMatrix();
            drawTrail();
            glPopMatrix();
            updateTrail(spdMult, slowed);

            if(projectile[i].lethal && collChkr->detectCollision(ply->playerPos.x, ply->playerPos.y, ply->radiusPlayer, projectile[i].posX, projectile[i].posY, 0.0)){
                projectile[i].alive = false;
                ply->invulnerable = false;
                ply->actionTrigger = ply->HIT;
                plyrBldGenerator(ply, &enmy[i]);
                ply->actions();
            }
            else if(!projectile[i].lethal && collChkr->detectCollision(projectile[i].xProjDest, projectile[i].yProjDest, 0.1, projectile[i].posX, projectile[i].posY, 0.1)){
                projectile[i].alive = false;
                enmy[numEnmy + sumnNum].summonEnms(projectile[i].xProjDest, projectile[i].yProjDest, level5);
                sumnNum++;
            }
            else if(projectile[i].posX > 16.0 || projectile[i].posX < -16.0 || projectile[i].posY > 16.0 || projectile[i].posY < -16.0){      //If outside of the screen or collides with player
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
            projectile[i].id = enmy->id;
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
            projectile[i].id = enmy->id;
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

        projectile[i].xDir = enmy->posE.x + xOffset;                    //Particle is generated near Enemy's Position
        projectile[i].yDir = enmy->posE.y + yOffset;                    //Particle is generated near Enemy's Position

        projectile[i].posZ = -4.0;

        projectile[i].t = 0.0;

        projectile[i].particleTimer->startTimer();
    }

    numProjDrops += newDrops;

    numProjDrops >=MAX_DROPS?numProjDrops=0:NULL;
}
///////////////////////////////////End of Projectile///////////////////////////////////////

/////////////////////////////////Projectile Trail//////////////////////////////////////////
void _particles::drawTrail()
{

    glPointSize(5);

    glDisable(GL_TEXTURE_2D);
    glBegin(GL_POINTS);
        for(int i = 0; i < numTrailDrops; i++){
            switch(trail[i].id)
            {
                case 'f':
                    glColor3f(0.5, 0.0, 0.5);
                    break;

                case 'm':
                    glColor3f(0.5, 0.5, 0.0);
                    break;

            }
            if(trail[i].alive){
                glVertex3f(trail[i].posX, trail[i].posY, trail[i].posZ);
            }
        }
    glEnd();
    glEnable(GL_TEXTURE_2D);
}

void _particles::updateTrail(float spdMult, float slowed)
{
    for(int i = 0; i < numTrailDrops; i++){
        if(trail[i].alive){

            scroll(0.0005 * spdMult * slowed, &trail[i]);

            if(trail[i].particleTimer->getTicks() > 40 ){      //If enough time has passed Trail particle dies
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

        trail[i].alive = true;
        trail[i].id = projectile[projIndex].id;
        trail[i].posX = projectile[projIndex].posX;                 //Trail particles X pos = projectile's X pos at that moment
        trail[i].posY = projectile[projIndex].posY;                 //Trail particles Y pos = projectile's Y pos at that moment
        trail[i].posZ = -4.0;

        trail[i].particleTimer->startTimer();
    }

    numTrailDrops += newDrops;

    numTrailDrops >=MAX_DROPS?numTrailDrops=0:NULL;
    //*/
}
//////////////////////////////////End of Projectile Trail//////////////////////////////////
