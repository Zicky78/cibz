#include "_input.h"

_input::_input()
{
    prevMouseX = 0;
    prevMouseY = 0;
    mouseTranslation = false;
    mouseRotate = false;
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
        snds->stopAllSounds();
        //Scene->liveLevel1 = ! Scene->liveLevel1; //true

        // Scene->menuLevel = ! Scene->menuLevel; //false
        menu->menuLevel = true;
        menu->landing = false;

        menu->pauseLevel = false; //enter main menu from pause

        // Scene->landing = ! Scene->landing;
        //cout << Scene->menuLevel << endl;
        menu->doneLoading = false; //false

        //Scene->snds->stopAllSounds();
        //Scene->snds->playMusic("sounds/mistydungeon.wav");
        snds->playMusic("sounds/mistydungeon.mp3");
        break;

    case 0x4E: //if user presses n, start new game
        snds->stopAllSounds();
        menu->menuLevel = false;
        menu->liveLevel1 = true;
        menu->currLevel = 1;

        menu->doneLoading = false; //false
        snds->playMusic("sounds/foyermusic.mp3");
        break;

    case 0x4D: //if user presses m, open new menu
        snds->stopAllSounds();
        menu->pauseLevel = false;
        menu->newMenu = true;

        menu->doneLoading = false; //false
        break;

    case 0x52: //if user presses r, resumes last game
        snds->stopAllSounds();
        menu->menuLevel = false;

        if(menu->currLevel == 1){
            menu->liveLevel1 = ! menu->liveLevel1;
        }
        else if(menu->currLevel == 2){
            menu->liveLevel2 = ! menu->liveLevel2;
        }
        else if(menu->currLevel == 3){
            menu->liveLevel3 = ! menu->liveLevel3;
        }

        menu->doneLoading = false; //false

        break;

    case 0x48:  //if user presses h, go to help
        if(!menu->holding && (menu->menuLevel || menu->helpLevel)){ //if in menu or help
        menu->helpLevel = ! menu->helpLevel; //true
        menu->menuLevel = ! menu->menuLevel; //false
        menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x50: //if user presses p, go to pause menu
        if(!menu->holding){
        menu->pauseLevel = ! menu->pauseLevel; //true
        //menu->liveLevel1 = ! menu->liveLevel1; //false

        if(menu->currLevel == 1){
            menu->liveLevel1 = ! menu->liveLevel1;
        }
        else if(menu->currLevel == 2){
            menu->liveLevel2 = ! menu->liveLevel2;
        }
        else if(menu->currLevel == 3){
            menu->liveLevel3 = ! menu->liveLevel3;
        }

        menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x43: //if user presses c, go to credits menu
        if(!menu->holding && (menu->menuLevel || menu->creditLevel)){
        menu->creditLevel = ! menu->creditLevel; //true
        menu->menuLevel = ! menu->menuLevel; //false
        menu->doneLoading = false; //false
        menu->holding = true;
        }
        break;

    case 0x32: //if user presses 2, start level 2
        snds->stopAllSounds();
        menu->liveLevel1 = false;
        menu->liveLevel2 = true;

        menu->doneLoading = false; //false
        snds->playMusic("sounds/level2music.mp3");
        menu->currLevel = 2;
        break;

    case 0x33: //if user presses 3, start level 3
        snds->stopAllSounds();
        menu->liveLevel2 = false;
        menu->liveLevel3 = true;

        menu->doneLoading = false; //false
        snds->playMusic("sounds/level3music.mp3");
        menu->currLevel = 3;
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

    case VK_SHIFT:
        ply->isAttacking = false;

        plx->isAttacking = false;

        //Item
        item->isAttacking = false;

        //Door
        door->isAttacking = false;

        //Particles
        part->isAttacking = false;

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

        break;

    case 67:                        //C key for Blocking
        //Player
        ply->isBlocking = false;
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

    ply->isDodging = false;
    plx->isDodging = false;

    //Item
    item->isDodging = false;

    //Door
    door->isDodging = false;

    //Enemy
    for(i = 0; i < numOfEnem; i++){
        enem[i].isDodging = false;
    }

    //cout << "reset all flags\n";
    if(!ply->lFlag && !ply->rFlag && !ply->uFlag && !ply->dFlag) {
        snds->stopAllSounds();
        playSound = true;
    }
}

void _input::mouseDown(_onScreenButtons* btn, _menu* menu, float x, float y, float width, float height)
{
    //Checking Mouse clicked a button's bounded box section of the Window screen
    if(btn->buttonID == "start"){
        if(x >= width * 0.93 && x <= width * 1.0 && y >= height * 0.0 && y <= height * 0.05){               //Bounding box is a set percentage of the Window size, Bound box width = 93%-100% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->started = true;
                cout << "Start Button pressed!!!\n";
        }
    }
    else if(btn->buttonID == "replay"){
        if(x >= width * 0.47 && x <= width * 0.53 && y >= height * 0.0 && y <= height * 0.05){              //Bounding box is a set percentage of the Window size, Bound box width = 47%-53% of Window Width, Bound box height = 0.0%-5% of Height
                btn->pressed = true;
                //rNC->t1 = 0.0;
                cout << "Replay Button pressed!!!\n";
        }
    }
    else if(btn->buttonID == "reset"){
        if(x >= width * 0.0 && x <= width * 0.06 && y >= height * 0.0 && y <= height * 0.05){               //Bounding box is a set percentage of the Window size, Bound box width = 0.0%-6% of Window Width, Bound box height = 0.0%-5% of Height
            btn->pressed = true;
            //rNC->initRails();
            //rNC->cartInit(4.0);
            cout << "Reset Button pressed!!!\n";
        }
    }
}

void _input::mouseDown(_player* ply, _parallax* plx, float x, float y, _enemies* enem, int numOfEnem,  _door* door, _particles* part)
{
    cout << "Mouse wParam: " << wParam << endl;
    switch(wParam)
    {
    case MK_LBUTTON:
        ply->actionTrigger = ply->ATK;
        ply->isAttacking = true;

        plx->isAttacking = true;

        //Door
        door->isAttacking = true;

        //Particles
        part->isAttacking = true;

        //New Code
        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].xSpeed2 = 0.0;
            enem[i].ySpeed2 = 0.0;
        }
        break;

    case MK_RBUTTON:
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;

        plx->isAttacking = true;

        //Door
        door->isAttacking = true;

        //Particles
        part->isAttacking = true;

        //New Code
        //Enemy
        for(i = 0; i < numOfEnem; i++){
            enem[i].xSpeed2 = 0.0;
            enem[i].ySpeed2 = 0.0;
        }
        break;
    }
}

void _input::mouseUp(_player* ply, _parallax* plx, _enemies* enem, int numOfEnem, _door* door, _particles* part)
{
     //Player
    ply->isAttacking = false;

    //Parallax
    plx->isAttacking = false;

    //Door
    door->isAttacking = false;

    //Particles
    part->isAttacking = false;

    /*
    //Enemy
    for(i = 0; i < numOfEnem; i++){
        enem[i].xSpeed2 = 0.0;
        enem[i].ySpeed2 = 0.0;
    }
    */
}
