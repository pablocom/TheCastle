#include "Mundo.h"

Mundo::Mundo()
{
    //ctor
    hud = new Hud();

    j1 = new Jugador(10, 180);

    /**NIVEL 1**/
    niveles.push_back(new Nivel());
    niveles[0]->cargarMapa("assets/maps/nivel1.tmx");
    niveles[0]->crearEnemigo(102, 135, 220, false);
    niveles[0]->crearEnemigo(196, 10, 250, true);
    niveles[0]->crearLlave(34, 170);
    niveles[0]->crearPuerta(46.5, 188);
    niveles[0]->crearObjeto(73, 95, 1);
    niveles[0]->crearNext(284, 206);
    niveles[0]->crearNext(284, 158);

    // nivelActivo = 1;

    /**NIVEL 2**/
    niveles.push_back(new Nivel());
    niveles[1]->cargarMapa("assets/maps/nivel2.tmx");
    niveles[1]->crearEnemigo(102, 135, 220, false);
    niveles[1]->crearEnemigo(196, 10, 250, true);
    niveles[1]->crearLlave(288, 180);
    niveles[1]->crearLlave(288, 132);
    niveles[1]->crearPuerta(302.5, 188);
    niveles[1]->crearPuerta(-1, 138);
    niveles[1]->crearObjeto(190, 64, 1);
    niveles[1]->crearObjeto(236, 64, 1);
    niveles[1]->crearCaja(80, 191);
    niveles[1]->crearPincho(15, 79);
    niveles[1]->crearPincho(31, 79);
    niveles[1]->crearPincho(95, 79);
    niveles[1]->crearPincho(111, 79);
}

Mundo::~Mundo()
{
    //dtor
}

void Mundo::draw(RenderWindow *w)
{
    niveles[nivelActivo]->draw(w);
    j1->dibujar(w);
    hud->draw(w);
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

    if(j1->saleDerecha())
    {
        if(nivelActivo < niveles.size() - 1)
        {
            nivelActivo++;
            j1->moveTo(Vector2f(0, j1->getSprite().getPosition().y));
        }
    }

    if(j1->saleIzquierda())
    {
        if(nivelActivo > 0)
        {
            nivelActivo--;
            j1->moveTo(Vector2f(299, j1->getSprite().getPosition().y));
        }
    }
    hud->update(j1);
}

void Mundo::handleEvents(RenderWindow *w)
{
    j1->procesarEventos(w, niveles[nivelActivo]);
}
