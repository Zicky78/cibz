#ifndef _INPUT_H
#define _INPUT_H

#include <windows.h>
#include <_model.h>
#include <_parallax.h>
#include <_player.h>
#include <_arrow.h>
#include <math.h>
#include <_timer.h>
#include <_enemies.h>

#define PI 3.14159265

class _input
{
    public:
        _input();
        virtual ~_input();
        _timer *tmr = new _timer();

        void keyPressed(_model*);           //Kick off when you press a key
        void keyPressed(_player*);          //Kick off when you press a key

        void moveEnv(_parallax *, _player*, _enemies*, int, float);
        //void moveEnv(_parallax *, float);           //Moving parallax
        // spotLight(_parallax*, _player*);
        void keyUp(_player*, _parallax *, _enemies*, int);          //Kick off when you press a key
        //void keyUp(_player*, _parallax *);
        void keyUp();

        void mouseDown(_model*, float, float);
        //void mouseDown(_player*, float, float);
        void mouseDown(_player*, _parallax*, float, float);
        void mouseUp(_player*, _parallax*);
        void mouseUp();
        void mouseWheel(_model*, float);
        void mouseMove(_model*, float, float);      //One float is a the source the other is the destination

        void mouseMove(_arrow*, float, float);

        float prevMouseX;
        float prevMouseY;
        bool mouseTranslation;
        bool mouseRotate;

        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUT_H
