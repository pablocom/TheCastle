#include "Enemigo.h"

Enemigo::Enemigo(float yInicial, float xIni, float xFin, bool invertido)
{
    //ctor

    yInicial = yInicial;
    xInicial = xIni;
    xFinal = xFin;

    /**ANIMACION ANDANDO**/

    walk_txt = new Texture();
    walk_txt->loadFromFile("assets/enemigo/skeleton_walk.png");
    walk_spr = new Sprite(*walk_txt);

    walk_spr->setScale(0.7, 0.6);
    walk_spr->setOrigin(11, 16.5);
    walk_spr->setTextureRect(IntRect(walk_sprite_active*22, 0, 22, 33));
    walk_spr->setPosition(xInicial, yInicial);

    /**ANIMACION MUERTE**/

    dead_txt = new Texture();
    dead_txt->loadFromFile("assets/enemigo/skeleton_dead.png");
    dead_spr = new Sprite(*dead_txt);

    dead_spr->setScale(0.7, 0.6);
    dead_spr->setOrigin(11, 16.5);
    dead_spr->setTextureRect(IntRect(4 + dead_sprite_active*33, 0, 33, 33));

    clockAnimation = new Clock();
    clockMuerte = new Clock();
    animate();

    initEnemigo();

    if(invertido)
    {
        walk_spr->setPosition(xFinal - 1, walk_spr->getPosition().y);
    }

    xAux = walk_spr->getPosition().x;
    yAux = walk_spr->getPosition().y;
}

Enemigo::~Enemigo()
{
    //dtor
}

void Enemigo::draw(RenderWindow *w)
{
    if(!muriendo)
    {
        w->draw(*walk_spr);
    }
    else
    {
        w->draw(*dead_spr);
    }
    animate();
}

void Enemigo::animate()
{

    if(!muriendo)
    {
        if(clockAnimation->getElapsedTime().asSeconds() > 0.05)
        {

            if(walk_sprite_active == 12)
            {
                walk_sprite_active = 0;
            }
            else
            {
                walk_sprite_active++;
            }
            clockAnimation->restart();
            updateFrame();
        }
    }
    else
    {
        if(clockMuerte->getElapsedTime().asSeconds() > 0.02)
        {

            if(dead_sprite_active == 15)
            {
                dead_sprite_active = 0;
                muerto = true;
            }
            else
            {
                dead_sprite_active++;
            }
            clockMuerte->restart();
            updateFrame();
        }
    }
}

void Enemigo::updateFrame()
{
    if(!muriendo)
    {
        if(velocidad.x > 0)
        {
            walk_spr->setTextureRect(IntRect(walk_sprite_active*22, 0, 22, 33));
        }
        else
        {
            walk_spr->setTextureRect(IntRect(walk_sprite_active * 22 + 22, 0, -22, 33));
        }
    }
    else
    {
        dead_spr->setTextureRect(IntRect(4 + dead_sprite_active*33, 0, 33, 33));
    }
}

void Enemigo::initEnemigo()
{
    if(xInicial > xFinal)
    {
        velocidad.x = -1;
    }
    else
    {
        velocidad.x = 1;
    }
}

void Enemigo::update(Mapa *mapa, std::vector<Puerta*> puertas, std::vector<Caja*> cajas)
{
    for(unsigned i = 0; i < puertas.size(); i++)
    {
        if(walk_spr->getGlobalBounds().intersects(puertas[i]->getSprite().getGlobalBounds()))
        {
            velocidad.x = -velocidad.x; /// invertimos la velocidad
        }
    }

    for(unsigned i = 0; i < cajas.size(); i++)
    {
        if(walk_spr->getGlobalBounds().intersects(cajas[i]->getSprite().getGlobalBounds()))
        {
            if(cajas[i]->getMoviendo() != 0)
            {
                velocidad.x = 0;
                muriendo = true;
                dead_spr->setPosition(walk_spr->getPosition().x, walk_spr->getPosition().y);
                clockMuerte->restart();
            }

            velocidad.x = -velocidad.x;
        }
    }

    if(walk_spr->getPosition().x > xFinal || walk_spr->getPosition().x < xInicial)
    {
        velocidad.x = -velocidad.x;
    }

    walk_spr->setPosition(walk_spr->getPosition().x + velocidad.x, walk_spr->getPosition().y);
}

bool Enemigo::checkearColision(FloatRect rect)
{
    if(walk_spr->getGlobalBounds().intersects(rect) && muriendo == false)
    {
        return true;
    }
    return false;
}

void Enemigo::reiniciar()
{
    walk_spr->setPosition(xAux, yAux);
}
