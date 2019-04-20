#ifndef MUNDO_H
#define MUNDO_H

#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Mapa.h"

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

        bool tSalto = false, tIzquierda = false, tDerecha = false;

};

#endif // MUNDO_H
