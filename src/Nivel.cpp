#include "Nivel.h"

Nivel::Nivel()
{
    //ctor
    mapa = new Mapa();

    fontNexts = new Font();
    fontNexts->loadFromFile("assets/maps/fullPack2025.ttf");
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

    for(int i = 0; i < objetos.size(); i++)
    {
        objetos[i]->draw(w);
    }

    for(int i = 0; i < cajas.size(); i++)
    {
        cajas[i]->draw(w);
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
        if(enemigos[i]->getDeadSpriteActive() == 14)
        {
            enemigos.erase(std::remove(enemigos.begin(), enemigos.end(), enemigos[i]), enemigos.end());
        }
        else
        {
            enemigos[i]->update(mapa, puertas, cajas);
        }
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

void Nivel::crearObjeto(float x, float y, int tipo)
{
    objetos.push_back(new Objeto(x, y, tipo));
}

void Nivel::crearNext(float x, float y)
{
    nexts.push_back(new Text());
    nexts[nexts.size()-1]->setFont(*fontNexts);
    nexts[nexts.size()-1]->setCharacterSize(9);
    nexts[nexts.size()-1]->setString("NEXT");
    nexts[nexts.size()-1]->setPosition(x, y);
}

void Nivel::crearCaja(float x, float y)
{
    cajas.push_back(new Caja(x, y));
}

bool Nivel::checkearColisionesCajas(FloatRect rect)
{
    for(int i = 0; i < cajas.size(); i++)
    {
        if(cajas[i]->checkearColisiones(rect))
        {
            return true;
        }
    }
    return false;
}

bool Nivel::checkearColisionesCajasDerecha(FloatRect rect, float velocidadX)
{
    for(int i = 0; i < cajas.size(); i++)
    {
        if(cajas[i]->checkearColisiones(rect))
        {
            if(velocidadX > 0)
            {
                cajas[i]->moveTo(cajas[i]->getPosition().x + velocidadX, cajas[i]->getPosition().y);
            }
//            cajas[i]->setMoviendo(0);
            return true;
        }
    }
    return false;
}

bool Nivel::checkearColisionesCajasIzquierda(FloatRect rect, float velocidadX)
{
    for(int i = 0; i < cajas.size(); i++)
    {
        if(cajas[i]->checkearColisiones(rect))
        {
            if(velocidadX < 0)
            {
                cajas[i]->moveTo(cajas[i]->getPosition().x + velocidadX, cajas[i]->getPosition().y);
            }
            return true;
        }
    }
    return false;
}
