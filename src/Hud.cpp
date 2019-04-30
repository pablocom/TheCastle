#include "Hud.h"

Hud::Hud()
{
    //ctor

    font = new Font();
    font->loadFromFile("assets/maps/fullPack2025.ttf");

    texts.push_back(new Text());
    texts[0]->setFont(*font);
    texts[0]->setCharacterSize(9);
    texts[0]->setString("LIFES ");
    texts[0]->setPosition(5, 2);

    texts.push_back(new Text());
    texts[1]->setFont(*font);
    texts[1]->setCharacterSize(9);
    texts[1]->setString("SCORE ");
    texts[1]->setPosition(5, 13);

    texts.push_back(new Text());
    texts[2]->setFont(*font);
    texts[2]->setCharacterSize(9);
    texts[2]->setString("0000");
    texts[2]->setPosition(60, 13);

    txt_vida = new Texture();
    txt_vida->loadFromFile("assets/objetos/corazon.png");
    spr_vida = new Sprite(*txt_vida);
    spr_vida->scale(.025, .025);
}

Hud::~Hud()
{
    //dtor
}

void Hud::update(Jugador *j)
{
    puntuacion = j->getPuntuacion();
    vidas = j->getVidas();
    llaves = j->getLlaves();

    texts[2]->setString(std::to_string(puntuacion));
}

void Hud::draw(RenderWindow *w)
{
    for(int i = 0; i < texts.size(); i++)
    {
        w->draw(*texts[i]);
    }
    for(int i = 0; i < vidas; i++)
    {
        w->draw(*spr_vida);
        spr_vida->setPosition(50 + i * 15, spr_vida->getPosition().y);
    }

}
