#include "Mundo.h"

Mundo::Mundo()
{
    //ctor

    j1 = new Jugador(10, 180);

    /**NIVEL 1**/
    niveles.push_back(new Nivel());
    niveles[0]->cargarMapa("assets/maps/nivel1.tmx");
    niveles[0]->crearEnemigo(102, 135, 220, false);
    niveles[0]->crearEnemigo(196, 10, 250, true);
    niveles[0]->crearLlave(34, 170);
    niveles[0]->crearPuerta(46.5, 188);

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
