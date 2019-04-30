#ifndef HUD_H
#define HUD_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "Jugador.h"

using namespace sf;

class Hud
{
    public:
        Hud();
        virtual ~Hud();
        void update(Jugador *j);
        void draw(RenderWindow *w);

    private:
        Font * font;

        Texture *txt_vida;
        Sprite *spr_vida;

        Texture *txt_llaves;
        Sprite *spr_llaves;

        int puntuacion = 0, llaves = 0, vidas = 0;

        std::vector<Text*> texts;
};

#endif // HUD_H
