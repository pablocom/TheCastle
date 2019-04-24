#include "Puerta.h"

Puerta::Puerta(float xInicial, float yInicial)
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/objetos/puerta.png");
    sprite = new Sprite(*texture);
    sprite->scale(.19, .14);
    moveTo(xInicial, yInicial);
}

Puerta::~Puerta()
{
    //dtor
}

void Puerta::draw(RenderWindow *w)
{
    w->draw(*sprite);
}

void Puerta::moveTo(float x, float y)
{
    sprite->setPosition(x, y);
}
