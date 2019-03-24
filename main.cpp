#include <SFML/Graphics.hpp>
#include "Juego.h"

int main()
{
    Juego * juego = new Juego(sf::Vector2i(800, 600), "The Castle");

    return 0;
}
