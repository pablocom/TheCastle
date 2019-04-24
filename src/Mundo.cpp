#include "Mundo.h"

Mundo::Mundo()
{
    //ctor

    j1 = new Jugador(10, 180);

    nivelActivo = new Nivel();

}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    nivelActivo->draw(w);
    j1->dibujar(w);
}

void Mundo::updateMundo()
{
    j1->update(nivelActivo);
    nivelActivo->updateNivel();
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, nivelActivo);
}
