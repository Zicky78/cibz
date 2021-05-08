#include "_input.h"

_input::_input()
{
    prevMouseX = 0;
    prevMouseY = 0;
    //ctor

    tmr->startTimer();

    playSound = true;
}

_input::~_input()
{
    //dtor
}

void _input::menuNav(_sounds *snds, _menu *menu)
{
    switch(wParam)
    {
    case VK_RETURN: //if user presses enter, go to menu

        //transition cases
        if(!menu->landing && !menu->gameOver && !menu->gameWin){
            if(menu->tran1){
                menu->liveLevel1 = true;
                menu->tran1 = false;
            }
            else if(menu->tran2){
                menu->liveLevel2 = true;
                menu->tran2 = false;
            }
            else if(menu->tran3){
                menu->liveLevel3 = true;
                menu->tran3 = false;
            }
            else if(menu->tran4){
                menu->liveLevel4 = true;
                menu->tran4 = false;
            }
            else if(menu->tran5){
                menu->liveLevel5 = true;
                menu->tran5 = false;
            }
            menu->doneLoading = false;
        }
        else {
            //Scene->liveLevel1 = ! Scene->liveLevel1; //true

        // Scene->menuLevel = ! Scene->menuLevel; //false
        menu->gameOver = false;
        menu->gameWin = false;

        menu->liveLevel1 = false;
        menu->liveLevel2 = false;
        menu->liveLevel3 = false;
        menu->liveLevel4 = false;
        menu->liveLevel5 = false;

        menu->menuLevel = true;
        menu->landing = false;


        menu->pauseLevel = false; //enter main menu from pause

        // Scene->landing = ! Scene->landing;
        //cout << Scene->menuLevel << endl;
        menu->doneLoading = false; //false

        //Scene->snds->stopAllSounds();
        //Scene->snds->playMusic("sounds/mistydungeon.wav");
        snds->playMusic("sounds/mistydungeon.mp3");
        }
        break;

    case 0x4E: //if user presses n, start new game
        snds->stopAllSounds();
        menu->menuLevel = false;
        menu->newMenu = false;
        //menu->liveLevel1 = true;
        menu->tran1 = true;
        menu->currLevel = 1;
        menu->newGame = false;

        //menu->doneLoading = false; //false
        snds->playMusic("sounds/foyermusic.mp3");
        break;

    case 0x4D: //if user presses m, open new menu
        snds->stopAllSounds();
        menu->pauseLevel = false;
        menu->newMenu = true;

        //menu->doneLoading = false; //false
        break;

    case 0x52: //if user presses r, resumes last game
        if(!menu->holding && (menu->newMenu)){
        snds->stopAllSounds();
        menu->newMenu = false;

        if(menu->currLevel == 1){
            menu->liveLevel1 = ! menu->liveLevel1;
            snds->playMusic("sounds/foyermusic.mp3");
        }
        else if(menu->currLevel == 2){
            menu->liveLevel2 = ! menu->liveLevel2;
            snds->playMusic("sounds/level2music.mp3");
        }
        else if(menu->currLevel == 3){
            menu->liveLevel3 = ! menu->liveLevel3;
            snds->playMusic("sounds/level3music.mp3");
        }
        else if(menu->currLevel == 4){
            menu->liveLevel4 = ! menu->liveLevel4;
        }
        else if(menu->currLevel == 5){
            menu->liveLevel5 = ! menu->liveLevel5;
        }

        //menu->doneLoading = false; //false
        }
        break;

    case 0x48:  //if user presses h, go to help
        if(!menu->holding && (menu->menuLevel || menu->helpLevel || menu->pauseLevel || menu->newMenu)){ //if in menu or help or pause or newMenu
        menu->helpLevel = ! menu->helpLevel; //true
        menu->menuLevel = ! menu->menuLevel; //false
        //menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x50: //if user presses p, go to pause menu
        if(!menu->holding){
        menu->pauseLevel = ! menu->pauseLevel; //true
        //menu->liveLevel1 = ! menu->liveLevel1; //false
        snds->stopAllSounds();

        if(menu->currLevel == 1){
            menu->liveLevel1 = ! menu->liveLevel1;
            snds->playMusic("sounds/foyermusic.mp3");
        }
        else if(menu->currLevel == 2){
            menu->liveLevel2 = ! menu->liveLevel2;
            snds->playMusic("sounds/level2music.mp3");
        }
        else if(menu->currLevel == 3){
            menu->liveLevel3 = ! menu->liveLevel3;
            snds->playMusic("sounds/level3music.mp3");
        }
        else if(menu->currLevel == 4){
            menu->liveLevel4 = ! menu->liveLevel4;
        }
        else if(menu->currLevel == 5){
            menu->liveLevel5 = ! menu->liveLevel5;
        }

        //menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x43: //if user presses c, go to credits menu
        if(!menu->holding && (menu->menuLevel || menu->creditLevel || menu->newMenu)){
        menu->creditLevel = ! menu->creditLevel; //true
        menu->menuLevel = ! menu->menuLevel; //false
        //menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x32: //if user presses 2, start level 2
        snds->stopAllSounds();
        menu->liveLevel1 = false;
        //menu->liveLevel2 = true;
        menu->tran2 = true;

        //menu->doneLoading = false; //false
        snds->playMusic("sounds/level2music.mp3");
        menu->currLevel = 2;
        break;

    case 0x33: //if user presses 3, start level 3
        snds->stopAllSounds();
        menu->liveLevel2 = false;
        //menu->liveLevel3 = true;
        menu->tran3 = true;

        //menu->doneLoading = false; //false
        snds->playMusic("sounds/level3music.mp3");
        menu->currLevel = 3;
        break;

    case 0x34: //if user presses 4, start level 4
        snds->stopAllSounds();
        menu->liveLevel3 = false;
        //menu->liveLevel4 = true;
        menu->tran4 = true;

        //menu->doneLoading = false; //false
        snds->playMusic("sounds/level3music.mp3"); //change to level 4 music
        menu->currLevel = 4;
        break;

    case 0x35: //if user presses 5, start level 5
        snds->stopAllSounds();
        menu->liveLevel4 = false;
        //menu->liveLevel5 = true;
        menu->tran5 = true;

        //menu->doneLoading = false; //false
        snds->playMusic("sounds/level3music.mp3"); //change to level 5 music
        menu->currLevel = 5;
        break;
    case 0x36: //if user presses 6, start level 6 (Win)
        snds->stopAllSounds();
        menu->liveLevel5 = false;

        menu->gameWin = true;
        //menu->landing = true;

        menu->doneLoading = false; //false
        snds->playMusic("sounds/gamewin.mp3"); //change to level 5 music
        menu->currLevel = 6;
    break;

    }

}

void _input::keyUp(_menu* menu)
{
    switch(wParam){
    case VK_RETURN: //if user presses enter, go to menu

        //menu->holding = false;

    case 0x4E: //if user presses n, start new game


    case 0x48:  //if user presses h, go to help



    case 0x50: //if user presses p, go to pause menu



    case 0x43: //if user presses c, go to credits menu



    case 0x32: //if user presses 2, start level 2



    case 0x33: //if user presses 3, start level 3

        menu->holding = false;

        break;

    }

}


void _input::moveEnv(_parallax* plx, _player* ply, _enemies enem[], _items* item, int numOfEnem, float speed, _door* door, _particles * part)
{
    //cout << "wParam: " << wParam << endl;
    switch(wParam)
    {
    case 65:
    case VK_LEFT:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
            //Player
            ply->lFlag = true;
            ply->rFlag = false;
            ply->actionTrigger = ply->LWALK;
            ply->facingDirection = ply->LEFT;

            //Parallax
            plx->lFlag = true;
            plx->rFlag = false;

            //Item
            item->lFlag = true;
            item->rFlag = false;

            //Door
            door->lFlag = true;
            door->rFlag = false;

            //Enemies
            for(i = 0; i < numOfEnem; i++){
                enem[i].lFlag = true;
                enem[i].rFlag = false;
            }

            //Particles
            part->lFlag = true;
            part->rFlag = false;
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 68:
    case VK_RIGHT:
        if(!ply->isDodging && !ply->isAttacking && !ply->isBlocking){          //Can only move if NOT Dodging AND NOT  Attacking
            //Player
            ply->rFlag = true;
            ply->lFlag = false;
            ply->actionTrigger = ply->RWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->RIGHT;

            //Parallax
            plx->rFlag = true;
            plx->lFlag = false;

            //Item
            item->rFlag = true;
            item->lFlag = false;

            //Door
            door->rFlag = true;
            door->lFlag = false;

            //Enemies
            for(i = 0; i < numOfEnem; i++){
                enem[i].rFlag = true;
                enem[i].lFlag = false;
            }

            //Particles
            part->rFlag = true;
            part->lFlag = false;
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 87:
    case VK_UP:
        if(!ply->isDodging && !ply->isAttacking && !ply->isBlocking){         //Can only move if NOT Dodging AND NOT  Attacking
            //Player
            ply->uFlag = true;
            ply->dFlag = false;
            ply->actionTrigger = ply->UWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->UP;

            //Parallax
            plx->uFlag = true;
            plx->dFlag = false;

            //Item
            item->uFlag = true;
            item->dFlag = false;

            //Parallax
            door->uFlag = true;
            door->dFlag = false;

            //Enemies
            for(i = 0; i < numOfEnem; i++){
                enem[i].uFlag = true;
                enem[i].dFlag = false;
            }

            //Particles
            part->uFlag = true;
            part->dFlag = false;
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 83:
    case VK_DOWN:
        if(!ply->isDodging && !ply->isAttacking && !ply->isBlocking){          //Can only move if NOT Dodging AND NOT  Attacking
            ply->dFlag = true;
            ply->uFlag = false;
            ply->actionTrigger = ply->DWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->DOWN;

            plx->dFlag = true;
            plx->uFlag = false;

            //Item
            item->dFlag = true;
            item->uFlag = false;

            //Door
            door->dFlag = true;
            door->uFlag = false;


            //Enemies
            for(i = 0; i < numOfEnem; i++){
                enem[i].dFlag = true;
                enem[i].uFlag = false;
            }

            //Particles
            part->dFlag = true;
            part->uFlag = false;
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case VK_SPACE:
        /*
        if(!ply->isDodging && !ply->isAttacking && !ply->isBlocking){
            if(tmr->getTicks() > 2400){
                //Player
                ply->isDodging = true;
                ply->actionTrigger = ply->DODGE;
                //Parallax
                plx->isDodging = true;

                //Item
                item->isDodging = true;

                //Door
                door->isDodging = true;

                //Enemy
                for(i = 0; i < numOfEnem; i++){
                    enem[i].isDodging = true;
                }

                //Particles
                part->isDodging = true;

                tmr->resetTime();
            }
        }
        */
        if(!ply->isAttacking && !ply->isBlocking){
            if(tmr->getTicks() > 2400){
                //ply->dodgingLimit = true;                      //dodgingLimit will have a timer in the class that will reset to false and can't be turned to true for a few seconds, might need to be in every class that has isDodging bool
                if(!ply->isDodging){
                    //cout << "Dodge Reset Player Timer Reached\n";
                    ply->dodgingLimit = false;
                    ply->plyTimer->resetTime();
                }

                if(!ply->dodgingLimit){
                    //Player
                    ply->isDodging = true;
                    ply->invulnerable = true;
                    ply->actionTrigger = ply->DODGE;
                    ply->actions();
                    //Parallax
                    plx->isDodging = true;

                    //Item
                    item->isDodging = true;

                    //Door
                    door->isDodging = true;

                    //Enemy
                    for(i = 0; i < numOfEnem; i++){                             //Please note that dodging xSpeed2 and ySpeed2 are small increments
                        enem[i].isDodging = true;
                    }

                    //Particles
                    part->isDodging = true;
                }
                else if(ply->dodgingLimit){
                    //cout << "Dodge Else Reached\n";
                    //Player
                    ply->isDodging = false;
                    ply->actionTrigger = ply->DODGE;
                    //Parallax
                    plx->isDodging = false;

                    //Item
                    item->isDodging = false;

                    //Door
                    door->isDodging = false;

                    //Enemy
                    for(i = 0; i < numOfEnem; i++){                             //Please note that dodging xSpeed2 and ySpeed2 are small increments
                        enem[i].isDodging = false;
                    }

                    //Particles
                    part->isDodging = false;

                    tmr->resetTime();
                }
            }
        }
        break;

    case VK_SHIFT:
        if(!ply->isBlocking){
            //Player
            ply->actionTrigger = ply->ATK;
            ply->isAttacking = true;

            //Parallax
            plx->isAttacking = true;

            //Item
            item->isAttacking = true;

            //Door
            door->isAttacking = true;

            //Particles
            part->isAttacking = true;

            //Enemy
            for(i = 0; i < numOfEnem; i++){
                enem[i].xSpeed2 = 0.0;
                enem[i].ySpeed2 = 0.0;
                enem[i].plyAttacking = true;
            }
        }
        break;

    case VK_CAPITAL:
        if(!ply->isBlocking){
        //Player
            ply->actionTrigger = ply->HATK;
            ply->isAttacking = true;

            //Parallax
            plx->isAttacking = true;

            //Item
            item->isAttacking = true;

            //Door
            door->isAttacking = true;

            //Particles
            part->isAttacking = true;

            //Enemy
            for(i = 0; i < numOfEnem; i++){
                enem[i].xSpeed2 = 0.0;
                enem[i].ySpeed2 = 0.0;
                enem[i].plyAttacking = true;
            }
        }
        break;

    case 67:                            //C key for Blocking
        //Player
        ply->isBlocking = true;
        ply->actionTrigger = ply->BLOCK;
        ply->invulnerable = true;

        //Parallax
        plx->isBlocking = true;

        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].isBlocking = true;
            enem[i].xSpeed2 = 0.0;
            enem[i].ySpeed2 = 0.0;
        }

        //Item
        item->isBlocking = true;

        //Door
        door->isBlocking = true;

        //Particles
        part->isBlocking = true;
        break;
    }
}

void _input::keyUp(_player* ply, _parallax* plx, _enemies enem[], _items* item, int numOfEnem, _door* door, _particles* part)
{
    cout << "Key Up wParam: " << wParam << endl;

   // menu->holding = false;

    switch(wParam)
    {
    case 65:                          //A key is pressed
    case VK_LEFT:
        //cout << "reset lflags\n";
        ply->lFlag = false;
        plx->lFlag = false;

        //Item
        item->lFlag = false;

        //Door
        door->lFlag = false;

        //Particles
        part->lFlag = false;

        //Enemies
        for(i = 0; i < numOfEnem; i++){
            enem[i].lFlag = false;
        }

        if(ply->uFlag){
            ply->actionTrigger = ply->UWALK;
            ply->facingDirection = ply->UP;

        }
        else if(ply->dFlag){
            ply->actionTrigger = ply->DWALK;
            ply->facingDirection = ply->DOWN;

        }
        else{
            ply->actionTrigger = ply->STAND;
        }
        break;

    case 68:                          //D key is pressed
    case VK_RIGHT:
        //cout << "reset rflags\n";
        ply->rFlag = false;
        plx->rFlag = false;

        //Item
        item->rFlag = false;

        //Door
        door->rFlag = false;

        //Particles
        part->rFlag = false;

        //Enemies
        for(i = 0; i < numOfEnem; i++){
            enem[i].rFlag = false;
        }

        if(ply->uFlag){
            ply->actionTrigger = ply->UWALK;
            ply->facingDirection = ply->UP;

        }
        else if(ply->dFlag){
            ply->actionTrigger = ply->DWALK;
            ply->facingDirection = ply->DOWN;

        }
        else{
            ply->actionTrigger = ply->STAND;
        }
        break;

    case 87:                          //W key is pressed
    case VK_UP:
        //cout << "reset uflags\n";
        ply->uFlag = false;
        plx->uFlag = false;

        //Item
        item->uFlag = false;

        //Door
        door->uFlag = false;

        //Particles
        part->uFlag = false;

        //Enemies
        for(i = 0; i < numOfEnem; i++){
            enem[i].uFlag = false;
        }

        if(ply->lFlag){
            ply->actionTrigger = ply->LWALK;
            ply->facingDirection = ply->LEFT;

        }
        else if(ply->rFlag){
            ply->actionTrigger = ply->RWALK;
            ply->facingDirection = ply->RIGHT;

        }
        else{
            ply->actionTrigger = ply->STAND;
        }
        break;

    case 83:                          //S key is pressed
    case VK_DOWN:
        //cout << "reset dflags\n";
        ply->dFlag = false;
        plx->dFlag = false;

        //Item
        item->dFlag = false;

        //Door
        door->dFlag = false;

        //Particles
        part->dFlag = false;

        //Enemies
        for(i = 0; i < numOfEnem; i++){
            enem[i].dFlag = false;
        }

        if(ply->lFlag){
            ply->actionTrigger = ply->LWALK;
            ply->facingDirection = ply->LEFT;

        }
        else if(ply->rFlag){
            ply->actionTrigger = ply->RWALK;
            ply->facingDirection = ply->RIGHT;

        }
        else{
            ply->actionTrigger = ply->STAND;
        }
        break;

    case VK_SPACE:
        //Player
        ply->isDodging = false;

        //Parallax
        plx->isDodging = false;

        //Item
        item->isDodging = false;

        //Door
        door->isDodging = false;

        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].isDodging = false;
        }

        //Particles
        part->isDodging = false;

        if(!ply->dodgingLimit){
            tmr->resetTime();
            ply->dodgingLimit = false;
        }

        break;

    case VK_SHIFT:
        ply->isAttacking = false;

        plx->isAttacking = false;

        //Item
        item->isAttacking = false;

        //Door
        door->isAttacking = false;

        //Particles
        part->isAttacking = false;

        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].xSpeed2 = 0.0;
            enem[i].ySpeed2 = 0.0;
            enem[i].plyAttacking = false;
        }
        break;

    case VK_CAPITAL:
        ply->isAttacking = false;

        plx->isAttacking = false;

        //Item
        item->isAttacking = false;

        //Door
        door->isAttacking = false;

        //Particles
        part->isAttacking = false;

        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].xSpeed2 = 0.0;
            enem[i].ySpeed2 = 0.0;
            enem[i].plyAttacking = false;
        }
        break;

    case 67:                        //C key for Blocking
        //Player
        ply->isBlocking = false;
        ply->invulnerable = false;
        ply->plyTimer->resetTime();

        //Parallax
        plx->isBlocking = false;

        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].isBlocking = false;
        }

        //Item
        item->isBlocking = false;

        //Door
        door->isBlocking = false;

        //Particles
        part->isBlocking = false;
        break;
    }

    //cout << "reset all flags\n";
    if(!ply->lFlag && !ply->rFlag && !ply->uFlag && !ply->dFlag) {
        snds->stopAllSounds();
        playSound = true;
    }
}

