#include "Nivel.h"

Nivel::Nivel()
{
    //ctor
    mapa = new Mapa();

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

Nivel::~Nivel()
{
    //dtor
}

void Nivel::draw(RenderWindow *w)
{
    mapa->draw(w);

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

bool Nivel::checkearColisiones(FloatRect rect)
{
    if(mapa->checkearColisiones(rect))
    {
        return true;
    }
    for(int i = 0; i < numPuertas; i++)
    {
        if(puertas[i]->checkearColisiones(rect))
        {
            return true;
        }
    }
    return false;
}

void Nivel::updateNivel()
{
    for(int i = 0; i < numEnemigos; i++) {
        enemigos[i]->update(mapa, puertas);
    }
}
