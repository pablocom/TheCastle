#ifndef MUNDO_H
#define MUNDO_H

#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Nivel.h"
#include "Hud.h"

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
        bool pausa = false;

        Jugador *j1;
        int nivelActivo = 0;

        std::vector<Nivel*> niveles;

        bool tSalto = false, tIzquierda = false, tDerecha = false;

        Hud * hud;

};

#endif // MUNDO_H
