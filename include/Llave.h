#ifndef LLAVE_H
#define LLAVE_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Llave
{
    public:
        Llave(float xInicial, float yInicial);
        virtual ~Llave();
        void draw(RenderWindow *w);
        void moveTo(float x, float y);

    private:
        Texture *texture;
        Sprite *sprite;




};

#endif // LLAVE_H
