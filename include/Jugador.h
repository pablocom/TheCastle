#ifndef JUGADOR_H
#define JUGADOR_H

#include "SFML/Graphics.hpp"

using namespace sf;

class Jugador
{
    public:
        Jugador();
        void dibujar(RenderWindow * window);
        void setSprite();
        void animar();
        void update();
        void procesarEventos(RenderWindow * window);
        Sprite getSprite () { return *sprite; }

    private:
        Event * evento;

        int spriteActive = 0;
        int * spritePositions;
        int * spritePositionsReverse;

        bool invertirSprite = false;

        Vector2f velocidad;
        Vector2f posicion;

        Texture * texture;
        Sprite * sprite;

        Clock * clock;

};

#endif // JUGADOR_H
