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

    j1 = new Jugador();
    clock1 = new Clock();
    time1 = new Time();

    mapa = new Mapa();


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

    mapa->draw(window);

    j1->dibujar(window);
    j1->animar();

    window->display();
}

void Juego::update()
{
    j1->update();
}

void Juego::procesarEventos()
{
    j1->procesarEventos(window);
}
