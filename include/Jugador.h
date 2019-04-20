#ifndef JUGADOR_H
#define JUGADOR_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "Mapa.h"

using namespace sf;
using namespace std;

class Jugador
{
    public:
        Jugador();
        void dibujar(RenderWindow * window);
        void setSprite();
        void animar();
        void update(Mapa *mapa);
        void procesarEventos(RenderWindow * window);
        void drawColliders(RenderWindow * window);
        void updateRectangles();
        void setRectangles();
        void updateColliders();
        void setColliders();
        void moveTo(Vector2f pos); //esto desplaza al jugador inmediatamente a la posicion indicada

        Sprite getSprite () { return *sprite; }
        std::vector<Rect<float>> getColliders() { return boxes; }

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
