#ifndef MUNDO_H
#define MUNDO_H

#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Mapa.h"
#include "Enemigo.h"
#include "Llave.h"

using namespace sf;
using namespace std;

class Mundo
{
    public:
        Mundo();
        virtual ~Mundo();
        void draw(RenderWindow *w);
        void updateMundo();
        void handleEvents(RenderWindow *w);
        void handleInputs();

    protected:

    private:
        Jugador *j1;
        Mapa *mapa;

        Enemigo **enemigos; /// Array con los enemigos que va a tener ese mundo
        Llave **llaves; /// Array con las llaves que va a tener ese mundo

        bool tSalto = false, tIzquierda = false, tDerecha = false;

};

#endif // MUNDO_H
