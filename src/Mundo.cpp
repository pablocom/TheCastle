#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    j1 = new Jugador();
    mapa = new Mapa();
}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    j1->dibujar(w);
    mapa->draw(w);
}

void Mundo::updateMundo()
{
    j1->update();
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w);
}
