//
// Created by Admin on 05.12.2020.
//

#ifndef PROJECT_2D_GAME_PLAYER_H
#define PROJECT_2D_GAME_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include "View.h"

using namespace sf;

class Player {

public:
    float x, y, currentFrame, w, h, dx, dy, speed;
    int dir, playerScore, health;
    bool life;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    Player(const String& F, float X, float Y, float W, float H){
        File = F;
        dir = playerScore = 0;
        health = 100;
        dx = dy = speed = currentFrame = 0;
        life = true;
        w = W;
        h = H;
        image.loadFromFile("../src/images/" + File);
        image.createMaskFromColor(Color(41, 33, 59));
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        x = X;
        y = Y;
        sprite.setTextureRect(IntRect(0, 0, w, h));
    }

    void control(float time){
        if (life) {
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                dir = 1;
                speed = 0.1;
                currentFrame += 0.005*time;
                if (currentFrame > 3)
                    currentFrame -= 3;
                sprite.setTextureRect(IntRect(96 * int(currentFrame), 96, 96, 96));
            }

            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                dir = 0;
                speed = 0.1;
                currentFrame += 0.005*time;
                if (currentFrame > 3)
                    currentFrame -= 3;
                sprite.setTextureRect(IntRect(96 * int(currentFrame), 192, 96, 96));
            }

            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                dir = 3;
                speed = 0.1;
                currentFrame += 0.005*time;
                if (currentFrame > 3)
                    currentFrame -= 3;
                sprite.setTextureRect(IntRect(96 * int(currentFrame), 307, 96, 96));
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) {
                dir = 2;
                speed = 0.1;
                currentFrame += 0.005*time;
                if (currentFrame > 3)
                    currentFrame -= 3;
                sprite.setTextureRect(IntRect(96 * int(currentFrame), 0, 96, 96));
            }
            getPlayerCoordinateForView(x, y);
        }
    }

    void update(float time, Map &currentMap){
        control(time);
        switch (dir)
        {
            case 0:
                dx = speed;
                dy = 0;
                break;
            case 1:
                dx = -speed;
                dy = 0;
                break;
            case 2:
                dx = 0;
                dy = speed;
                break;
            case 3:
                dx = 0;
                dy = -speed;
                break;
        }

        x += dx*time;
        y += dy*time;

        speed = 0;
        sprite.setPosition(x,y);
        interactionWithMap(currentMap);
        if (health <= 0)
            life = false;

    }

    void interactionWithMap(Map &currentMap){

        for (int i = y / 32; i < (y + h) / 32; i++)
            for (int j = x / 32; j<(x + w) / 32; j++)
            {
                if (currentMap.getTile(i, j) == '0')
                {
                    if (dy>0)
                        y = i * 32 - h;
                    if (dy<0)
                        y = i * 32 + 32;
                    if (dx>0)
                        x = j * 32 - w;
                    if (dx < 0)
                        x = j * 32 + 32;
                }

                if (currentMap.getTile(i, j) == 's') {
                    playerScore += 1;
                    currentMap.setTile(i, j, ' ');
                }

                if (currentMap.getTile(i, j) == 'f') {
                    health-=40;
                    currentMap.setTile(i, j, ' ');
                }

                if (currentMap.getTile(i, j) == 'h') {
                    health += 20;
                    currentMap.setTile(i, j, ' ');
                }
            }
    }

    void resetPlayer(float X, float Y, float W, float H){
            dir = playerScore = 0;
            health = 100;
            dx = dy = speed = currentFrame = 0;
            life = true;
            w = W;
            h = H;
            x = X;
            y = Y;
            sprite.setTextureRect(IntRect(0, 0, w, h));
    }
};


#endif //PROJECT_2D_GAME_PLAYER_H
