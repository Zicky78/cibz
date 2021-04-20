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

bool _collision::detectAggro(float px, float py, float pr, float ex, float ey, float er)
{
    if( sqrt( powf( (px - ex), 2.0 ) + powf( (py - ey), 2.0 ) ) < (pr + er) ) {
        //cout << "collision" << endl;
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
