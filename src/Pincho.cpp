#include "Pincho.h"

Pincho::Pincho(float x, float y)
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/objetos/pincho.png");
    sprite = new Sprite(*texture);
    sprite->rotate(180);
    moveTo(x, y);
}

Pincho::~Pincho()
{
    //dtor
}

void Pincho::moveTo(float x, float y)
{
    sprite->setPosition(x, y);
}

bool Pincho::checkearColisiones(FloatRect rect)
{
    if(sprite->getGlobalBounds().intersects(rect))
    {
        return true;
    }
    return false;
}

void Pincho::draw(RenderWindow *w)
{
    w->draw(*sprite);
}
