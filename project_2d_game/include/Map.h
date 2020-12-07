//
// Created by Admin on 05.12.2020.
//

#ifndef PROJECT_2D_GAME_MAP_H
#define PROJECT_2D_GAME_MAP_H

#include <SFML\Graphics.hpp>

using namespace sf;

const int heightMap = 25;
const int widthMap = 40;

String TileMap1[heightMap] = {
            "0000000000000000000000000000000000000000",
            "0                                      0",
            "0      sssss                           0",
            "0                                      0",
            "00000000000    000000    000           0",
            "0    hhh0      0                       0",
            "0              0                       0",
            "0     ss       0 h                     0",
            "0              0                       0",
            "0      000000000                       0",
            "0                          h           0",
            "0                                      0",
            "0                                      0",
            "0                                      0",
            "0       00000000000000                 0",
            "0       0            0      f          0",
            "0       0     f      0                 0",
            "0       0 s          0                 0",
            "0       0 ss         0                 0",
            "0       0000000      0       f         0",
            "0             0      0                 0",
            "0                    0                 0",
            "0        f    s      0        s        0",
            "0             s      0        s        0",
            "0000000000000000000000000000000000000000",
            };

String TileMap2[heightMap] = {
        "0000000000000000000000000000000000000000",
        "0                s                     0",
        "0           s    f s                   0",
        "0                 0000000000           0",
        "0              000000    000           0",
        "0    hhh0      0                       0",
        "0              0                       0",
        "0     ss       0 h                     0",
        "0              0                       0",
        "0      000000000         0000          0",
        "0                          h           0",
        "0                          00          0",
        "0                                      0",
        "0                                      0",
        "0       00000000000000                 0",
        "0       0            0      f          0",
        "0       0     f      0                 0",
        "0       0 s          0                 0",
        "0       0 ss         0                 0",
        "0                    0       f         0",
        "0             0      0                 0",
        "0                    0                 0",
        "0        f    s      0        s        0",
        "0             s      0        s        0",
        "0000000000000000000000000000000000000000",
};

class Map{
private:
    String _map[heightMap];
    Texture _texture;
    Sprite _sprite;

public:
    int neededScore;
    Map(String newMap[], String fileNameTexture, int score){
        for (int i = 0; i < heightMap; i++)
            _map[i] = newMap[i];
        _texture.loadFromFile("../src/images/"+fileNameTexture);
        _sprite.setTexture(_texture);
        neededScore = score;
    }

    void drawMap(RenderWindow &window){
        for (int i = 0; i < heightMap; i++)
            for (int j = 0; j < widthMap; j++)
            {
                if (_map[i][j] == ' ')
                    _sprite.setTextureRect(IntRect(0, 0, 32, 32));
                if (_map[i][j] == 's')
                    _sprite.setTextureRect(IntRect(32, 0, 32, 32));
                if (_map[i][j] == '0')
                    _sprite.setTextureRect(IntRect(64, 0, 32, 32));
                if (_map[i][j] == 'f')
                    _sprite.setTextureRect(IntRect(96, 0, 32, 32));
                if (_map[i][j] == 'h')
                    _sprite.setTextureRect(IntRect(128, 0, 32, 32));
                _sprite.setPosition(j * 32, i * 32);
                window.draw(_sprite);
            }
    }

    String getTile(int i, int j){
        return _map[i][j];
    }

    void setTile(int i, int j, char newTile){
        _map[i][j] = newTile;
    }


    void resetMap(String newMap[]){
        for (int i = 0; i < heightMap; i++)
            _map[i] = newMap[i];
    }
};





#endif //PROJECT_2D_GAME_MAP_H