void _input::mouseDown(_onScreenButtons* btn, _menu* menu, float x, float y, float width, float height, _sounds* snds, string lastMenu)
{
    //Checking Mouse clicked a button's bounded box section of the Window screen

    //Main Menu Selection
    if(btn->buttonID == "new"){
        if(x >= width * 0.35 && x <= width * 0.65 && y >= height * 0.15 && y <= height * 0.35){ //y 0.19,0.8              //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                //cout << "New game pressed!!!\n";
                //cout << "NEW GAME \n";
                if(menu->menuLevel){
                snds->stopAllSounds();
                menu->menuLevel = false;
                menu->newMenu = false;
                //menu->liveLevel1 = true;
                menu->tran1 = true;
                menu->currLevel = 1;

                //menu->doneLoading = false; //false
                snds->playMusic("sounds/foyermusic.mp3");
                }
        }
    }
    if(btn->buttonID == "help"){
        if(x >= width * 0.35 && x <= width * 0.65 && y >= height * 0.36 && y <= height * 0.55){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                //cout << "Help pressed!!!\n";
                if(menu->menuLevel){
                menu->helpLevel = ! menu->helpLevel; //true
                menu->menuLevel = ! menu->menuLevel; //false
                //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "credit"){
        if(x >= width * 0.35 && x <= width * 0.65 && y >= height * 0.63 && y <= height * 0.78){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                //cout << "Credits pressed!!!\n";
                if(menu->menuLevel){
                menu->creditLevel = ! menu->creditLevel; //true
                menu->menuLevel = ! menu->menuLevel; //false
                //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "exit"){
        if(x >= width * 0.35 && x <= width * 0.65 && y >= height * 0.82 && y <= height * 0.97){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                //cout << "Exit pressed!!!\n";
                if(menu->menuLevel){
                    exit(0);
                }
        }
    }




    //New Menu Selection
    if(btn->buttonID == "resume"){
        if(x >= width * 0.0075 && x <= width * 0.30 && y >= height * 0.29 && y <= height * 0.47){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "resume pressed!!!\n";
                if(menu->newMenu){
                    snds->stopAllSounds();
                    menu->newMenu = false;

                    if(menu->currLevel == 1){
                        menu->liveLevel1 = ! menu->liveLevel1;
                        snds->playMusic("sounds/foyermusic.mp3");
                    }
                    else if(menu->currLevel == 2){
                        menu->liveLevel2 = ! menu->liveLevel2;
                        snds->playMusic("sounds/level2music.mp3");
                    }
                    else if(menu->currLevel == 3){
                        menu->liveLevel3 = ! menu->liveLevel3;
                        snds->playMusic("sounds/level3music.mp3");
                    }
                    else if(menu->currLevel == 4){
                        menu->liveLevel4 = ! menu->liveLevel4;
                        //snds->playMusic("sounds/level3music.mp3");
                    }
                    else if(menu->currLevel == 5){
                        menu->liveLevel5 = ! menu->liveLevel5;
                        //snds->playMusic("sounds/level3music.mp3");
                    }

                    //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "newNew"){
        if(x >= width * 0.35 && x <= width * 0.64 && y >= height * 0.29 && y <= height * 0.47){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "new game pressed!!!\n";
                if(menu->newMenu){
                snds->stopAllSounds();
                menu->menuLevel = false;
                menu->newMenu = false;
                //menu->liveLevel1 = true;
                menu->tran1 = true;
                menu->currLevel = 1;

                //menu->doneLoading = false; //false
                snds->playMusic("sounds/foyermusic.mp3");
                }
        }
    }
    if(btn->buttonID == "newHelp"){
        if(x >= width * 0.69 && x <= width * 0.99 && y >= height * 0.29 && y <= height * 0.47){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "new help pressed!!!\n";
                if(menu->newMenu){
                menu->helpLevel = ! menu->helpLevel; //true
                menu->newMenu = ! menu->newMenu; //false
                //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "newCredits"){
        if(x >= width * 0.15 && x <= width * 0.45 && y >= height * 0.53 && y <= height * 0.70){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "new credits pressed!!!\n";
                if(menu->newMenu){
                menu->creditLevel = ! menu->creditLevel; //true
                menu->newMenu = ! menu->newMenu; //false
                //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "newExit"){
        if(x >= width * 0.54 && x <= width * 0.84 && y >= height * 0.53 && y <= height * 0.70){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "new exit pressed!!!\n";
                if(menu->newMenu){
                    exit(0);
                }
        }
    }

    //Help Back Button
    if(btn->buttonID == "helpBack"){
        if(x >= width * 0.5 && x <= width * 1.0 && y >= height * 0.0 && y <= height * 0.2){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "help back pressed!!!\n";

                if(menu->helpLevel){
                    if(lastMenu == "main"){
                        menu->helpLevel = ! menu->helpLevel; //true
                        menu->menuLevel = ! menu->menuLevel; //false
                        //menu->doneLoading = false; //false
                    }

                    if(lastMenu == "new"){
                        menu->helpLevel = ! menu->helpLevel; //true
                        menu->newMenu = ! menu->newMenu; //false
                        //menu->doneLoading = false; //false
                    }

                    if(lastMenu == "pause"){
                        menu->helpLevel = ! menu->helpLevel; //true
                        menu->pauseLevel = ! menu->pauseLevel; //false
                        //menu->doneLoading = false; //false
                    }
                }
        }
    }

    //Credits Back Button
    if(btn->buttonID == "creditsBack"){
        if(x >= width * 0.93 && x <= width * 1.0 && y >= height * 0.0 && y <= height * 0.1){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "credits back pressed!!!\n";

                if(menu->creditLevel){
                    if(lastMenu == "main"){
                        menu->creditLevel = ! menu->creditLevel; //true
                        menu->menuLevel = ! menu->menuLevel; //false
                        //menu->doneLoading = false; //false
                    }

                    if(lastMenu == "new"){
                        menu->creditLevel = ! menu->creditLevel; //true
                        menu->newMenu = ! menu->newMenu; //false
                        //menu->doneLoading = false; //false
                    }
                }

        }
    }


    //Pause buttons
    if(btn->buttonID == "pauseQuit"){
        if(x >= width * 0.16 && x <= width * 0.39 && y >= height * 0.16 && y <= height * 0.51){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "pause quit pressed!!!\n";
                if(menu->pauseLevel){
                    exit(0);
                }
        }
    }
    if(btn->buttonID == "pauseHelp"){
        if(x >= width * 0.59 && x <= width * 0.78 && y >= height * 0.16 && y <= height * 0.51){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "pause help pressed!!!\n";
                if(menu->pauseLevel){
                    menu->helpLevel = ! menu->helpLevel; //true
                    menu->pauseLevel = ! menu->pauseLevel; //false
                    //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "pausePlay"){
        if(x >= width * 0.16 && x <= width * 0.39 && y >= height * 0.55 && y <= height * 0.91){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "pause play pressed!!!\n";
                if(menu->pauseLevel){

                    snds->stopAllSounds();
                    menu->pauseLevel = false;

                    if(menu->currLevel == 1){
                        menu->liveLevel1 = ! menu->liveLevel1;
                        snds->playMusic("sounds/foyermusic.mp3");
                    }
                    else if(menu->currLevel == 2){
                        menu->liveLevel2 = ! menu->liveLevel2;
                        snds->playMusic("sounds/level2music.mp3");
                    }
                    else if(menu->currLevel == 3){
                        menu->liveLevel3 = ! menu->liveLevel3;
                        snds->playMusic("sounds/level3music.mp3");
                    }
                    else if(menu->currLevel == 4){
                        menu->liveLevel4 = ! menu->liveLevel4;
                    }
                    else if(menu->currLevel == 5){
                        menu->liveLevel5 = ! menu->liveLevel5;
                    }
                    //menu->doneLoading = false; //false
                }
        }
    }
    if(btn->buttonID == "pauseMenu"){
        if(x >= width * 0.59 && x <= width * 0.78 && y >= height * 0.55 && y <= height * 0.91){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //cout << "pause menu pressed!!!\n";
                if(menu->pauseLevel){
                    snds->stopAllSounds();
                    menu->pauseLevel = false;
                    menu->newMenu = true;

                    //menu->doneLoading = false; //false

                }
        }
    }








    if(btn->buttonID == "start"){
        if(x >= width * 0.93 && x <= width * 1.0 && y >= height * 0.0 && y <= height * 0.05){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                //cout << "Start Button pressed!!!\n";
        }
    }
    else if(btn->buttonID == "replay"){
        if(x >= width * 0.47 && x <= width * 0.53 && y >= height * 0.0 && y <= height * 0.05){              //Bounding box is a set percentage of the Window size, Bound box width = 47%-53% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->t1 = 0.0;
                //cout << "Replay Button pressed!!!\n";
        }
    }
    else if(btn->buttonID == "reset"){
        if(x >= width * 0.0 && x <= width * 0.06 && y >= height * 0.0 && y <= height * 0.05){               //Bounding box is a set percentage of the Window size, Bound box width = 0.0%-6% of Window Width, Bound box height = 0.0%-5% of Height
            btn->pressed = true;
            //rNC->initRails();
            //rNC->cartInit(4.0);
            //cout << "Reset Button pressed!!!\n";
        }
    }
}

void _input::mouseDown(_player* ply, _parallax* plx, float x, float y, _items* item, _enemies* enem, int numOfEnem,  _door* door, _particles* part)
{
    cout << "Mouse wParam: " << wParam << endl;
    switch(wParam)
    {
    case MK_LBUTTON:
        if(!ply->isBlocking){
            //Player
            ply->actionTrigger = ply->ATK;
            ply->isAttacking = true;

            //Parallax
            plx->isAttacking = true;

            //Item
            item->isAttacking = true;

            //Door
            door->isAttacking = true;

            //Particles
            part->isAttacking = true;

            //Enemy
            for(i = 0; i < numOfEnem; i++){
                enem[i].xSpeed2 = 0.0;
                enem[i].ySpeed2 = 0.0;
                enem[i].plyAttacking = true;
            }
        }
        break;

    case MK_RBUTTON:
        if(!ply->isBlocking){
            //Player
            ply->actionTrigger = ply->HATK;
            ply->isAttacking = true;

            //Parallax
            plx->isAttacking = true;

            //Item
            item->isAttacking = true;

            //Door
            door->isAttacking = true;

            //Particles
            part->isAttacking = true;

            //New Code
            //Enemy
            for(i = 0; i < numOfEnem; i++){
                enem[i].xSpeed2 = 0.0;
                enem[i].ySpeed2 = 0.0;
                enem[i].plyAttacking = true;
            }
        }
        break;
    }
}

void _input::mouseUp(_player* ply, _parallax* plx, _items* item,_enemies* enem, int numOfEnem, _door* door, _particles* part)
{
     //Player
    ply->isAttacking = false;

    //Parallax
    plx->isAttacking = false;

    //Door
    door->isAttacking = false;

    //Particles
    part->isAttacking = false;

    //*
    //Enemy
    for(i = 0; i < numOfEnem; i++){
        enem[i].xSpeed2 = 0.0;
        enem[i].ySpeed2 = 0.0;
    }
    //*/
}
