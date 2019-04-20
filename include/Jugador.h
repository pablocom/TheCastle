#ifndef JUGADOR_H
#define JUGADOR_H

#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Jugador
{
    public:
        Jugador();
        void dibujar(RenderWindow * window);
        void setSprite();
        void animar();
        void update();
        void procesarEventos(RenderWindow * window);
        void drawColliders(RenderWindow * window);
        void setRectangles();

        Sprite getSprite () { return *sprite; }

    private:
        Event * evento;

        int spriteActive = 0;
        int * spritePositions;
        int * spritePositionsReverse;

        bool invertirSprite = false;

        std::vector<Rect<float>> boxes;

        Vector2f velocidad;
        Vector2f posicion;

        Texture * texture;
        Sprite * sprite;

        Clock * clock;

        /**TESTING**/
        std::vector<RectangleShape> rectangles;

};

#endif // JUGADOR_H
