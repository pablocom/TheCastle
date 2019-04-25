#ifndef NIVEL_H
#define NIVEL_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "Mapa.h"
#include "Enemigo.h"
#include "Llave.h"
#include "Puerta.h"
#include "Objeto.h"

using namespace sf;

class Nivel
{
    public:
        Nivel();
        virtual ~Nivel();
        void draw(RenderWindow *w);
        void updateNivel();
        bool checkearColisiones(FloatRect rect);
        bool checkearColisionesLlaves(FloatRect rect);
        bool checkearColisionesEnemigos(FloatRect rect);
        bool checkearColisionesPuertas(FloatRect rect, int nLlaves);
        void crearEnemigo(float yInicial, float xInicial, float xFinal, bool invertido);
        void crearLlave(float x, float y);
        void crearPuerta(float x, float y);
        void crearObjeto(float x, float y, const char* tipo);
        void cargarMapa(const char* tilemap);
        void reiniciar();


    protected:

    private:
        int id;

        Mapa *mapa;
        std::vector<Enemigo*> enemigos; /// Array con los enemigos que va a tener ese nivel
        std::vector<Llave*> llaves; /// Array con las llaves que va a tener ese nivel
        std::vector<Puerta*> puertas; /// Array con las puertas que va a tener ese nivel
        std::vector<Objeto*> objetos; /// Array con las puertas que va a tener ese nivel

        Font *fontNexts;
        std::vector<Text*> nexts;

};

#endif // NIVEL_H
