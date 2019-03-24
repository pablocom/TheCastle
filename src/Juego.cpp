#include "Juego.h"

Juego::Juego(Vector2i dimension, std::string title)
{
    //ctor
    window = new RenderWindow(VideoMode(dimension.x, dimension.y), title);

    window->setFramerateLimit(fps);

    inicializar();

    txt1 = new Texture;

    txt1->loadFromFile("assets/mapa.png");

    spr1 = new Sprite(*txt1);

    gameLoop();
}

void Juego::inicializar()
{
    clock1 = new Clock();
    time1 = new Time();
}

void Juego::gameLoop()
{
    while(window->isOpen() && !gameOver)
    {
        *time1 = clock1->getElapsedTime(); // obtenemos el tiempo transcurrido

        if(time1->asSeconds() > (1 / fps))
        {
            update();

            dibujar();
            clock1->restart();
        }
    }
}

void Juego::dibujar()
{
    window->clear();

    window->draw(*spr1);

    window->display();
}

void Juego::update()
{

}


