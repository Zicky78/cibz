#include "_input.h"

_input::_input()
{
    prevMouseX = 0;
    prevMouseY = 0;
    mouseTranslation = false;
    mouseRotate = false;
    //ctor

    tmr->startTimer();
}

_input::~_input()
{
    //dtor
}
void _input::keyPressed(_model* mdl)
{
    switch(wParam)
    {
    case VK_LEFT:
            mdl->rotateY += 1.0;
        break;

    case VK_RIGHT:
            mdl->rotateY -= 1.0;
        break;
    }
}

/*
void _input::keyPressed(_player* ply)
{
    cout << "Keyborad wParam: " << wParam << endl;

    switch(wParam)
    {
    case 65:                          //A key is pressed
    case VK_LEFT:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
            ply->lFlag = true;
            ply->rFlag = false;
            ply->actionTrigger = ply->LWALK;
            ply->facingDirection = ply->LEFT;

        }
        break;

    case 68:                          //D key is pressed
    case VK_RIGHT:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
            ply->rFlag = true;
            ply->lFlag = false;
            ply->actionTrigger = ply->RWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->RIGHT;
        }
        break;

    case 87:                          //W key is pressed
    case VK_UP:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
            ply->uFlag = true;
            ply->dFlag = false;
            ply->actionTrigger = ply->UWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->UP;
        }
        break;

    case 83:                          //S key is pressed
    case VK_DOWN:
        if(!ply->isDodging && !ply->isAttacking){          //Can only move if NOT Dodging AND NOT  Attacking
            ply->dFlag = true;
            ply->uFlag = false;
            ply->actionTrigger = ply->DWALK;                 //Do action according to your sprite
            ply->facingDirection = ply->DOWN;
        }
        break;

    case VK_SPACE:
        if(tmr->getTicks() > 2400){
            if(!ply->isDodging && !ply->isAttacking){
                ply->isDodging = true;
                ply->actionTrigger = ply->DODGE;
            }
            tmr->resetTime();
        }
        break;

    case VK_SHIFT:
        ply->actionTrigger = ply->ATK;
        ply->isAttacking = true;
        break;

    case VK_CAPITAL:
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;
        break;
    }
}
*/

void _input::moveEnv(_parallax* plx, _player* ply, _enemies enem[], int numOfEnem, float speed)
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

            //Enemies
            for(int i = 0; i < numOfEnem; i++){
                enem[i].lFlag = true;
                enem[i].rFlag = false;
            }
            /*
            if(enem.lFlag)
                cout << "LFlag: True\n";
            else
                cout << "LFlag: False\n";

            if(enem.rFlag)
                cout << "RFlag: True\n";
            else
                cout << "RFlag: False\n";
            */
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

            //Enemies
            for(int i = 0; i < numOfEnem; i++){
                enem[i].rFlag = true;
                enem[i].lFlag = false;

                /*
                if(enem[i].actionTrigger == enem[i].RIGHT)
                    cout << "ActionTrigger: True\n";
                else
                    cout << "ActionTrigger: False\n";
                */
            }
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

            //Enemies
            for(int i = 0; i < numOfEnem; i++){
                enem[i].uFlag = true;
                enem[i].dFlag = false;
            }
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

            //Enemies
            for(int i = 0; i < numOfEnem; i++){
                enem[i].dFlag = true;
                enem[i].uFlag = false;
            }
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
                //Enemy
                for(int k = 0; k < numOfEnem; k++){
                    enem[k].isDodging = true;
                }

                tmr->resetTime();
            }
        }
        break;

    case VK_SHIFT:
        ply->actionTrigger = ply->ATK;
        ply->isAttacking = true;

        plx->isAttacking = true;
        break;

    case VK_CAPITAL:
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;

        plx->isAttacking = true;
        break;
    }
}

void _input::keyUp(_player* ply, _parallax* plx, _enemies enem[], int numOfEnem)
{
    cout << "Key Up wParam: " << wParam << endl;

    switch(wParam)
    {
    case 65:                          //A key is pressed
    case VK_LEFT:
        //cout << "reset lflags\n";
        ply->lFlag = false;
        plx->lFlag = false;
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
        break;

    case VK_CAPITAL:
        ply->isAttacking = false;

        plx->isAttacking = false;
        break;
    }

    //if(!ply->isDodging)
        //ply->actionTrigger = ply->STAND;
    //ply->onGround = false;
    ply->isDodging = false;
    plx->isDodging = false;

    for(int j = 0; j < numOfEnem; j++){
        enem[j].isDodging = false;
    }
    //cout << "reset all flags\n";
}

void _input::keyUp()
{
    switch(wParam)
    {
    default:

        break;

    }
}

void _input::mouseDown(_player* ply, _parallax* plx, float x, float y)
{
    cout << "Mouse wParam: " << wParam << endl;
    switch(wParam)
    {
    case MK_LBUTTON:
        ply->actionTrigger = ply->ATK;
        ply->isAttacking = true;

        plx->isAttacking = true;
        break;

    case MK_RBUTTON:
        ply->actionTrigger = ply->HATK;
        ply->isAttacking = true;

        plx->isAttacking = true;
        break;
    }
}


void _input::mouseDown(_model* mdl, float x, float y)
{
    prevMouseX = x;
    prevMouseY = y;

    switch(wParam)
    {
    case MK_LBUTTON:
        mouseRotate = true;
        break;

    case MK_RBUTTON:
        mouseTranslation = true;
        break;

    default:

        break;

    }
}

void _input::mouseUp(_player* ply, _parallax* plx)
{
    ply->isAttacking = false;
    plx->isAttacking = false;
}


void _input::mouseUp()
{
    mouseRotate = false;
    mouseTranslation = false;

}

void _input::mouseWheel(_model* mdl, float delta)
{
    mdl->zoom += delta/100;
}

void _input::mouseMove(_model* mdl, float x, float y)
{
    if(mouseRotate){
        mdl->rotateY += (x - prevMouseX)/3;
        mdl->rotateX += (y - prevMouseY)/3;

    }

    if(mouseTranslation){
        mdl->xPos += (x - prevMouseX)/100;
        mdl->yPos -= (y - prevMouseY)/100;          //Y is -= because Windows origin is top-left corner
    }
    prevMouseX = x;
    prevMouseY = y;
}

void _input::mouseMove(_arrow* arw, float x, float y)
{

    //arw->arrowRot.z = atan((x) / (y)) * 720/PI;

    //*
    arw->arrowRot.z = atan((x - arw->arrowRot.x) / (y - arw->arrowRot.y)) * 180/PI;

    arw->arrowRot.x = x;
    arw->arrowRot.y = y;
    //*/
}

