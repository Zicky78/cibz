#include "_glScene.h"
#include <_glLight.h>
#include <SOIL.h>

_glScene::_glScene()
{
    //ctor
    //screenWidth = GetSystemMetrics(SM_CXSCREEN);
    //screenHeight = GetSystemMetrics(SM_CYSCREEN);

    menu->landingLevel = true;

    menu->doneLoading= false;
    menu->liveLevel1 = false; //starts loading level 1, liveLevel1 = true;
    menu->liveLevel2 = false;
    menu->liveLevel3 = false;
    menu->liveLevel4 = false;
    menu->liveLevel5 = false;


    menu->menuLevel = false;
    menu->helpLevel = false;
    menu->pauseLevel = false;
    menu->creditLevel = false;

    //flags for transitions
    bool tran1 = false;
    bool tran2 = false;
    bool tran3 = false;
    bool tran4 = false;
    bool tran5 = false;
}

_glScene::~_glScene()
{
    //dtor
}
GLint _glScene::initGL()
{
    if(menu->newGame){
        glewInit();
        glShadeModel(GL_SMOOTH);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClearDepth(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        glEnable(GL_COLOR_MATERIAL);
        _glLight myLight(GL_LIGHT0);

        //Menues
        menu->menuInit();

        //On Screen Button
        button->buttonInit("images/wood.png", "start");

        //Player
        myPly->playerInit(9, 3);
        myPly->plyImage->loadTexture("images/knight.png");

        //Fonts
        fnts->initFonts("images/fantasyfont.png");

        //Items
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

        //Enemies
        numOfSumn = 0;

        //Visibility
        backGround1->parallaxInit("images/visibility.png");
        backGround1->plxPos.z = -2.0;

        //Door
        texDoor->loadTexture("images/door.png");
        //door->scroll(0.005);
        door->posE.x = 3.0;
        door->posE.y = 3.0;
        door->posE.z = -3.0;

        //UI
        texHearts->loadTexture("images/heart.png");
        for (int i = 0; i < 10; i++) {
            hearts[i].texH = texHearts->tex;
            if(i > 0) {
            hearts[i].heartPos.x = hearts[i-1].heartPos.x + 0.55;
            }
            cout << hearts[i].heartPos.x;
        }

        texBorder->loadTexture("images/itemui.png");
        ui->texB = texBorder->tex;

        texItems[0].loadTexture("images/light.png");
        ui->texI[0] = texItems[0].tex;

        texItems[1].loadTexture("images/attack.png");
        ui->texI[1] = texItems[1].tex;

        texItems[2].loadTexture("images/speed.png");
        ui->texI[2] = texItems[2].tex;

        //Shaders
        shd->initShader("shaders/v.vs", "shaders/f.fs");


    }


    if(menu->liveLevel1){
        //cout << "liveLevel1 Reached\n";
        backGroundLevel1->parallaxInit("images/level1.png", 10.0, 5.0);              //Bind our only background parallax to level 1 texture, we will
        xPlayingField = yPlayingField = 15.0;

        fnts->buildFont("Level 1", 9.0);

        numOfEnms = 10;                                                         //Initialize number of enemies for level1

        texEnms->loadTexture("images/wolf4.png");
        for(i = 0; i < numOfEnms/2; i++){
            enms[i].levelCount = 1;
            enms[i].enmsInit('w', 5.0, 13.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
            enms[i].placeEnms(enms[i].posE);
        }

        texEnms->loadTexture("images/plantEnemy.png");
        for(i = numOfEnms/2; i < numOfEnms; i++){
            enms[i].levelCount = 1;
            enms[i].enmsInit('p', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
            enms[i].placeEnms(enms[i].posE);
        }

        //Enemy counter
        eCount = numOfEnms;
        eCounter->initFonts("images/fantasyfont.png");
        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);

        swarmTimer->startTimer();

        menu->doneLoading = true;        //This should ALWAYS  be the last line
    }
    else if(menu->liveLevel2){
        backGroundLevel1->parallaxInit("images/level2.png");
        xPlayingField = yPlayingField = 20.0;

        fnts->buildFont("Level 2", 9.0);

        numOfEnms = 20;
        texEnms->loadTexture("images/wolf4.png");
        for(i = 0; i < 10; i++){
            enms[i].levelCount = 2;
            enms[i].enmsInit('w', 5.0, 13.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/plantEnemy.png");
        for(i = 10; i < 15; i++){
            enms[i].levelCount = 2;
            enms[i].enmsInit('p', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/screamer.png");
        for(i = 15; i < numOfEnms; i++){
            enms[i].levelCount = 2;
            enms[i].enmsInit('s', 9.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        //Enemy counter
        eCount = numOfEnms;
        eCounter->initFonts("images/fantasyfont.png");
        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);

        swarmTimer->startTimer();

        menu->doneLoading = true;        //This should ALWAYS  be the last line
    }
    else if(menu->liveLevel3){
        backGroundLevel1->parallaxInit("images/level3.jpg");
        xPlayingField = yPlayingField = 25.0;

        fnts->buildFont("Level 3", 9.0);

        numOfEnms = 30;

        texEnms->loadTexture("images/wolf4.png");
        for(i = 0; i < 10; i++){
            enms[i].levelCount = 3;
            enms[i].enmsInit('w', 5.0, 13.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/plantEnemy.png");
        for(i = 10; i < 15; i++){
            enms[i].levelCount = 3;
            enms[i].enmsInit('p', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/screamer.png");
        for(i = 15; i < 20; i++){
            enms[i].levelCount = 3;
            enms[i].enmsInit('s', 9.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/mage.png");
        for(i = 20; i < numOfEnms; i++){
            enms[i].levelCount = 3;
            enms[i].enmsInit('m', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        //Enemy counter
        eCount = numOfEnms;
        eCounter->initFonts("images/fantasyfont.png");
        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);

        swarmTimer->startTimer();

        menu->doneLoading = true;        //This should ALWAYS  be the last line
    }
    else if(menu->liveLevel4){
        backGroundLevel1->parallaxInit("images/level4.jpg");
        xPlayingField = yPlayingField = 30.0;

        fnts->buildFont("Level 4", 9.0);

        numOfEnms = 40;
        numOfSumn = 0;
        texEnms->loadTexture("images/wolf4.png");
        for(i = 0; i < 10; i++){
            enms[i].levelCount = 4;
            enms[i].enmsInit('w', 5.0, 13.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/plantEnemy.png");
        for(i = 10; i < 20; i++){
            enms[i].levelCount = 4;
            enms[i].enmsInit('p', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/screamer.png");
        for(i = 20; i < 25; i++){
            enms[i].levelCount = 4;
            enms[i].enmsInit('s', 9.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/mage.png");
        for(i = 25; i < 35; i++){
            enms[i].levelCount = 4;
            enms[i].enmsInit('m', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/fairy.png");
        for(i = 35; i < numOfEnms; i++){
            enms[i].levelCount = 4;
            enms[i].enmsInit('f', 6.0, 5.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        //Enemy counter
        eCount = numOfEnms;
        eCounter->initFonts("images/fantasyfont.png");
        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);
        cout << "ECount for level 4: " << eCount << endl;

        swarmTimer->startTimer();

        menu->doneLoading = true;        //This should ALWAYS  be the last line
    }
    else if(menu->liveLevel5){
        backGroundLevel1->parallaxInit("images/level5.jpg");
        xPlayingField = yPlayingField = 30.0;

        fnts->buildFont("Level 5", 9.0);

        numOfEnms = 45;
        numOfSumn = 0;
        texEnms->loadTexture("images/wolf4.png");
        for(i = 0; i < 10; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('w', 5.0, 13.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/plantEnemy.png");
        for(i = 10; i < 15; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('p', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/screamer.png");
        for(i = 15; i < 20; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('s', 9.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/mage.png");
        for(i = 20; i < 30; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('m', 6.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/fairy.png");
        for(i = 30; i < 35; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('f', 6.0, 5.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        texEnms->loadTexture("images/ogre3.png");
        for(i = 35; i < numOfEnms; i++){
            enms[i].levelCount = 5;
            enms[i].enmsInit('o', 9.0, 4.0);
            enms[i].tex = texEnms->tex;
            enms[i].posE.x = (float)rand()/float(RAND_MAX) * (2 * xPlayingField) - xPlayingField;
            enms[i].posE.y = (float)rand()/float(RAND_MAX) * (2 * yPlayingField) - yPlayingField;
        }

        //Enemy counter
        eCount = numOfEnms;
        eCounter->initFonts("images/fantasyfont.png");
        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);
        cout << "ECount for level 5: " << eCount << endl;

        swarmTimer->startTimer();

        menu->doneLoading = true;        //This should ALWAYS  be the last line
    }

     timer->startTimer();
    //Menu Images

    /*
    //cout << "menu init" << endl;
    menu->landingImage->loadTexture("images/MainMenu.png");
    //menuPic->landingImage->menuInit("images/MainMenu.png"); //loads landing image
    //menuPic->menuImage->menuInit("images/MenuSelection.png"); //loads menu image //mine
    menu->menuImage->loadTexture("images/MenuSelection.png");
    //menuPic->helpImage->menuInit("images/help.png"); //loads help image
    menu->helpImage->loadTexture("images/help.png");
    //menuPic->pauseImage->menuInit("images/pause.png"); //loads pause image
    menu->pauseImage->loadTexture("images/pause.png");
    //menuPic->creditImage->menuInit("images/Credits1.png"); //loads credits image
    menu->creditImage->loadTexture("images/Credits1.png");




    backGroundLevel1->parallaxInit("images/forest2.png");
    backGroundLevel2->parallaxInit("images/village.png");
    backGroundLevel3->parallaxInit("images/grasstile.png");

    backGround->parallaxInit("images/dungeonFloor.jpg", 10.0, 5.0);
    backGround1->parallaxInit("images/visibility.png");
    backGround1->plxPos.z = -2.0;




    //Enemies
    numOfEnms = 2;
    //texEnms->loadTexture("images/fairy.png");
    //texEnms->loadTexture("images/mage.png");
    texEnms->loadTexture("images/ogre3.png");
    //texEnms->loadTexture("images/plantEnemy.png");
    //texEnms->loadTexture("images/screamer.png");
    //texEnms->loadTexture("images/wolf4.png");
    for(int i = 0; i < numOfEnms; i++){
        //enms[i].enmsInit('f', 6.0, 5.0);
        //enms[i].enmsInit('m', 6.0, 4.0);
        enms[i].enmsInit('o', 9.0, 4.0);
        //enms[i].enmsInit('p', 6.0, 4.0);
        //enms[i].enmsInit('s', 9.0, 4.0);
        //enms[i].enmsInit('w', 5.0, 13.0);


        enms[i].tex = texEnms->tex;
        enms[i].enemyHealth = 3;
        enms[i].posE.x = (float)rand()/float(RAND_MAX) * 8.0 - 3.0;
        enms[i].posE.y = (float)rand()/float(RAND_MAX) * 8.0 - 3.0;

        enms[i].placeEnms(enms[i].posE);
        //enms[i].sizeE.y = enms[i].sizeE.x = 0.3;    //(float)(rand() % 12)/50.0;
    }
*/

    return true;

}

GLint _glScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0,0.0, 0.0, 1.0, 0.0);
    glScalef(285.0, 285.0, 1.0);


    /////////////////////CHRISTIAN'S CODE
    if(menu->landing){

    glPushMatrix();
        //snds->stopAllSounds();
        glScalef(4.0, 4.0, 1.0); //glScalef(1.3, 1.3, 1.0);
        glBindTexture(GL_TEXTURE_2D, menu->landingImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'l'); //draw landing image
        //menuImage->drawSquare(screenWidth, screenHeight); //draw menu image
        //snds->playSound("sounds/mistydungeon.wav"); //plays background music
        //snds->stopAllSounds();
        //snds->pauseSound("sounds/mistydungeon.wav");
    glPopMatrix();

    }

    //Displays Menu Image
    if(menu->menuLevel){

    glPushMatrix();
        //snds->stopAllSounds();
        //snds->pauseSound("sounds/mistydungeon.wav");
        glScalef(4.0, 4.0, 1.0); //glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, menu->menuImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'm'); //draw menu image
        //snds->playSound("sounds/mistydungeon.wav");
        glPushMatrix();
            glBindTexture(GL_TEXTURE_2D, button->buttonTexture->tex);
            //button->buttonPos.x = screenWidth/screenHeight * 0.93;
            //button->buttonPos.y = screenWidth/screenHeight * 0.51;
            //button->drawButton();
            //newGameBtn->drawButton();
            //helpBtn->drawButton();
            //creditBtn->drawButton();
            //exitBtn->drawButton();
            lastMenu = "main";
        glPopMatrix();
    glPopMatrix();
    }

    //Displays new Menu (from pause)
    if(menu->newMenu){
    glPushMatrix();
        glScalef(4.0, 4.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, menu->newMenuImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'r'); //draw menu image
        //resumeBtn->drawButton();
        //newNewBtn->drawButton();
        //newHelpBtn->drawButton();
        //newCreditBtn->drawButton();
        //newExitBtn->drawButton();
        lastMenu = "new";
    glPopMatrix();
    }

    //Displays Pause Menu
    if(menu->pauseLevel){

    glPushMatrix();
        glScalef(4.0, 4.0, 1.0); //(0.5, 0.5, 1.0) for small, (1.3, 1.3, 1.0) for full
        glBindTexture(GL_TEXTURE_2D, menu->pauseImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'p'); //draw menu image
        //pauseQuitBtn->drawButton();
        //pausePlayBtn->drawButton();
        //pauseHelpBtn->drawButton();
        //pauseMenuBtn->drawButton();
        lastMenu = "pause";
    glPopMatrix();

    }

    //Displays help page
    if (menu->helpLevel){

    glPushMatrix();
        glScalef(3.9, 3.9, 1.0); //(0.5, 0.5, 1.0) for small, (1.3, 1.3, 1.0) for full; (5.0, 5.0, 1.0) new default
        glBindTexture(GL_TEXTURE_2D, menu->helpImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'h'); //draw menu image
        //helpBackBtn->drawButton();
    glPopMatrix();

    }

    //Displays the credits page
    if (menu->creditLevel){
    glPushMatrix();
        glScalef(3.9, 3.9, 1.0);
        glBindTexture(GL_TEXTURE_2D, menu->creditImage->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
        //creditsBackBtn->drawButton();
    glPopMatrix();
    }

    //Transition menus
    if(menu->tran1){
        glPushMatrix();
        glScalef(3.9,3.9,1.0);
        glBindTexture(GL_TEXTURE_2D, menu->transition1->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
    glPopMatrix();
    }
    if(menu->tran2){
        glPushMatrix();
        glScalef(3.9,3.9,1.0);
        glBindTexture(GL_TEXTURE_2D, menu->transition2->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
    glPopMatrix();
    }
    if(menu->tran3){
        glPushMatrix();
        glScalef(3.9,3.9,1.0);
        glBindTexture(GL_TEXTURE_2D, menu->transition3->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
    glPopMatrix();
    }
    if(menu->tran4){
        glPushMatrix();
        glScalef(3.9,3.9,1.0);
        glBindTexture(GL_TEXTURE_2D, menu->transition4->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
    glPopMatrix();
    }
    if(menu->tran5){
        glPushMatrix();
        glScalef(3.9,3.9,1.0);
        glBindTexture(GL_TEXTURE_2D, menu->transition5->tex);
        menu->drawSquare(screenWidth, screenHeight, 'c'); //draw menu image
    glPopMatrix();
    }




    /////////////////////CHRISTIAN'S CODEw

    //if(menu->liveLevel1){ //Level 1 Setup
    if(!menu->landing && !menu->menuLevel && !menu->newMenu && !menu->pauseLevel && !menu->creditLevel && !menu->helpLevel
       && !menu->tran1 && !menu->tran2 && !menu->tran3 && !menu->tran4 && !menu->tran5){

    //Background
    glPushMatrix();
        glScalef(5.0, 5.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, backGroundLevel1->plxTexture->tex);
        backGroundLevel1->scroll(0.0009* myPly->speedMulti);//0.005
        backGroundLevel1->renderBack(screenWidth, screenHeight);
    glPopMatrix();

    //backGround1->scroll(false, "left", 0.003);

    //Items
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
        //door->moveCausedByPlayer();
        door->drawEnms();

    glPopMatrix();

    //Player
    glPushMatrix();
        //glScalef(2.0, 2.0, 1.0);
        glBindTexture(GL_TEXTURE_2D, myPly->plyImage->tex);
        glTranslatef(myPly->playerPos.x , myPly->playerPos.y, myPly->playerPos.z);

        glUseProgram(shd->program);                             //Start of the Shader
        shd->loc1 = glGetUniformLocation(shd->program, "invul");
        shd->loc2 = glGetUniformLocation(shd->program, "isBlk");
        shd->loc3 = glGetUniformLocation(shd->program, "isDdg");
        if(shd->loc1 != -1 || shd->loc2 != -1 || shd->loc3 != -1){
            glUniform1f(shd->loc1, myPly->invulnerable);
            glUniform1f(shd->loc2, myPly->isBlocking);
            glUniform1f(shd->loc3, myPly->isDodging);
        }
        else
            cout << "Location NOT found\n";

        myPly->drawPlayer();

        if(timer->getTicks() > 150)
        {
            myPly->actions();
            timer->resetTime();
        }


        glUseProgram(0);
    glPopMatrix();

    //Enemies
    for(int i = 0; i < numOfEnms + numOfSumn; i++){
        if(enms[i].isAlive){
            if(enms[i].posE.x > xPlayingField){
                enms[i].actionTrigger = enms[i].LEFT;           //Enemy moving Left because hit bounding box of game
                enms[i].facingDirection = enms[i].LEFT;
                enms[i].xSpeed = -0.005;
                enms[i].xSpeed2 = 0.0;
            }
            else if(enms[i].posE.x < -xPlayingField){
                enms[i].actionTrigger = enms[i].RIGHT;          //Enemy moving Right because hit bounding box of game
                enms[i].facingDirection = enms[i].RIGHT;
                enms[i].xSpeed =  0.005;
                enms[i].xSpeed2 = 0.0;
            }
            else if(enms[i].posE.y < -yPlayingField){
                enms[i].actionTrigger = enms[i].UP;             //Enemy moving Up because hit bounding box of game
                enms[i].facingDirection = enms[i].UP;
                enms[i].ySpeed =  0.005;
                enms[i].ySpeed2 = 0.0;
            }
            else if(enms[i].posE.y > yPlayingField){
                enms[i].actionTrigger = enms[i].DOWN;           //Enemy moving Down because hit bounding box of game
                enms[i].facingDirection = enms[i].DOWN;
                enms[i].ySpeed = -0.005;
                enms[i].ySpeed2 = 0.0;
            }

            enms[i].moveCausedByPlayer();                       //Enemy moving in relation to Player movements: setting values for xSpeed2 and ySpeed2

            if(collided->detectAggro(myPly, enms[i])){           //Checking if Enemy is Aware of the Player
                enms[i].actionTrigger = enms[i].HUNT;
                enms[i].deaf = true;

                if(enms[i].id == 'o' && enms[i].atkRange && enms[i].shouted){
                        myPly->facingDirection = collided->enemyHitPlayer(myPly, &enms[i], backGround1);
                    if(!myPly->invulnerable){
                        part->plyrBldGenerator(myPly, &enms[i]);
                        myPly->actionTrigger = myPly->HIT;
                        part->plyrBldGenerator(myPly, &enms[i]);
                        myPly->actions();
                    }
                        enms[i].moveCausedByPlayer();
                        enms[i].shouted = false;
                }
                else if((enms[i].id == 'm' || enms[i].id == 'f') && enms[i].shouted){       //Shouted variable used for projectile firing
                    part->projectileGenerator(&enms[i]);
                    enms[i].shouted = false;
                }
                else if(enms[i].id == 's' && enms[i].shouted){
                    for(j = 0; j < numOfEnms + numOfSumn; j++){
                        if(!enms[j].deaf)
                            enms[j].isCalled = true;
                            enms[j].calledPos.x = enms[i].posE.x;
                            enms[j].calledPos.y = enms[i].posE.y;
                            enms[j].timerRandAct->resetTime();
                    }
                    //cout << "Shouted\n";
                    enms[i].shouted = false;
                    myPly->slowed = 0.33;
                    myPly->slowedTimer->resetTime();
                }

            }
            else if(enms[i].isCalled){
                enms[i].actionTrigger = enms[i].CALLED;
            }
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
                part->enmyBldGenerator(&enms[i]);
                enms[i].alreadyHit = true;
                enms[i].actionTrigger = enms[i].HIT;
                enms[i].actionsEnms();
            }
            //Else if the Player is not Invulnerable and Player physically collides into an Enemy
            else if(!myPly->isDodging && !enms[i].isAttacking && collided->detectCollision(myPly, enms[i])){
                myPly->facingDirection = collided->enemyHitPlayer(myPly, &enms[i], backGroundLevel1);
                if(!myPly->invulnerable){
                    myPly->actionTrigger = myPly->HIT;
                    part->plyrBldGenerator(myPly, &enms[i]);
                    myPly->actions();
                }
                enms[i].moveCausedByPlayer();
            }

            if(enms[i].isCalled){
                enms[i].calledPos.x += (enms[i].xSpeed + (enms[i].xSpeed2 * myPly->speedMulti * myPly->slowed));
                enms[i].calledPos.y += (enms[i].ySpeed + (enms[i].ySpeed2 * myPly->speedMulti * myPly->slowed));
            }
            //enms[i].calledPos.x += (enms[i].xSpeed2 * myPly->speedMulti * myPly->slowed);
            //enms[i].calledPos.y += (enms[i].ySpeed2 * myPly->speedMulti * myPly->slowed);

            enms[i].posE.x += (enms[i].xSpeed + (enms[i].xSpeed2* myPly->speedMulti * myPly->slowed));           //Enemy Total X movement
            enms[i].posE.y += (enms[i].ySpeed + (enms[i].ySpeed2* myPly->speedMulti * myPly->slowed));           //Enemy Total Y movement
            //if(myPly->playerPos)

            //If the enough time passes and the player has NOT killed every enemy then All enemies within the swarm radius
            //will Hunt the player for a certain amount of time.
            if(swarmTimer->getTicks() > 60000){
                if(collided->detectCollision(0.0, 0.0, myPly->radiusPlayer, enms[i].posE.x, enms[i].posE.y, swarmRadius)){
                    enms[i].actionTrigger = enms[i].HUNT;
                    enms[i].deaf = true;
                    //cout << "Begin the HUNT\n";

                    if(myPly->isAttacking && collided->atkCollision(myPly, enms[i]) && collided->collisionOrientation(myPly, enms[i])){
                        if(myPly->actionTrigger == myPly->HATK){
                            enms[i].dmgTaken = myPly->HeavyDmg;
                        }
                        else{
                            enms[i].dmgTaken = myPly->lightDmg;
                        }
                        part->enmyBldGenerator(&enms[i]);
                        enms[i].alreadyHit = true;
                        enms[i].actionTrigger = enms[i].HIT;
                        //enms[i].actionsEnms();
                    }

                    if(swarmTimer->getTicks() > 72000){
                        swarmRadius += 5.0;
                        swarmTimer->resetTime();
                        //cout << "Swarm Radius: " << swarmRadius << "\nEnd the HUNT\n";
                    }
                }
            }
            enms[i].actionsEnms();                                          //Changing Animation to match Enemy's Random movement

            if(enms[i].enemyHealth <= 0){
                if(items->notPickedUp == false && (rand() % 100) < 10){
                    items->itemInit(8.0, 1.0);
                    switch(items->itemType) {
                    case 0:
                        items->itemImage->loadTexture("images/light.png");
                        break;
                    case 1:
                        items->itemImage->loadTexture("images/attack.png");
                        break;
                    case 2:
                        items->itemImage->loadTexture("images/speed.png");
                        break;
                    }
                }
                eCount--;
                //swarmTimer->resetTime();                                    //If the Player kills an enemy than it will reset the swarm timer
            }

            glUseProgram(shd->program);                             //Start of the Shader
            shd->loc1 = glGetUniformLocation(shd->program, "invul");
            shd->loc2 = glGetUniformLocation(shd->program, "isBlk");
            shd->loc3 = glGetUniformLocation(shd->program, "isDdg");
            if(shd->loc1 != -1 || shd->loc2 != -1 || shd->loc3 != -1){
                glUniform1f(shd->loc1, enms[i].alreadyHit);
                glUniform1f(shd->loc2, enms[i].isBlocking);
                glUniform1f(shd->loc3, enms[i].isDodging);
            }
            else
                cout << "Location NOT found\n";
            enms[i].drawEnms();                                             //Draw enemies
            glUseProgram(0);
        }
    }

    //Particles
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
        glPushMatrix();
            part->drawBlood();
            part->drawProjectile();
        glPopMatrix();
        part->updateBlood(myPly->speedMulti, myPly->slowed);
        part->updateProjectile(myPly, enms, numOfEnms, numOfSumn, menu->liveLevel5, myPly->speedMulti, myPly->slowed);
    glEnable(GL_TEXTURE_2D);
    //glDisable(GL_COLOR_MATERIAL);

    //Background1
    if(!menu->liveLevel1){
        glPushMatrix();
            //glTranslatef(0.0, 0.0, backGround1->plxPos.z);
            glScalef(5.0, 5.0, 1.0);
            glBindTexture(GL_TEXTURE_2D, backGround1->plxTexture->tex);
            backGround1->renderBack(screenWidth, screenHeight);
        glPopMatrix();
    }


    //Draw UI
    for(int i = 0; i < myPly->health; i++ ){

            hearts[i].drawHearts();
    }
    ui->drawBorder();

    if(ui->uiT->getTicks() > 100) {
        ui->xMinI += 1.0/8.0;
        ui->xMaxI += 1.0/8.0;

        string eRemain = "Enemies Remaining: ";
        eRemain += to_string(eCount);
        char eRe[eRemain.size() +1];
        strcpy(eRe, eRemain.c_str());
        eCounter->buildFont(eRe, 9.0);

        ui->uiT->resetTime();
    }

    ui->drawUIItems();



    //Fonts
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-9.0, 4.0, 1.0);
        fnts->drawFonts();
    glPopMatrix();

    //Enemy Counter
    glPushMatrix();
        //Need to make use an expendable character to translate line of character
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(3.7, 1.7, 1.0);
        glScalef(0.25, 0.25, 0.25);
        eCounter->drawFonts();
    glPopMatrix();

    if(!menu->doneLoading){
        for(i = 0; i < 10000; i++){
            part->bldDrops[i].alive = false;
            part->projectile[i].alive = false;
            part->trail[i].alive = false;
        }
        initGL();
    }

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
    //glOrtho(-aspectRatio, aspectRatio, -aspectRatio/aspectRatio, aspectRatio/aspectRatio, 0.1, 100.0);


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
            kbMs->menuNav(snds, menu);
            kbMs->moveEnv(backGroundLevel1, myPly, enms, items, numOfEnms + numOfSumn, 0.005*myPly->speedMulti*myPly->slowed, door, part);
		    //kbMs->spotLight(backGround1, myPly);
			break;
		}

		case WM_KEYUP:								// Has A Key Been Released?
		{
		    kbMs->menuNav(snds, menu);
		    kbMs->keyUp(menu);
            kbMs->keyUp(myPly, backGroundLevel1, enms, items, numOfEnms + numOfSumn, door, part); //add door
            break;
		}

		case WM_LBUTTONDOWN:                        //Left mouse button down
        {
            getOGLPos(LOWORD(lParam),HIWORD(lParam));
            cout << posMX << " " << posMY << endl;
            kbMs->menuNav(snds, menu);
            kbMs->mouseDown(button, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu); //for menu mouse clicks
            kbMs->mouseDown(newGameBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(helpBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(creditBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(exitBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(resumeBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu); //new menu buttons
            kbMs->mouseDown(newNewBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(newHelpBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(newCreditBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(newExitBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(helpBackBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu); //back buttons
            kbMs->mouseDown(creditsBackBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(pauseQuitBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu); //pause buttons
            kbMs->mouseDown(pauseHelpBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(pausePlayBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(pauseMenuBtn, menu, LOWORD(lParam), HIWORD(lParam), screenWidth, screenHeight, snds, lastMenu);
            kbMs->mouseDown(myPly, backGroundLevel1, LOWORD(lParam), HIWORD(lParam), items, enms, numOfEnms + numOfSumn, door, part);
            break;
        }

        case WM_RBUTTONDOWN:                        //Right mouse button down
        {
            kbMs->menuNav(snds, menu);
            kbMs->mouseDown(myPly, backGroundLevel1, LOWORD(lParam), HIWORD(lParam), items, enms, numOfEnms + numOfSumn, door, part);
            break;
        }

        case WM_MBUTTONDOWN:                        //Middle mouse button down
        {
            break;
        }

        case WM_RBUTTONUP:                          //Right mouse button up
        {
            kbMs->mouseUp(myPly, backGroundLevel1, items, enms, numOfEnms + numOfSumn, door, part);
        }
        case WM_MBUTTONUP:                          //Middle mouse button up
        {
        }
        case WM_LBUTTONUP:                          //Left mouse button up
        {
            kbMs->mouseUp(myPly, backGroundLevel1, items, enms, numOfEnms + numOfSumn, door, part);
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

