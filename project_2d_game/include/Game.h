//
// Created by Admin on 07.12.2020.
//

#ifndef PROJECT_2D_GAME_GAME_H
#define PROJECT_2D_GAME_GAME_H

#include <iostream>
#include "Player.h"
#include "Mission.h"
#include "Menu.h"
#include <sstream>

int drawDeathView(RenderWindow &window){



    return 0;
}

bool startGame(){
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

    Map map1(TileMap1, 1, "map.png");
    Menu menu("../src/musics/knopka.ogg", "../src/images/menu.jpg", "../src/images/bg1.png");
    Death death("../src/fonts/20011.ttf", "You died\nTo go to menu\npress Space\n\nTo exit\npress Esc\n", "../src/images/missionbg.jpg");
    bool showMissionText = true;
    Font font;
    font.loadFromFile("../src/fonts/20011.ttf");
    Text text("", font, 14);
    text.setFillColor(Color::Black);

    Texture quest_texture;
    quest_texture.loadFromFile("../src/images/missionbg.jpg");
    Sprite s_quest;
    s_quest.setTexture(quest_texture);
    s_quest.setScale(0.6f, 0.6f);

    Clock clock;

    Music music;
    music.openFromFile("../src/musics/srednevekove-950.ogg");
    music.setLoop(true);
    //music.play();

    Player p("hero.png", 32, 32, 96.0, 96.0);
    String currentMode = "Menu";
    while (window.isOpen()){
        if (currentMode == "Menu") {
            p.resetPlayer(32, 32, 96.0, 96.0);
            map1.resetMap(TileMap1);
            view.reset(FloatRect(0, 0, windowWidth, windowHeight));
            window.setView(view);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            currentMode = menu.controlMenu(window);
            if (currentMode == "Game")
                view.reset(FloatRect(0, 0, 640, 480));


            window.clear();
            menu.drawMenu(window);
            window.display();

        }
        else if (currentMode == "Game"){
            window.setView(view);
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Tab) {
                        switch (showMissionText) {
                            case true: {
                                std::ostringstream playerHealthString, playerScore;
                                playerHealthString << p.health;
                                playerScore << p.playerScore;
                                std::ostringstream task;
                                task << getTextMission(getCurrentMission(p.x));
                                text.setString(playerScore.str()+"\n" + task.str());
                                text.setPosition(view.getCenter().x + 125, view.getCenter().y - 110);
                                s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);
                                showMissionText = false;
                                break;
                            }
                            case false: {
                                text.setString("");
                                showMissionText = true;
                                break;
                            }
                        }
                    }
            }


            p.update(time, map1);

            window.clear();
            map1.drawMap(window);
            drawStats(window, p);

            if (!showMissionText) {
                std::ostringstream playerHealthString, playerScore;
                playerHealthString << p.health;
                playerScore << p.playerScore;
                std::ostringstream task;
                task << getTextMission(getCurrentMission(p.x));
                text.setString(task.str());
                text.setPosition(view.getCenter().x + 125, view.getCenter().y - 110);
                s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);
                window.draw(s_quest);
                window.draw(text);
            }

            window.draw(p.sprite);
            window.display();
            if (!p.life)
                currentMode = "Death";

        } else if (currentMode == "Death") {
            view.reset(FloatRect(0, 0, 640, 480));
            window.setView(view);
            window.clear(Color(140, 80, 25));
            currentMode = death.control(window);
            death.drawDeath(window);
            window.display();
        } else if (currentMode == "Exit"){
            window.close();
            return false;
        }
    }
    return false;
}

void gameRunnig(){
    if (startGame())
        gameRunnig();
}

#endif //PROJECT_2D_GAME_GAME_H
