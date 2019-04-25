#include "Mundo.h"

Mundo::Mundo()
{
    //ctor

    j1 = new Jugador(10, 180);

    niveles.push_back(new Nivel());

}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    niveles[nivelActivo]->draw(w);
    j1->dibujar(w);
}

void Mundo::updateMundo()
{
    if(!j1->estaMuriendo())
    {
        j1->update(niveles[nivelActivo]);
        niveles[nivelActivo]->updateNivel();
    }

    if(j1->pendienteDeReinicio())
    {
        niveles[nivelActivo]->reiniciar();
        j1->reiniciar();
        pausa = false;
    }
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, niveles[nivelActivo]);
}
