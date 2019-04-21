#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    mapa = new Mapa();

    j1 = new Jugador();

    enemigoPrueba = new Enemigo(196, 200, 250);
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
}

void Mundo::updateMundo()
{
    j1->update(mapa);
    enemigoPrueba->update();
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, mapa);
}
