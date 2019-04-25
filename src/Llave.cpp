#include "Llave.h"

Llave::Llave(float xInicial, float yInicial)
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/objetos/llave.png");
    sprite = new Sprite(*texture);
    sprite->scale(.4, .4);
    moveTo(xInicial, yInicial);
}

Llave::~Llave()
{
    //dtor
}

void Llave::draw(RenderWindow *w)
{
    w->draw(*sprite);
}

void Llave::moveTo(float x, float y)
{
    sprite->setPosition(x, y);
}

bool Llave::checkearColisiones(FloatRect rect)
{
    if(sprite->getGlobalBounds().intersects(rect))
    {
        return true;
    }
    return false;
}
