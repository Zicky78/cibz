#include "_collision.h"

_collision::_collision()
{
    //ctor
}

_collision::~_collision()
{
    //dtor
}

bool _collision::detectCollision(float px, float py, float pr, float ex, float ey, float er)
{
    if( sqrt( powf( (px - ex), 2.0 ) + powf( (py - ey), 2.0 ) ) < (pr + er) ) {
        //cout << "collision" << endl;
        return true;
    }
    //cout << "false" << endl;
    return false;
}

bool _collision::detectCollision(_player* ply, _enemies enmy)
{
    if(sqrt(powf((ply->playerPos.x - enmy.posE.x), 2.0) + powf((ply->playerPos.y - enmy.posE.y), 2.0)) < (ply->radiusPlayer + enmy.enemyRadius)){
        //cout << "Physical Collision" << endl;
        return true;
    }
    //cout << "false" << endl;
    return false;
}

bool _collision::detectAggro(float px, float py, float pr, float ex, float ey, float er)
{
    if( sqrt( powf( (px - ex), 2.0 ) + powf( (py - ey), 2.0 ) ) < (pr + er) ) {
        //cout << "collision" << endl;
        return true;
    }
    //cout << "false" << endl;
    return false;
}

bool _collision::detectAggro(_player* ply, _enemies enmy)
{
    if(sqrt(powf((ply->playerPos.x - enmy.posE.x), 2.0) + powf((ply->playerPos.y - enmy.posE.y), 2.0)) < (ply->radiusPlayer + enmy.detectRadius)){
        //cout << "Awareness Collision" << endl;
        return true;
    }
    //cout << "false" << endl;
    return false;
}

bool _collision::detectItem(float px, float py, float pr, float ix, float iy, float ir)
{
    if( sqrt( powf( (px - ix), 2.0 ) + powf( (py - iy), 2.0 ) ) < (pr + ir) ) {
        //cout << "collision" << endl;
        return true;
    }
    //cout << "false" << endl;
    return false;
}

bool _collision::atkCollision(_player* ply, _enemies enmy)
{
    if(sqrt(powf((ply->playerPos.x - enmy.posE.x), 2.0) + powf((ply->playerPos.y - enmy.posE.y), 2.0)) < (ply->atkRadius + enmy.enemyRadius)){
        //cout << "Player Attack Collision" << endl;
        /*
        if(ply->actionTrigger == ply->ATK){
            enmy.enemyHealth -= ply->lightDmg;
            return true;
        }
        enmy.enemyHealth -= ply->HeavyDmg;
        */
        return true;
    }
    //cout << "false" << endl;
    return false;
}


bool _collision::collisionOrientation(_player* ply, _enemies enmy)
{
    //All situations where Enemy is Behind the player.
    if(enmy.posE.x > 0.0 && ply->facingDirection == ply->LEFT)                      //Player facing Left, but Enemy is to the Right
        return false;
    else if(enmy.posE.x < 0.0 && ply->facingDirection == ply->RIGHT)                //Player facing Right, but Enemy is to the Left
        return false;
    else if(enmy.posE.y < 0.0 && ply->facingDirection == ply->UP)                   //Player facing Up, but Enemy is Below
        return false;
    else if(enmy.posE.y > 0.0 && ply->facingDirection == ply->DOWN)                 //Player facing Down, but Enemy is Above
        return false;

    return true;
}

