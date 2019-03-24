#ifndef JUEGO_H
#define JUEGO_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Juego
{
    public:
        Juego(Vector2i dimension, std::string title);
        void inicializar();
        void gameLoop();
        void update();
        void dibujar();

    private:
        RenderWindow * window;

        Texture * txt1;
        Sprite * spr1;

        int fps = 60;
        bool gameOver = false;
        Clock * clock1;
        Time * time1;

};

#endif // JUEGO_H
