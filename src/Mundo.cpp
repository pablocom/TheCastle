#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    mapa = new Mapa();

    j1 = new Jugador(10, 180);


    numEnemigos = 2;
    enemigos = new Enemigo*[numPuertas];
    enemigos[0] = new Enemigo(102, 135, 220, false);
    enemigos[1] = new Enemigo(196, 10, 250, true);

    numLlaves = 1;
    llaves = new Llave*[1];
    llaves[0] = new Llave(34, 170);

    numPuertas = 1;
    puertas = new Puerta*[1];
    puertas[0] = new Puerta(46.5, 188);
}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    mapa->draw(w);
    j1->dibujar(w);
    for(int i = 0; i < numEnemigos; i++)
    {
        enemigos[i]->draw(w);
    }

    for(int i = 0; i < numLlaves; i++)
    {
        llaves[i]->draw(w);
    }

    for(int i = 0; i < numPuertas; i++)
    {
        puertas[i]->draw(w);
    }
}

void Mundo::updateMundo()
{
    j1->update(mapa);
    for(int i = 0; i < 2; i++) {
        enemigos[i]->update();
    }
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, mapa);
}
