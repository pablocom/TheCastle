#include "Enemigo.h"

Enemigo::Enemigo()
{
    //ctor
    walk_txt = new Texture();
    walk_txt->loadFromFile("assets/enemigo/skeleton_walk.png");
    walk_spr = new Sprite(*walk_txt);

    walk_spr->setScale(0.7, 0.6);
    walk_spr->setOrigin(11, 16.5);
    walk_spr->setTextureRect(IntRect(walk_sprite_active*22, 0, 22, 33));
    walk_spr->setPosition(200, 196);

    clockAnimation = new Clock();
    animate();
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(RenderWindow *w)
{
    w->draw(*walk_spr);
    animate();
}

void Enemigo::animate()
{
    if(clockAnimation->getElapsedTime().asSeconds() > 0.05)
    {

        if(walk_sprite_active == 12)
        {
            walk_sprite_active = 0;
        }
        else
        {
            walk_sprite_active++;
        }
        clockAnimation->restart();
        updateFrame();
    }
}

void Enemigo::updateFrame()
{
    walk_spr->setTextureRect(IntRect(walk_sprite_active*22, 0, 22, 33));
}
