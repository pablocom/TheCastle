#include <iostream>

#include "Jugador.h"

using namespace sf;
using namespace std;

Jugador::Jugador(float xInicial, float yInicial)
{
    cout << "===========Creando Jugador==========" << endl;

    evento = new Event();

    //ctor
    texture = new Texture();
    texture->loadFromFile("assets/sheet_hero_walk.png");
    sprite = new Sprite(*texture);
    sprite->scale(.4, .4);
    // sprite->setOrigin(32, 32);

    clock = new Clock();
    clockSalto = new Clock();

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

    velocidad.y = 1; // gravedad

    setColliders();
    setRectangles();

    setSprite();

    /**POSICION INICIAL**/
    moveTo(Vector2f(xInicial, yInicial));

}

void Jugador::dibujar(RenderWindow * window)
{
    window->draw(*sprite);
    // drawColliders(window);
    animar();
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
    if(clock->getElapsedTime().asSeconds() > 0.4f)
    {

        if(true)
        {
            if(spriteActive < 3)
            {

                setSprite();
                spriteActive++;
                clock->restart();
            }
            else
            {

                setSprite();
                spriteActive = 0;
                clock->restart();
            }
        }
    }
}

void Jugador::procesarEventos(RenderWindow * window, Nivel * nivel)
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

            if(Keyboard::isKeyPressed(Keyboard::Space))
            {
                if(saltando == false && nivel->checkearColisiones(boxes[2])) // si no estaba saltando
                {
                    saltando = true;
                    clockSalto->restart();
                }
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
            if(evento->key.code == Keyboard::Space)
            {
                saltando = false;
                clockSalto->restart();
            }
        }
    }
}

void Jugador::update(Nivel *nivel)
{
    if(nivel->checkearColisionesLlaves(boxes[0]))
    {
        cout << "Has cogido una llave" << endl;
        llaves++;
    }

    if(clockSalto->getElapsedTime().asSeconds() >= 2)
    {
        saltando = false;
    }

    if(saltando == true)
    {
        if(saltoTotal <= -32)
        {
            velocidad.y = 0;
        }
        else
        {
            velocidad.y = -1;
            saltoTotal += velocidad.y;
        }
    }
    else
    {
        velocidad.y = 1;
        saltoTotal = 0;
    }

    if(nivel->checkearColisiones(boxes[1]) && velocidad.x > 0)
    {
        velocidad.x = 0;
    }

    if(nivel->checkearColisiones(boxes[3]) && velocidad.x < 0)
    {
        velocidad.x = 0;
    }


    if(nivel->checkearColisiones(boxes[2]) && velocidad.y > 0) // choca por abajo y esta bajando
    {
        sprite->setPosition(sprite->getPosition().x + velocidad.x, sprite->getPosition().y);
    }
    else if(nivel->checkearColisiones(boxes[0]) && velocidad.y < 0) // choca por arriba y esta subiendo
    {
        sprite->setPosition(sprite->getPosition().x + velocidad.x, sprite->getPosition().y);
    }
    else
    {
        sprite->setPosition(sprite->getPosition().x + velocidad.x, sprite->getPosition().y + velocidad.y);
    }

    updateColliders();
    updateRectangles();
}

/**TESTING**/

void Jugador::drawColliders(RenderWindow * window)
{
    for(int i = 0; i < rectangles.size(); i++)
    {
        window->draw(rectangles[i]);
    }
}

void Jugador::setRectangles()
{
    for(int i = 0; i < boxes.size(); i++)
    {
        rectangles.push_back(RectangleShape(Vector2f(boxes[i].width, boxes[i].height)));
        rectangles[i].setFillColor(Color::Magenta);
        rectangles[i].setPosition(boxes[i].left, boxes[i].top);
    }
}

void Jugador::updateColliders()
{
    boxes[0].left = sprite->getPosition().x + 9.5; boxes[0].top = sprite->getPosition().y + 14;
    boxes[1].left = sprite->getPosition().x + 14.5; boxes[1].top = sprite->getPosition().y + 16;
    boxes[2].left = sprite->getPosition().x + 9.5; boxes[2].top = sprite->getPosition().y + 22.5;
    boxes[3].left = sprite->getPosition().x + 7; boxes[3].top = sprite->getPosition().y + 16;
    // setRectangles();
}

void Jugador::updateRectangles()
{
    for(int i = 0; i < rectangles.size(); i++)
    {
        rectangles[i].setPosition(boxes[i].left, boxes[i].top);
    }
}

void Jugador::moveTo(Vector2f pos)
{
    sprite->setPosition(pos);

    updateColliders();

    updateRectangles();
}

void Jugador::setColliders()
{
    /**COLISIONERS**/
    boxes.push_back(FloatRect(sprite->getPosition().x + 12, sprite->getPosition().y + 14, 6, 3));   // arriba
    boxes.push_back(FloatRect(sprite->getPosition().x + 14.5, sprite->getPosition().y + 16, 3, 7)); // derecha
    boxes.push_back(FloatRect(sprite->getPosition().x + 12, sprite->getPosition().y + 22.5, 6, 3)); // abajo
    boxes.push_back(FloatRect(sprite->getPosition().x + 8, sprite->getPosition().y + 16, 3, 7)); // izquierda
}
