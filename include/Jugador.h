#ifndef JUGADOR_H
#define JUGADOR_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "Nivel.h"

using namespace sf;
using namespace std;

class Jugador
{
    public:
        Jugador(float xInicial, float yInicial);
        void dibujar(RenderWindow * window);
        void setSprite();
        void animar();
        void update(Nivel *nivel);
        void procesarEventos(RenderWindow * window, Nivel *nivel);
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

        int saltoTotal = 0;

        bool invertirSprite = false;

        bool saltando = false;

        std::vector<Rect<float>> boxes;

        Vector2f velocidad;
        Vector2f posicion;

        /**SPRITE**/
        Texture * texture;
        Sprite * sprite;

        /**ANIMACION**/
        Clock * clock;

        /**SALTO**/
        Clock * clockSalto;

        /**TESTING**/
        std::vector<RectangleShape> rectangles;

        /****/
        int llaves = 0;



};

#endif // JUGADOR_H
