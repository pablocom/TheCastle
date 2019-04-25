#include "Caja.h"

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
}

void Caja::moveTo(float x, float y)
{
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
