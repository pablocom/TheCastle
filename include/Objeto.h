#ifndef OBJETO_H
#define OBJETO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Objeto
{
    public:
        Objeto(float xInicial, float yInicial);
        virtual ~Objeto();
        void draw(RenderWindow *w);
        void moveTo(float x, float y);
        bool checkearColisiones(FloatRect rect);

    protected:

    private:
};

#endif // OBJETO_H
