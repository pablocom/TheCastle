#ifndef NIVEL_H
#define NIVEL_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "Mapa.h"
#include "Enemigo.h"
#include "Llave.h"
#include "Puerta.h"
#include "Objeto.h"
#include "Caja.h"
#include "Pincho.h"

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
        bool checkearColisionesPinchos(FloatRect rect);
        bool checkearColisionesCajas(FloatRect rect);
        bool checkearColisionesCajasDerecha(FloatRect rect, float velocidadX);
        bool checkearColisionesCajasIzquierda(FloatRect rect, float velocidadX);
        void crearEnemigo(float yInicial, float xInicial, float xFinal, bool invertido);
        void crearLlave(float x, float y);
        void crearPuerta(float x, float y);
        void crearNext(float x, float y);
        void crearCaja(float x, float y);
        void crearPincho(float x, float y);
        void crearObjeto(float x, float y, int tipo);

        void cargarMapa(const char* tilemap);
        void reiniciar();


    protected:

    private:
        int id;

        Mapa *mapa;
        std::vector<Enemigo*> enemigos;
        std::vector<Llave*> llaves;
        std::vector<Puerta*> puertas;
        std::vector<Objeto*> objetos;
        std::vector<Caja*> cajas;
        std::vector<Pincho*> pinchos;

        Font *fontNexts;
        std::vector<Text*> nexts;

};

#endif // NIVEL_H
