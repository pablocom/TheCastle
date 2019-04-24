#ifndef MUNDO_H
#define MUNDO_H

#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Nivel.h"

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
        Nivel *nivelActivo;

        bool tSalto = false, tIzquierda = false, tDerecha = false;

};

#endif // MUNDO_H
