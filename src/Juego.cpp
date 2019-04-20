#include "Juego.h"


Juego::Juego(Vector2i dimension, std::string title)
{
    //ctor
    window = new RenderWindow(VideoMode(dimension.x, dimension.y), title);

    window->setFramerateLimit(fps);

    view = new View();
    view->reset(sf::FloatRect(0.f, 0.f, 320.f, 240.f));
    view->setCenter(Vector2f(160.f, 120.f));
    window->setView(*view);

    clock1 = new Clock();
    time1 = new Time();

    mundo = new Mundo();

    gameLoop();
}

void Juego::gameLoop()
{
    while(window->isOpen() && !gameOver)
    {
        *time1 = clock1->getElapsedTime(); // obtenemos el tiempo transcurrido

        if(time1->asSeconds() > (1 / fps))
        {

            procesarEventos();
            update();

            dibujar();
            clock1->restart();
        }
    }
}

void Juego::dibujar()
{
    window->clear();

    mundo->draw(window);

    window->display();
}

void Juego::update()
{
    mundo->updateMundo();
}

void Juego::procesarEventos()
{
    mundo->handleEvents(window);
}
