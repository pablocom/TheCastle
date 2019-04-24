#ifndef PUERTA_H
#define PUERTA_H

#include "SFML/Graphics.hpp"

using namespace sf;


class Puerta
{
    public:
        Puerta(float xInicial, float yInicial);
        virtual ~Puerta();
        void draw(RenderWindow *w);
        void moveTo(float x, float y);
        Sprite getSprite() {return *sprite;}

    private:
        Texture *texture;
        Sprite *sprite;
};

#endif // PUERTA_H
