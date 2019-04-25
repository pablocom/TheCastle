#include "Objeto.h"

Objeto::Objeto(float xInicial, float yInicial, int tipo)
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/objetos/anillo.png");
    sprite = new Sprite(*texture);
    sprite->scale(.8, .8);
    moveTo(xInicial, yInicial);
}

Objeto::~Objeto()
{
    //dtor
}

void Objeto::draw(RenderWindow *w)
{
    w->draw(*sprite);
}

void Objeto::moveTo(float x, float y)
{
    sprite->setPosition(x, y);
}

bool Objeto::checkearColisiones(FloatRect rect)
{
    if(sprite->getGlobalBounds().intersects(rect))
    {
        return true;
    }
    return false;
}
