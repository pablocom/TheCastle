#ifndef NIVEL_H
#define NIVEL_H

#include "SFML/Graphics.hpp"

#include "Mapa.h"
#include "Enemigo.h"
#include "Llave.h"
#include "Puerta.h"

using namespace sf;

class Nivel
{
    public:
        Nivel();
        virtual ~Nivel();
        void draw(RenderWindow *w);
        void updateNivel();
        bool checkearColisiones(FloatRect rect);


    protected:

    private:
        int id;

        Mapa *mapa;
        int numEnemigos = 0, numLlaves = 0, numPuertas = 0;
        Enemigo **enemigos; /// Array con los enemigos que va a tener ese mundo
        Llave **llaves; /// Array con las llaves que va a tener ese mundo
        Puerta **puertas;

};

#endif // NIVEL_H
