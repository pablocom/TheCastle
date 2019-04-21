#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
    walk_txt = new Texture();
    walk_txt->loadFromFile("assets/enemigo/skeleton_walk.png");
    walk_spr = new Sprite(*walk_txt);
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(RenderWindow *w)
{
    w->draw(*walk_spr);
}
