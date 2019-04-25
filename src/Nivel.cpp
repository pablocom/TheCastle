#include "Nivel.h"

Nivel::Nivel()
{
    //ctor
    mapa = new Mapa();

    enemigos.push_back(new Enemigo(102, 135, 220, false));
    enemigos.push_back(new Enemigo(196, 10, 250, true));

    llaves.push_back(new Llave(34, 170));

    puertas.push_back(new Puerta(46.5, 188));
}

Nivel::~Nivel()
{
    //dtor
}

void Nivel::draw(RenderWindow *w)
{
    mapa->draw(w);

    for(int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->draw(w);
    }

    for(int i = 0; i < llaves.size(); i++)
    {
        llaves[i]->draw(w);
    }

    for(int i = 0; i < puertas.size(); i++)
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
    for(int i = 0; i < puertas.size(); i++)
    {
        if(puertas[i]->checkearColisiones(rect))
        {
            return true;
        }
    }
    return false;
}

bool Nivel::checkearColisionesLlaves(FloatRect rect)
{
    for(int i = 0; i < llaves.size(); i++)
    {
        if(llaves[i]->checkearColisiones(rect))
        {
            return true;
        }
        return false;
    }
}

void Nivel::updateNivel()
{
    for(int i = 0; i < enemigos.size(); i++) {
        enemigos[i]->update(mapa, puertas);
    }
}
