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
#include <_items.h>
#include <_sounds.h>
#include <_menu.h>
#include <_onScreenButtons.h>
#include <_particles.h>

#define PI 3.14159265

class _input
{
    public:
        _input();
        virtual ~_input();
        _timer *tmr = new _timer();

        void keyPressed(_player*);          //Kick off when you press a key

        _sounds *snds = new _sounds();
        bool playSound;

        void menuNav(_sounds *snd, _menu *menu);
        void keyUp(_menu* );

        void mouseDown(_onScreenButtons* btn, _menu* menu, float x, float y, float width, float height, _sounds* snds, string lastMenu);

        void moveEnv(_parallax *, _player*, _enemies*, _items*, int, float, _door*, _particles*);
        void keyUp(_player*, _parallax *, _enemies*, _items*, int, _door*, _particles*);          //Kick off when you press a key

        void mouseDown(_player*, _parallax*, float, float, _items*, _enemies*, int,  _door*, _particles*, _menu*);
        void mouseUp(_player*, _parallax*, _items*, _enemies*, int, _door*, _particles*);

        float prevMouseX;
        float prevMouseY;

        int i;
        bool isHeld;

        WPARAM wParam;

    protected:

    private:
};

#endif // _INPUT_H
