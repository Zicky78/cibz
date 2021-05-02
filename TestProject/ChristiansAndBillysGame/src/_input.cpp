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

void _input::moveEnv(_parallax* plx, _player* ply, _enemies enem[], _items* item, int numOfEnem, float speed, _door* door)
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
            for(int i = 0; i < numOfEnem; i++){
                enem[i].lFlag = true;
                enem[i].rFlag = false;
            }
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 68:
    case VK_RIGHT:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
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
            for(int i = 0; i < numOfEnem; i++){
                enem[i].rFlag = true;
                enem[i].lFlag = false;
            }
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 87:
    case VK_UP:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
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
            for(int i = 0; i < numOfEnem; i++){
                enem[i].uFlag = true;
                enem[i].dFlag = false;
            }
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case 83:
    case VK_DOWN:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
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
            for(int i = 0; i < numOfEnem; i++){
                enem[i].dFlag = true;
                enem[i].uFlag = false;
            }
        }
        if(playSound) {
                snds->playSounds("sounds/footsteps.wav");
                playSound = false;
            }
        break;

    case VK_SPACE:
        if(!ply->isDodging && !ply->isAttacking){
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
                for(int k = 0; k < numOfEnem; k++){
                    enem[k].isDodging = true;
                }

                tmr->resetTime();
            }
        }
        break;

    case VK_SHIFT:
        //Player
        ply->actionTrigger = ply->ATK;
        ply->isAttacking = true;

        //Parallax
        plx->isAttacking = true;

        //Item
        item->isAttacking = true;

        //Door
        door->isAttacking = true;
        snds->playSounds("sounds/sword_hit.mp3");
        break;

    case VK_CAPITAL:
        //Player
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;

        //Parallax
        plx->isAttacking = true;

        //Item
        item->isAttacking = true;

        //Door
        door->isAttacking = true;
        snds->playSounds("sounds/sword_hit.mp3");
        break;
    }
}

void _input::keyUp(_player* ply, _parallax* plx, _enemies enem[], _items* item, int numOfEnem, _door* door)
{
    cout << "Key Up wParam: " << wParam << endl;

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

        for(int j = 0; j < numOfEnem; j++){
            enem[j].lFlag = false;
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

        for(int j = 0; j < numOfEnem; j++){
            enem[j].rFlag = false;
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

        for(int j = 0; j < numOfEnem; j++){
            enem[j].uFlag = false;
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

        for(int j = 0; j < numOfEnem; j++){
            enem[j].dFlag = false;
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

        break;

    case VK_CAPITAL:
        ply->isAttacking = false;

        plx->isAttacking = false;

        //Item
        item->isAttacking = false;

        //Door
        door->isAttacking = false;

        break;
    }

    ply->isDodging = false;
    plx->isDodging = false;

    //Item
    item->isDodging = false;

    //Door
    door->isDodging = false;

    for(int j = 0; j < numOfEnem; j++){
        enem[j].isDodging = false;
    }
    //cout << "reset all flags\n";
    if(!ply->lFlag && !ply->rFlag && !ply->uFlag && !ply->dFlag) {
        snds->stopAllSounds();
        playSound = true;
    }
}

void _input::mouseDown(_player* ply, _parallax* plx, float x, float y, _door* door)
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

        snds->playSounds("sounds/sword_hit.mp3");

        break;

    case MK_RBUTTON:
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;

        plx->isAttacking = true;

        //Door
        door->isAttacking = true;

        snds->playSounds("sounds/sword_hit.mp3");

        break;
    }
}

void _input::mouseUp(_player* ply, _parallax* plx, _door* door)
{
    ply->isAttacking = false;
    plx->isAttacking = false;

    //Door
    door->isAttacking = false;
}
