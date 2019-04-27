#include "Caja.h"
#include <iostream>

Caja::Caja(float xInicial, float yInicial)
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/objetos/caja.png");
    sprite = new Sprite(*texture);
    sprite->scale(1, 1);
    moveTo(xInicial, yInicial);
}

Caja::~Caja()
{
    //dtor
}

void Caja::draw(RenderWindow *w)
{
    w->draw(*sprite);
    moviendo = 0;/// al final de cada iteacion se seteara a 0 como que no se esta moviendo
}

void Caja::moveTo(float x, float y)
{
    if(x != sprite->getPosition().x)
    {
        moviendo = 1;
    }

    sprite->setPosition(x, y);
}

bool Caja::checkearColisiones(FloatRect rect)
{
    if(sprite->getGlobalBounds().intersects(rect))
    {
        return true;
    }
    return false;
}

int Caja::getMoviendo()
{
    return moviendo;
}

void Caja::setMoviendo(int x)
{
    moviendo = x;
}
