#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    mapa = new Mapa();

    j1 = new Jugador(10, 180);

    enemigoPrueba = new Enemigo(196, 10, 250, true);

    enemigos = new Enemigo*[1];

    enemigos[0] = new Enemigo(102, 135, 220, false);
}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    mapa->draw(w);
    j1->dibujar(w);
    enemigoPrueba->draw(w);
    for(int i = 0; i < 1; i++)
    {
        enemigos[0]->draw(w);
    }
}

void Mundo::updateMundo()
{
    j1->update(mapa);
    enemigoPrueba->update();
    for(int i = 0; i < 1; i++)
    {
        enemigos[0]->update();
    }
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, mapa);
}
