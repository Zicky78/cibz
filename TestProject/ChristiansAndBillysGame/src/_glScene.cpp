#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //ctor
    //screenWidth = GetSystemMetrics(SM_CXSCREEN);
    //screenHeight = GetSystemMetrics(SM_CYSCREEN);

    landingLevel = true;

    doneLoading= false;
    liveLevel1 = false; //starts loading level 1, liveLevel1 = true;
    liveLevel2 = false;
    liveLevel3 = false;


    menuLevel = false;
    helpLevel = false;
    pauseLevel = false;
    creditLevel = false;
}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_COLOR_MATERIAL);
    _glLight myLight(GL_LIGHT0);

    //Menu Images
    landingImage->menuInit("images/MainMenu.png"); //loads landing image
    menuImage->menuInit("images/MenuSelection.png"); //loads menu image //mine
    helpImage->menuInit("images/help.png"); //loads help image
    pauseImage->menuInit("images/pause.png"); //loads pause image
    creditImage->menuInit("images/Credits1.png"); //loads credits image

    backGroundLevel1->parallaxInit("images/dungeonFloor.jpg", 10.0, 5.0);
    backGroundLevel2->parallaxInit("images/dungeonFloor2.jpg", 10.0, 5.0);
    backGroundLevel3->parallaxInit("images/dungeonFloor3.jpg", 10.0, 5.0);

    backGround->parallaxInit("images/dungeonFloor.jpg", 10.0, 5.0);
    backGround1->parallaxInit("images/visibility.png");
    backGround1->plxPos.z = -2.0;

    timer->startTimer();

    myPly->playerInit(9, 3);
    myPly->plyImage->loadTexture("images/knight.png");

    fnts->initFonts("images/fantasyfont.png");
    fnts->buildFont(" ]Level 1]", 9.0);

    items->itemInit(8.0, 1.0);
    switch(items->itemType) {
    case 0:
        cout << "0 item"<< endl;
        items->itemImage->loadTexture("images/light.png");
        break;
    case 1:
        cout << "1 item"<< endl;
        items->itemImage->loadTexture("images/attack.png");
        break;
    case 2:
        cout << "2 item" << endl;
        items->itemImage->loadTexture("images/speed.png");
        break;
    }

    numOfEnms = 5;
    texEnms->loadTexture("images/zombie_n_skeleton2.png");
    for(int i = 0; i < numOfEnms; i++){
        enms[i].tex = texEnms->tex;
        enms[i].enemyHealth = 3;
        enms[i].posE.x = (float)rand()/float(RAND_MAX) * 8.0 - 3.0;
        enms[i].posE.y = (float)rand()/float(RAND_MAX) * 8.0 - 3.0;

        enms[i].placeEnms(enms[i].posE);
        enms[i].sizeE.y = enms[i].sizeE.x = 0.3;    //(float)(rand() % 12)/50.0;
    }

    texDoor->loadTexture("images/door.png");
    //door->scroll(0.005);
    door->posE.x = 3.0;
    door->posE.y = 3.0;
    door->posE.z = -3.0;

    return true;

}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0,0.0, 0.0, 1.0, 0.0);
    glScalef(285.0, 285.0, 1.0);


    /////////////////////CHRISTIAN'S CODE
    if(landing){

    glPushMatrix();
        //snds->stopAllSounds();
        glScalef(3.8, 3.8, 1.0); //glScalef(1.3, 1.3, 1.0);
        landingImage->drawSquare(screenWidth, screenHeight); //draw landing image
        //menuImage->drawSquare(screenWidth, screenHeight); //draw menu image
        //snds->playSound("sounds/mistydungeon.wav"); //plays background music
        //snds->stopAllSounds();
        //snds->pauseSound("sounds/mistydungeon.wav");
    glPopMatrix();

    }

    //Displays Menu Image
    if(menuLevel){

    glPushMatrix();
        //snds->stopAllSounds();
        //snds->pauseSound("sounds/mistydungeon.wav");
        glScalef(3.8, 3.8, 1.0);
        menuImage->drawSquare(screenWidth, screenHeight); //draw menu image
        //snds->playSound("sounds/mistydungeon.wav");
    glPopMatrix();

    }

    //Displays help page
    if (helpLevel){

    glPushMatrix();
        glScalef(3.8, 3.8, 1.0); //(0.5, 0.5, 1.0) for small, (1.3, 1.3, 1.0) for full
        helpImage->drawSquare(screenWidth, screenHeight); //draw menu image
    glPopMatrix();

    }

    //Displays the credits page
    if (creditLevel){
    glPushMatrix();
        glScalef(3.8, 3.8, 1.0);
        creditImage->drawSquare(screenWidth, screenHeight); //draw menu image
    glPopMatrix();
    }

    //Displays Pause Menu
    if(pauseLevel){

    glPushMatrix();
        glScalef(3.8, 3.8, 1.0);
        pauseImage->drawSquare(screenWidth, screenHeight); //draw menu image
    glPopMatrix();

    }


    /////////////////////CHRISTIAN'S CODEw

    if(liveLevel1){ //Level 1 Setup

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGroundLevel1->plxTexture->tex);
        backGroundLevel1->scroll(0.005* myPly->speedMulti);//0.005
        backGroundLevel1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, items->itemImage->tex);
        if(items->notPickedUp){
            items->itemScroll(0.007 * myPly->speedMulti);
            items->drawItem();
        }

        if(items->iT->getTicks() > 100) {
        items->xMin += 1.0/8.0;
        items->xMax += 1.0/8.0;

        if(collided->detectItem(myPly->playerPos.x, myPly->playerPos.y, myPly->radiusPlayer, items->itemPos.x, items->itemPos.y, items->itemRadius) && items->notPickedUp) {
            switch(items->itemType) {
            case 0:
                backGround1->parallaxInit("images/visibility2.png");
                items->notPickedUp = false;
                cout << "LIGHT" << endl;
                break;
            case 1:
                myPly->lightDmg += 1.0;
                myPly->HeavyDmg += 1.0;
                items->notPickedUp = false;
                break;
            case 2:
                myPly->speedMulti += 1.0;
                items->notPickedUp = false;
                break;
            }
        }
        items->iT->resetTime();
        }
    glPopMatrix();

    //Door
    glPushMatrix();
        glScalef(0.5, 0.5, 1.0);
        door->tex = texDoor->tex;

        door->scroll(0.007 * myPly->speedMulti); //0.005

        door->placeEnms(door->posE);
        door->moveCausedByPlayer();
        door->drawEnms();

    glPopMatrix();

    //Player
    glPushMatrix();
        //glScalef(2.0, 2.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        glTranslatef(myPly->playerPos.x , myPly->playerPos.y, myPly->playerPos.z);
        myPly->drawPlayer();

    if(timer->getTicks() > 150)
    {
        myPly->actions();
        timer->resetTime();
    }
    glPopMatrix();

    //Enemies
    for(int i = 0; i < numOfEnms; i++){
        if(enms[i].isAlive){
            if(enms[i].posE.x > 5.0){
                enms[i].actionTrigger = enms[i].LEFT;           //Enemy moving Left because hit bounding box of game
                enms[i].facingDirection = enms[i].LEFT;
                enms[i].xSpeed = -0.005;
            }
            else if(enms[i].posE.x < -5.0){
                enms[i].actionTrigger = enms[i].RIGHT;          //Enemy moving Right because hit bounding box of game
                enms[i].facingDirection = enms[i].RIGHT;
                enms[i].xSpeed =  0.005;
            }
            else if(enms[i].posE.y < -5.0){
                enms[i].actionTrigger = enms[i].UP;             //Enemy moving Up because hit bounding box of game
                enms[i].facingDirection = enms[i].UP;
                enms[i].ySpeed =  0.005;
            }
            else if(enms[i].posE.y > 5.0){
                enms[i].actionTrigger = enms[i].DOWN;           //Enemy moving Down because hit bounding box of game
                enms[i].facingDirection = enms[i].DOWN;
                enms[i].ySpeed = -0.005;
            }

            enms[i].moveCausedByPlayer();                       //Enemy moving in relation to Player movements: setting values for xSpeed2 and ySpeed2

            if(collided->detectAggro(myPly, enms[i]))           //Checking if Enemy is Aware of the Player
                enms[i].actionTrigger = enms[i].HUNT;
            else                                                //If the Enemy is Unaware of the Player
                enms[i].randAction();                           //Random Enemy movement: setting values for xSpeed and ySpeed

            //Enemies is hit if Player is Attacking, within Attack Range, and  Player correctly Facing the Enemy
            if(myPly->isAttacking && collided->atkCollision(myPly, enms[i]) && collided->collisionOrientation(myPly, enms[i])){
                if(myPly->actionTrigger == myPly->HATK){
                    enms[i].dmgTaken = myPly->HeavyDmg;
                }
                else{
                    enms[i].dmgTaken = myPly->lightDmg;
                }
                //cout << "Enemy Health: " << enms[i].enemyHealth << endl;
                enms[i].alreadyHit = true;
                enms[i].actionTrigger = enms[i].HIT;
            }
            //Else if the Player is not Invulnerable and Player within Enemies' Attack Range
            else if(!myPly->invulnerable && !enms[i].isAttacking && collided->detectCollision(myPly, enms[i])){
                myPly->facingDirection = collided->enemyHitPlayer(myPly, &enms[i], backGround);
                myPly->actionTrigger = myPly->HIT;
                if(enms[i].isAttacking)
                    //cout << "Enemy is Attacking\n";


                enms[i].moveCausedByPlayer();
            }

            enms[i].posE.x += (enms[i].xSpeed + (enms[i].xSpeed2* myPly->speedMulti));           //Enemy Total X movement
            enms[i].posE.y += (enms[i].ySpeed + (enms[i].ySpeed2* myPly->speedMulti));           //Enemy Total Y movement
            //if(myPly->playerPos)

            enms[i].actionsEnms();                                          //Changing Animation to match Enemy's Random movement
            enms[i].drawEnms();                                             //Draw enemies
        }
    }

    //Background1
    /*
    glPushMatrix();
        //glTranslatef(0.0, 0.0, backGround1->plxPos.z);
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
        backGround1->renderBack(screenWidth, screenHeight);
    glPopMatrix();
    */

    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-9.0, 4.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();
    }


    if(liveLevel2){ //Level 2 Setup

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGroundLevel2->plxTexture->tex);
        backGroundLevel2->scroll(0.005* myPly->speedMulti);//0.005
        backGroundLevel2->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, items->itemImage->tex);
        if(items->notPickedUp){
            items->itemScroll(0.007 * myPly->speedMulti);
            items->drawItem();
        }

        if(items->iT->getTicks() > 100) {
        items->xMin += 1.0/8.0;
        items->xMax += 1.0/8.0;

        if(collided->detectItem(myPly->playerPos.x, myPly->playerPos.y, myPly->radiusPlayer, items->itemPos.x, items->itemPos.y, items->itemRadius) && items->notPickedUp) {
            switch(items->itemType) {
            case 0:
                backGround1->parallaxInit("images/visibility2.png");
                items->notPickedUp = false;
                cout << "LIGHT" << endl;
                break;
            case 1:
                myPly->lightDmg += 1.0;
                myPly->HeavyDmg += 1.0;
                items->notPickedUp = false;
                break;
            case 2:
                myPly->speedMulti += 1.0;
                items->notPickedUp = false;
                break;
            }
        }
        items->iT->resetTime();
        }
    glPopMatrix();

    //Player
    glPushMatrix();
        //glScalef(2.0, 2.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        glTranslatef(myPly->playerPos.x , myPly->playerPos.y, myPly->playerPos.z);
        myPly->drawPlayer();


    if(timer->getTicks() > 150)
    {
        myPly->actions();
        timer->resetTime();
    }
    glPopMatrix();

    //Enemies
    for(int i = 0; i < numOfEnms; i++){
        if(enms[i].isAlive){
            if(enms[i].posE.x > 5.0){
                enms[i].actionTrigger = enms[i].LEFT;           //Enemy moving Left because hit bounding box of game
                enms[i].facingDirection = enms[i].LEFT;
                enms[i].xSpeed = -0.005;
            }
            else if(enms[i].posE.x < -5.0){
                enms[i].actionTrigger = enms[i].RIGHT;          //Enemy moving Right because hit bounding box of game
                enms[i].facingDirection = enms[i].RIGHT;
                enms[i].xSpeed =  0.005;
            }
            else if(enms[i].posE.y < -5.0){
                enms[i].actionTrigger = enms[i].UP;             //Enemy moving Up because hit bounding box of game
                enms[i].facingDirection = enms[i].UP;
                enms[i].ySpeed =  0.005;
            }
            else if(enms[i].posE.y > 5.0){
                enms[i].actionTrigger = enms[i].DOWN;           //Enemy moving Down because hit bounding box of game
                enms[i].facingDirection = enms[i].DOWN;
                enms[i].ySpeed = -0.005;
            }

            enms[i].moveCausedByPlayer();                       //Enemy moving in relation to Player movements: setting values for xSpeed2 and ySpeed2

            if(collided->detectAggro(myPly, enms[i]))           //Checking if Enemy is Aware of the Player
                enms[i].actionTrigger = enms[i].HUNT;
            else                                                //If the Enemy is Unaware of the Player
                enms[i].randAction();                           //Random Enemy movement: setting values for xSpeed and ySpeed

            //Enemies is hit if Player is Attacking, within Attack Range, and  Player correctly Facing the Enemy
            if(myPly->isAttacking && collided->atkCollision(myPly, enms[i]) && collided->collisionOrientation(myPly, enms[i])){
                if(myPly->actionTrigger == myPly->HATK){
                    enms[i].dmgTaken = myPly->HeavyDmg;
                }
                else{
                    enms[i].dmgTaken = myPly->lightDmg;
                }
                //cout << "Enemy Health: " << enms[i].enemyHealth << endl;
                enms[i].alreadyHit = true;
                enms[i].actionTrigger = enms[i].HIT;
            }
            //Else if the Player is not Invulnerable and Player within Enemies' Attack Range
            else if(!myPly->invulnerable && !enms[i].isAttacking && collided->detectCollision(myPly, enms[i])){
                myPly->facingDirection = collided->enemyHitPlayer(myPly, &enms[i], backGround);
                myPly->actionTrigger = myPly->HIT;
                if(enms[i].isAttacking)
                    //cout << "Enemy is Attacking\n";


                enms[i].moveCausedByPlayer();
            }

            enms[i].posE.x += (enms[i].xSpeed + (enms[i].xSpeed2* myPly->speedMulti));           //Enemy Total X movement
            enms[i].posE.y += (enms[i].ySpeed + (enms[i].ySpeed2* myPly->speedMulti));           //Enemy Total Y movement
            //if(myPly->playerPos)

            enms[i].actionsEnms();                                          //Changing Animation to match Enemy's Random movement
            enms[i].drawEnms();                                             //Draw enemies
        }
    }


    //Background1
    glPushMatrix();
        //glTranslatef(0.0, 0.0, backGround1->plxPos.z);
        glScalef(5.0, 5.0, 1.0);

        glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
        backGround1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-9.0, 4.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();
    }

    if(liveLevel3){ //Level 3 Setup

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGroundLevel3->plxTexture->tex);
        backGroundLevel3->scroll(0.005 * myPly->speedMulti);//0.005
        backGroundLevel3->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, items->itemImage->tex);
        if(items->notPickedUp){
            items->itemScroll(0.007 * myPly->speedMulti);
            items->drawItem();
        }

        if(items->iT->getTicks() > 100) {
        items->xMin += 1.0/8.0;
        items->xMax += 1.0/8.0;

        if(collided->detectItem(myPly->playerPos.x, myPly->playerPos.y, myPly->radiusPlayer, items->itemPos.x, items->itemPos.y, items->itemRadius) && items->notPickedUp) {
            switch(items->itemType) {
            case 0:
                backGround1->parallaxInit("images/visibility2.png");
                items->notPickedUp = false;
                cout << "LIGHT" << endl;
                break;
            case 1:
                myPly->lightDmg += 1.0;
                myPly->HeavyDmg += 1.0;
                items->notPickedUp = false;
                break;
            case 2:
                myPly->speedMulti += 1.0;
                items->notPickedUp = false;
                break;
            }
        }
        items->iT->resetTime();
        }
    glPopMatrix();

    //Player
    glPushMatrix();
        //glScalef(2.0, 2.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        glTranslatef(myPly->playerPos.x , myPly->playerPos.y, myPly->playerPos.z);
        myPly->drawPlayer();


    if(timer->getTicks() > 150)
    {
        myPly->actions();
        timer->resetTime();
    }
    glPopMatrix();

    //Enemies
    for(int i = 0; i < numOfEnms; i++){
        if(enms[i].isAlive){
            if(enms[i].posE.x > 5.0){
                enms[i].actionTrigger = enms[i].LEFT;           //Enemy moving Left because hit bounding box of game
                enms[i].facingDirection = enms[i].LEFT;
                enms[i].xSpeed = -0.005;
            }
            else if(enms[i].posE.x < -5.0){
                enms[i].actionTrigger = enms[i].RIGHT;          //Enemy moving Right because hit bounding box of game
                enms[i].facingDirection = enms[i].RIGHT;
                enms[i].xSpeed =  0.005;
            }
            else if(enms[i].posE.y < -5.0){
                enms[i].actionTrigger = enms[i].UP;             //Enemy moving Up because hit bounding box of game
                enms[i].facingDirection = enms[i].UP;
                enms[i].ySpeed =  0.005;
            }
            else if(enms[i].posE.y > 5.0){
                enms[i].actionTrigger = enms[i].DOWN;           //Enemy moving Down because hit bounding box of game
                enms[i].facingDirection = enms[i].DOWN;
                enms[i].ySpeed = -0.005;
            }

            enms[i].moveCausedByPlayer();                       //Enemy moving in relation to Player movements: setting values for xSpeed2 and ySpeed2

            if(collided->detectAggro(myPly, enms[i]))           //Checking if Enemy is Aware of the Player
                enms[i].actionTrigger = enms[i].HUNT;
            else                                                //If the Enemy is Unaware of the Player
                enms[i].randAction();                           //Random Enemy movement: setting values for xSpeed and ySpeed

            //Enemies is hit if Player is Attacking, within Attack Range, and  Player correctly Facing the Enemy
            if(myPly->isAttacking && collided->atkCollision(myPly, enms[i]) && collided->collisionOrientation(myPly, enms[i])){
                if(myPly->actionTrigger == myPly->HATK){
                    enms[i].dmgTaken = myPly->HeavyDmg;
                }
                else{
                    enms[i].dmgTaken = myPly->lightDmg;
                }
                //cout << "Enemy Health: " << enms[i].enemyHealth << endl;
                enms[i].alreadyHit = true;
                enms[i].actionTrigger = enms[i].HIT;
            }
            //Else if the Player is not Invulnerable and Player within Enemies' Attack Range
            else if(!myPly->invulnerable && !enms[i].isAttacking && collided->detectCollision(myPly, enms[i])){
                myPly->facingDirection = collided->enemyHitPlayer(myPly, &enms[i], backGround);
                myPly->actionTrigger = myPly->HIT;
                if(enms[i].isAttacking)
                    //cout << "Enemy is Attacking\n";


                enms[i].moveCausedByPlayer();
            }

            enms[i].posE.x += (enms[i].xSpeed + (enms[i].xSpeed2* myPly->speedMulti));           //Enemy Total X movement
            enms[i].posE.y += (enms[i].ySpeed + (enms[i].ySpeed2* myPly->speedMulti));           //Enemy Total Y movement
            //if(myPly->playerPos)

            enms[i].actionsEnms();                                          //Changing Animation to match Enemy's Random movement
            enms[i].drawEnms();                                             //Draw enemies
        }
    }


    //Background1
    glPushMatrix();
        //glTranslatef(0.0, 0.0, backGround1->plxPos.z);
        glScalef(5.0, 5.0, 1.0);

        glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
        backGround1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-9.0, 4.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();
    }





}