int _collision::enemyHitPlayer(_player* ply, _enemies enmy[], _parallax* plx)
{
    plx->isHit = true;
    enmy->isAttacking = true;
    //cout << "Enemy Hit Player Reached\n";
    //cout << "Player Facing Direction: " << ply->facingDirection << endl;
    //cout << "Enemy Facing Direction: " << enmy->facingDirection << endl;

    //Player Facing Left
    if(ply->facingDirection == ply->LEFT && enmy->facingDirection == enmy->LEFT){             //Player facing Left and Enemy facing Left
        plx->rHitFlag = true;
        return RIGHT;                                                                       //Player should be facing Right after push back
    }
    else if(ply->facingDirection == ply->LEFT && enmy->facingDirection == enmy->RIGHT){                        //Player facing Left and Enemy facing Right
        plx->lHitFlag = true;
        return LEFT;                                                                                        //Player should be Left facing after push back
    }
    else if(ply->facingDirection == ply->LEFT && enmy->facingDirection == enmy->UP){          //Player facing Left and Enemy facing UP
        plx->dHitFlag = true;
        return DOWN;                                                                        //Player should be facing Down after push back
    }
    else if(ply->facingDirection == ply->LEFT && enmy->facingDirection == enmy->DOWN){                        //Player facing Left and Enemy facing Down
        plx->uHitFlag = true;
        return UP;                                                                                          //Player should be UP{ facing after push back
    }
    //Player Facing Right
    else if(ply->facingDirection == ply->RIGHT && enmy->facingDirection == enmy->RIGHT){      //Player facing Right and Enemy facing Right
        plx->lHitFlag = true;
        return LEFT;                                                                        //Player should be facing Left after push back
    }
    else if(ply->facingDirection == ply->RIGHT && enmy->facingDirection == enmy->LEFT){                        //Player facing Right and Enemy facing Left
        plx->rHitFlag = true;
        return RIGHT;                                                                                       //Player facing Left after push back
    }
    else if(ply->facingDirection == ply->RIGHT && enmy->facingDirection == enmy->UP){         //Player facing Right and Enemy facing UP
        plx ->dHitFlag = true;
        return DOWN;                                                                        //Player should be facing Down after push back
    }
    else if(ply->facingDirection == ply->RIGHT && enmy->facingDirection == enmy->DOWN){                        //Player facing Righ and Enemy facing Down
        plx->dHitFlag = true;
        return UP;                                                                                          //Player should be facing Down after push back
    }
    //Player Facing Up
    else if(ply->facingDirection == ply->UP && enmy->facingDirection == enmy->UP){            //Player facing UP and Enemy facing Up
        plx->dHitFlag = true;
        return DOWN;                                                                        //Player should be facing Down after push back
    }
    else if(ply->facingDirection == ply->UP && enmy->facingDirection == enmy->DOWN){                          //Player facing UP and Enemy facing Down
        plx->uHitFlag = true;
        return UP;                                                                                          //Player should be facing Up after push back
    }
    else if(ply->facingDirection == ply->UP && enmy->facingDirection == enmy->LEFT){          //Player facing UP and Enemy facing Left
        plx->rHitFlag = true;
        return RIGHT;                                                                       //Player should be facing Right after push back
    }
    else if(ply->facingDirection == ply->UP && enmy->facingDirection == enmy->RIGHT){                         //Player facing UP and Enemy facing Right
        plx->lHitFlag = true;
        return LEFT;                                                                                        //Player should be facing Left after push back
    }
    //Player Facing Down
    else if(ply->facingDirection == ply->DOWN && enmy->facingDirection == enmy->DOWN){        //Player facing Down and Enemy facing Down
        plx->uHitFlag = true;;
        return UP;                                                                          //Player should be facing Up after push back
    }
    else if(ply->facingDirection == ply->DOWN && enmy->facingDirection == enmy->UP){                          //Player facing Down and Enemy facing Up
        plx->dHitFlag = true;
        return DOWN;                                                                                        //Player should be facing Down after push back
    }
    else if(ply->facingDirection == ply->DOWN && enmy->facingDirection == enmy->LEFT){        //Player facing Down and Enemy facing Left
        plx->rHitFlag = true;
        return RIGHT;                                                                       //Player should be facing Right after push back
    }
    else if(ply->facingDirection == ply->DOWN && enmy->facingDirection == enmy->RIGHT){                       //Player facing Down and Enemy facing Right
        plx->lHitFlag = true;
        return LEFT;                                                                                        //Player should be facing Left after push back
    }
}
