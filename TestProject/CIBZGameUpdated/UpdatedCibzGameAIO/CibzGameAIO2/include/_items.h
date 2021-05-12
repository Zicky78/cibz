#ifndef _ITEMS_H
#define _ITEMS_H

#include <_common.h>
#include<_texture.h>
#include<GL/gl.h>
#include<_timer.h>

class _items
{
    public:
        _items();
        virtual ~_items();

        vec3 itemPos;
        vec3 itemScale;
        vec3 itemRot;
        vec3 vert[4];

        int itemType;

        float itemRadius;

        float xFrames;
        float yFrames;
        float xMin, xMax, yMin, yMax;

        bool notPickedUp;

        //initializes a new item with a random item type and random location
        void itemInit(float, float);
        //draws the item
        void drawItem();
        //accounts for the player moving
        void itemScroll(float);

        bool lFlag, rFlag, uFlag, dFlag;
        bool isDodging, isAttacking;
        bool isBlocking;

        _texture *itemImage = new _texture();

        _timer *iT = new _timer();

    protected:

    private:
};

#endif // _ITEMS_H
