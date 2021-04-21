#ifndef _INPUT_H
#define _INPUT_H

#include <windows.h>
#include <_model.h>
#include <_parallax.h>
#include <_player.h>
#include <math.h>
#include <_timer.h>
#include <_enemies.h>
#include <_door.h>

#define PI 3.14159265

class _input
{
    public:
        _input();
        virtual ~_input();
        _timer *tmr = new _timer();

        void keyPressed(_player*);          //Kick off when you press a key

        void moveEnv(_parallax *, _player*, _enemies*, int, float, _door*);
        void keyUp(_player*, _parallax *, _enemies*, int, _door*);          //Kick off when you press a key

        void mouseDown(_player*, _parallax*, float, float, _door*);
        void mouseUp(_player*, _parallax*, _door*);

        float prevMouseX;
        float prevMouseY;
        bool mouseTranslation;
        bool mouseRotate;

        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUT_H
