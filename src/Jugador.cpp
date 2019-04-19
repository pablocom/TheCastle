#include <iostream>

#include "Jugador.h"

using namespace sf;
using namespace std;

Jugador::Jugador()
{
    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/sheet_hero_walk.png");
    sprite = new Sprite(*texture);
    sprite->scale(.4, .4);

    clock = new Clock();

    spritePositions = new int[4];
    spritePositions[0] = 0;
    spritePositions[1] = 64;
    spritePositions[2] = 128;
    spritePositions[3] = 64;

    spritePositionsReverse = new int[4];
    spritePositionsReverse[0] = 64;
    spritePositionsReverse[1] = 128;
    spritePositionsReverse[2] = 192;
    spritePositionsReverse[3] = 128;

    velocidad.y = 0; // gravedad

    setSprite();
}

void Jugador::dibujar(RenderWindow * window)
{
    window->draw(*sprite);
}

void Jugador::setSprite()
{
    if(!invertirSprite)
    {
        sprite->setTextureRect(IntRect(spritePositions[spriteActive], 0, 64, 64));
    }
    else
    {
        sprite->setTextureRect(IntRect(spritePositionsReverse[spriteActive], 0, -64, 64));
    }
}

void Jugador::animar()
{
    if(clock->getElapsedTime().asSeconds() > 0.4f) {

        if(true) {

            if(spriteActive < 3) {

                setSprite();
                spriteActive++;
                clock->restart();
            }
            else {

                setSprite();
                spriteActive = 0;
                clock->restart();
            }
        }
    }
}

void Jugador::procesarEventos(RenderWindow * window)
{
    while(window->pollEvent(*evento))
    {
        // We are going to listen the different events
        switch(evento->type)
        {
            case Event::Closed:
                exit(1);
                break;

            case Event::KeyPressed:

                if(Keyboard::isKeyPressed(Keyboard::Left))
                {
                    invertirSprite = true;
                    setSprite();
                    velocidad.x = -1;
                }
                else if(Keyboard::isKeyPressed(Keyboard::Right))
                {
                    invertirSprite = false;
                    setSprite();
                    velocidad.x = 1;
                }

                break;

            case Event::KeyReleased:
                if(evento->key.code == Keyboard::Left)
                {
                    velocidad.x = 0;
                }
                if(evento->key.code == Keyboard::Right)
                {
                    velocidad.x = 0;
                }
        }
    }
}

void Jugador::update()
{
    sprite->setPosition(sprite->getPosition().x + velocidad.x, sprite->getPosition().y + velocidad.y);
}
