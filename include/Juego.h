#ifndef JUEGO_H
#define JUEGO_H

#include "SFML/Graphics.hpp"
#include "Jugador.h"
#include "Teclado.h"
#include "Mapa.h"
#include "Mundo.h"

using namespace sf;

class Juego
{
    public:
        Juego(Vector2i dimension, std::string title);
        void gameLoop();
        void procesarEventos();
        void update();
        void dibujar();

    private:
        RenderWindow *window;
        View *view;

        Mundo *mundo;

        int fps = 60;
        bool gameOver = false;
        Clock * clock1;
        Time * time1;

};

#endif // JUEGO_H
