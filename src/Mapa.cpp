#include "Mapa.h"
#include "../lib/tinyxml/tinyxml2.h"

using namespace tinyxml2;

Mapa::Mapa()
{
    mapTexture = new Texture();

    load();

}

void Mapa::load()
{

    XMLDocument doc;
    XMLError error = doc.LoadFile("assets/maps/nivel1.tmx");

    if(error)
    {
        cout << "Error reading tmx file" << endl;
        exit(0);
    }

    XMLElement * map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", &width);
    map->QueryIntAttribute("height", &height);
    map->QueryIntAttribute("tilewidth", &tileWidth);
    map->QueryIntAttribute("tileheight", &tileHeight);

    cout<<"Width: " << width << " Height: " << height <<endl;
    cout<<"Tilewidth: " << tileWidth << " Tileheight: " << tileHeight <<endl;


    tilesetColumns = 33;



    mapTexture->loadFromFile("assets/maps/tileset.png");

    XMLElement *layer = map->FirstChildElement("layer");
    while(layer)
    {
        numLayers++;
        layer = layer->NextSiblingElement("layer");
    }

    // inicializamos la matriz de gids que tiene nuestor mapa
    tileMap = new int**[numLayers];
    for(int i = 0; i < numLayers; i++)
    {
        tileMap[i] = new int *[height];
    }
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            tileMap[l][y] = new int[width];
            for(int x = 0; x < width; x++)
            {
                tileMap[l][y][x] = 0; // inicializamos a 0 porque si no se vuelve loquisimo
            }
        }
    }

    layer = map->FirstChildElement("layer");
    XMLElement * tile ;
    while(layer)
    {
        tile = layer->FirstChildElement("data")->FirstChildElement("tile");

        for (int l = 0; l < numLayers; l++)   // para cada capa del mapa
        {
            for(int y = 0; y < height; y++)   // para cada fila del tilemap
            {
                for(int x = 0; x < width; x++)
                {

                    tile->QueryIntAttribute("gid", &tileMap[l][y][x]);
                    tile = tile->NextSiblingElement("tile");
                }
            }
        }
        layer = layer->NextSiblingElement("layer");
    }


    cout << "============ RESULTADO DE LECTURA =============" << endl;
    cout << "Width del mapa -> " << width << endl;
    cout << "Height del mapa -> " << height << endl;
    cout << "===============================================" << endl;

    // for testing
    // printTileMap();

    setTileMapSprites();
}

void Mapa::printTileMap()
{
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                cout << tileMap[l][y][x] << ", ";
            }
            cout << endl;
        }
    }
}

void Mapa::setTileMapSprites()
{

    tilemapSprite = new Sprite***[numLayers];

    for (int l = 0; l < numLayers; l++)
    {
        tilemapSprite[l] = new sf::Sprite**[height];
    }

    for(int l=0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            tilemapSprite[l][y] = new Sprite*[width];
            for(int x = 0; x< width; x++)
            {
                tilemapSprite[l][y][x] = new Sprite();
            }
        }
    }

    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {

                int gid = tileMap[l][y][x];

                if(gid > 0)
                {
                    int xAux=gid%tilesetColumns, yAux=gid/tilesetColumns;

                    tilemapSprite[l][y][x] = new Sprite(*mapTexture);
                    tilemapSprite[l][y][x]->setTextureRect(IntRect((xAux-1)*tileWidth, yAux*tileHeight, tileWidth, tileHeight));
                    tilemapSprite[l][y][x]->setPosition(x*(tileWidth) - 1, y*(tileHeight) - 1);
                } else {
                    tilemapSprite[l][y][x] = NULL;
                }
            }
        }
    }
}

void Mapa::draw(RenderWindow * window)
{
    for(int l = 0; l < numLayers; l++)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                if(tilemapSprite[l][y][x] != NULL)
                {
                    window->draw(*tilemapSprite[l][y][x]);
                }
            }
        }
    }
}
