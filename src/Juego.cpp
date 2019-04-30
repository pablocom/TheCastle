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

    txt_portada = new Texture();
    txt_portada->loadFromFile("assets/portada.png");
    spr_portada = new Sprite(*txt_portada);
    spr_portada->scale(.5, .5);

    evento = new Event();

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

    switch(estado)
    {
    case 0:
        window->draw(*spr_portada);
        break;
    case 1:
        mundo->draw(window);
        break;
    }

    window->display();
}

void Juego::update()
{
    if(estado == 1)
    {
        mundo->updateMundo();
    }
    if(mundo->getPendienteReinicio())
    {
        mundo = new Mundo();
    }
}

void Juego::procesarEventos()
{
    switch(estado)
    {
        case 0:
            while(window->pollEvent(*evento))
            {
                // We are going to listen the different events
                switch(evento->type)
                {
                    case Event::Closed:
                        exit(1);
                        break;

                    case Event::KeyPressed:

                        if(Keyboard::isKeyPressed(Keyboard::Space))
                        {
                            std::cout << "Comenzando el juego" << std::endl;
                            estado = 1;
                        }
                        break;
                }
            break;
        case 1:
            mundo->handleEvents(window);
            break;
        }
    }
}
