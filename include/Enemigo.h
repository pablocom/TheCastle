#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();
        void update();
        void draw(RenderWindow *w);
        void animate();
        void updateFrame();
        void moveTo(float left, float top);

    protected:

    private:
        Texture *walk_txt;
        Sprite *walk_spr;
        int walk_sprite_active = 0;

        Clock *clockAnimation;

};

#endif // ENEMIGO_H
