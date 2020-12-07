//
// Created by Admin on 05.12.2020.
//

#ifndef PROJECT_2D_GAME_VIEW_H
#define PROJECT_2D_GAME_VIEW_H

#include <SFML/Graphics.hpp>
using namespace sf;

View view;

void getPlayerCoordinateForView(float x,float y) {
    float tempX = x, tempY = y;
    if (x < 320)
        tempX = 320;
    if (y < 240)
        tempY= 240;
    if (y > 554)
        tempY = 554;
    view.setCenter(tempX, tempY);
}

#endif //PROJECT_2D_GAME_VIEW_H
