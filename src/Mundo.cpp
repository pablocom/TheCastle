#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    mapa = new Mapa();

    j1 = new Jugador(10, 180);



    enemigos = new Enemigo*[2];
    enemigos[0] = new Enemigo(102, 135, 220, false);
    enemigos[1] = new Enemigo(196, 10, 250, true);

    llaves = new Llave*[1];
    llaves[0] = new Llave(34, 170);
}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    mapa->draw(w);
    j1->dibujar(w);
    for(int i = 0; i < 2; i++)
    {
        enemigos[i]->draw(w);
    }

    for(int i = 0; i < 1; i++) {
        llaves[i]->draw(w);
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
