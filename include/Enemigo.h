#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Enemigo
{
    public:
        Enemigo();
        virtual ~Enemigo();
        void update();
        void draw(RenderWindow *w);
        void animate();

    protected:

    private:
        Texture *walk_txt;
        Sprite *walk_spr;

        Clock clockAnimation;

};

#endif // ENEMIGO_H