void _glScene::resizeGLScene(int width, int height)
{
    screenWidth = width;
    screenHeight = height;

    float aspectRatio = (float)width/(float)height;

    glViewport(0.0, 0.0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0, aspectRatio, 0.1, 100.0);              //Can change this to glOrtho()
    glOrtho(-width, width, -height, height, 0.1, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
///*
int _glScene::winMsg(	HWND	hWnd,			// Handle For This Window
							UINT	uMsg,			// Message For This Window
							WPARAM	wParam,			// Additional Message Information
							LPARAM	lParam)
{
    kbMs->wParam = wParam;

    switch (uMsg)									// Check For Windows Messages
	{
		case WM_KEYDOWN:							// Is A Key Being Held Down?
		{
		    //kbMs->keyPressed(myPly);
            //for(int j = 0; j < numOfEnms; j++)
            kbMs->moveEnv(backGroundLevel1, myPly, enms, items, numOfEnms, 0.005*myPly->speedMulti, door);
            kbMs->moveEnv(backGroundLevel2, myPly, enms, items, numOfEnms, 0.005*myPly->speedMulti, door);
            kbMs->moveEnv(backGroundLevel3, myPly, enms, items, numOfEnms, 0.005*myPly->speedMulti, door);
		    //kbMs->spotLight(backGround1, myPly);
			break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
            kbMs->keyUp(myPly, backGroundLevel1, enms, items, numOfEnms, door); //add door
            kbMs->keyUp(myPly, backGroundLevel2, enms, items, numOfEnms, door);
            kbMs->keyUp(myPly, backGroundLevel3, enms, items, numOfEnms, door);
            break;
		}

		case WM_LBUTTONDOWN:                        //Left mouse button down
        {
            kbMs->mouseDown(myPly, backGroundLevel1, LOWORD(lParam), HIWORD(lParam), door);
            kbMs->mouseDown(myPly, backGroundLevel2, LOWORD(lParam), HIWORD(lParam), door);
            kbMs->mouseDown(myPly, backGroundLevel3, LOWORD(lParam), HIWORD(lParam), door);
            break;
        }

        case WM_RBUTTONDOWN:                        //Right mouse button down
        {
            kbMs->mouseDown(myPly, backGroundLevel1, LOWORD(lParam), HIWORD(lParam), door);
            kbMs->mouseDown(myPly, backGroundLevel2, LOWORD(lParam), HIWORD(lParam), door);
            kbMs->mouseDown(myPly, backGroundLevel3, LOWORD(lParam), HIWORD(lParam), door);
            break;
        }

        case WM_MBUTTONDOWN:                        //Middle mouse button down
        {
            break;
        }

        case WM_RBUTTONUP:                          //Right mouse button up
        {
            kbMs->mouseUp(myPly, backGroundLevel1, door);
            kbMs->mouseUp(myPly, backGroundLevel2, door);
            kbMs->mouseUp(myPly, backGroundLevel3, door);
        }
        case WM_MBUTTONUP:                          //Middle mouse button up
        {
        }
        case WM_LBUTTONUP:                          //Left mouse button up
        {
            kbMs->mouseUp(myPly, backGroundLevel1, door);
            kbMs->mouseUp(myPly, backGroundLevel2, door);
            kbMs->mouseUp(myPly, backGroundLevel3, door);
            break;
        }

        case WM_MOUSEMOVE:                          //Detecting mouse movement
        {
            break;
        }

        case WM_MOUSEWHEEL:                         //Detection mouse scroll wheel movement
        {
            break;
        }
	}
}

