#include "Nivel.h"

Nivel::Nivel()
{
    //ctor
    mapa = new Mapa();

    fontNexts = new Font();
    fontNexts->loadFromFile("assets/maps/fullPack2025.ttf");

    nexts.push_back(new Text());
    nexts[0]->setFont(*fontNexts);
    nexts[0]->setCharacterSize(9);
    nexts[0]->setString("NEXT");
    nexts[0]->setPosition(284, 206);

    nexts.push_back(new Text());
    nexts[1]->setFont(*fontNexts);
    nexts[1]->setCharacterSize(9);
    nexts[1]->setString("NEXT");
    nexts[1]->setPosition(284, 158);

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

    for(int i = 0; i < nexts.size(); i++)
    {
        w->draw(*nexts[i]);
    }
}

bool Nivel::checkearColisiones(FloatRect rect)
{
    if(mapa->checkearColisiones(rect))
    {
        return true;
    }

    return false;
}

bool Nivel::checkearColisionesPuertas(FloatRect rect, int nLlaves)
{
    for(int i = 0; i < puertas.size(); i++)
    {
        if(puertas[i]->checkearColisiones(rect))
        {
            if(nLlaves > 0)
            {
                puertas.erase(std::remove(puertas.begin(), puertas.end(), puertas[i]), puertas.end());
                return false; // no colisiona si no que la abre
            }
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
            llaves.erase(std::remove(llaves.begin(), llaves.end(), llaves[i]), llaves.end());
            return true;
        }
        return false;
    }
}

void Nivel::updateNivel()
{
    for(int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->update(mapa, puertas);
    }
}

bool Nivel::checkearColisionesEnemigos(FloatRect rect)
{
    for(int i = 0; i < enemigos.size(); i++)
    {
        if(enemigos[i]->checkearColision(rect))
        {
            return true;
        }
    }
    return false;
}

void Nivel::reiniciar()
{
    for(int i = 0; i < enemigos.size(); i++)
    {
        enemigos[i]->reiniciar(); /// devolver al enemigo a la posicion en la que empezo (si sigue en el nivel)
    }
}

void Nivel::crearEnemigo(float yInicial, float xInicial, float xFinal, bool invertido)
{
    enemigos.push_back(new Enemigo(yInicial, xInicial, xFinal, invertido));
}

void Nivel::crearLlave(float x, float y)
{
    llaves.push_back(new Llave(x, y));
}

void Nivel::crearPuerta(float x, float y)
{
    puertas.push_back(new Puerta(x, y));
}

void Nivel::cargarMapa(const char* tilemap)
{
    mapa->load(tilemap);
}
