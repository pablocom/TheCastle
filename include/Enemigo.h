#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

#include "Mapa.h"
#include "Puerta.h"
#include "Caja.h"

using namespace sf;

class Enemigo
{
    public:
        Enemigo(float yInicial, float xInicial, float xFinal, bool invertido);
        virtual ~Enemigo();
        void update(Mapa *mapa, std::vector<Puerta*> puertas, std::vector<Caja*> cajas);
        void draw(RenderWindow *w);
        void animate();
        void updateFrame();
        void moveTo(float left, float top);
        void initEnemigo();
        bool checkearColision(FloatRect rect);
        void reiniciar();

        int getDeadSpriteActive() { return dead_sprite_active; }

    protected:

    private:
        float yAux, xAux, xInicial, xFinal;
        bool muriendo = false, muerto = false;


        Texture *walk_txt;
        Sprite *walk_spr;

        Texture *dead_txt;
        Sprite *dead_spr;

        int walk_sprite_active = 0, dead_sprite_active = 0;

        Vector2f velocidad;

        Clock *clockAnimation;
        Clock *clockMuerte;

};

#endif // ENEMIGO_H
