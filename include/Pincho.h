#ifndef PINCHO_H
#define PINCHO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Pincho
{
    public:
        Pincho(float x, float y);
        virtual ~Pincho();
        void draw(RenderWindow *w);
        void moveTo(float x, float y);
        bool checkearColisiones(FloatRect rect);

    private:
        Texture *texture;
        Sprite *sprite;
};

#endif // PINCHO_H
