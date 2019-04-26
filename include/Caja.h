#ifndef CAJA_H
#define CAJA_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Caja
{
    public:
        Caja(float xInicial, float yInicial);
        virtual ~Caja();
        void draw(RenderWindow *w);
        void moveTo(float x, float y);

        bool checkearColisiones(FloatRect rect);

        Vector2f getPosition() { return sprite->getPosition(); }
        Sprite getSprite() { return *sprite; }


    private:


        Texture *texture;
        Sprite *sprite;

};

#endif // CAJA_H
