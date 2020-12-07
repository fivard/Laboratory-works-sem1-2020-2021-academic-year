//
// Created by Admin on 07.12.2020.
//

#ifndef PROJECT_2D_GAME_GAME_H
#define PROJECT_2D_GAME_GAME_H

#include <iostream>
#include "Player.h"
#include "Mission.h"
#include <sstream>

const int windowWidth = 1600;
const int windowHeight = 960;

bool drawMenu(RenderWindow & window) {

    SoundBuffer buttonBuffer;
    buttonBuffer.loadFromFile("../src/musics/knopka.ogg");
    Sound button(buttonBuffer);
    button.setVolume(10);

    Image menu;
    menu.loadFromFile("../src/images/menu.jpg");
    menu.createMaskFromColor(Color(255, 255, 255));
    menu.createMaskFromColor(Color(255, 243, 205));
    menu.createMaskFromColor(Color(245, 246, 238));

    Texture menuTexture, menuBackground;
    menuTexture.loadFromImage(menu);
    menuBackground.loadFromFile("../src/images/bg1.png");
    Sprite menu1(menuTexture), menu2(menuTexture), menu3(menuTexture), menuBg(menuBackground);
    int menuNum = 0;
    menu1.setTextureRect(IntRect(142,100, 571, 190));
    menu1.setPosition(windowWidth/2 - 571/2, 30);

    menu2.setTextureRect(IntRect(142,320, 571, 190));
    menu2.setPosition(windowWidth/2- 571/2, 220);

    menu3.setTextureRect(IntRect(142,760, 571, 190));
    menu3.setPosition(windowWidth/2- 571/2, 410);
    menuBg.setPosition(0, 0);
    menuBg.setScale(2.5f, 3.4f);

    menu1.setColor(Color::White);
    menu2.setColor(Color::White);
    menu3.setColor(Color::White);
    menuNum = 0;

    if (IntRect(windowWidth/2 - 571/2, 30, 571, 190).contains(Mouse::getPosition(window))) {
        menu1.setColor(Color::Blue);
        menuNum = 1;
    }
    if (IntRect(windowWidth/2 - 571/2, 220, 571, 190).contains(Mouse::getPosition(window))) {
        menu2.setColor(Color::Blue);
        menuNum = 2;
    }
    if (IntRect(windowWidth/2 - 571/2, 410, 571, 190).contains(Mouse::getPosition(window))) {
        menu3.setColor(Color::Blue);
        menuNum = 3;
    }

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        if (menuNum == 1)
            return false;
        if (menuNum == 2) {
            window.display();
            while (!Keyboard::isKeyPressed(Keyboard::Escape));
        }
        if (menuNum == 3)  {
            window.close();
            return false;
        }

        button.play();
    }

    window.clear();
    window.draw(menuBg);
    window.draw(menu1);
    window.draw(menu2);
    window.draw(menu3);

    window.display();
    return true;
}

bool drawDeathView(RenderWindow &window){
    Font font;
    font.loadFromFile("../src/fonts/20011.ttf");
    Text text("You died\nTo go to menu\n press Space\n", font, 14);
    text.setFillColor(Color::Black);

    Texture quest_texture;
    quest_texture.loadFromFile("../src/images/missionbg.jpg");
    Sprite s_quest;
    s_quest.setTexture(quest_texture);
    s_quest.setScale(0.6f, 0.6f);



    text.setPosition(200, 200);
    s_quest.setPosition(150, 150);
    window.draw(s_quest);
    window.draw(text);
    window.display();
    Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
            if (event.key.code == Keyboard::Space)
                return true;
        if (event.type == Event::KeyPressed)
            if (event.key.code == Keyboard::Escape)
                return false;

    }
}

bool startGame(){
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");
    Map map1(TileMap1, 1, "map.png");

    //bool showMissionText = true;
    /*Font font;
    font.loadFromFile("../src/fonts/20011.ttf");
    Text text("", font, 14);
    text.setFillColor(Color::Black);

    Texture quest_texture;
    quest_texture.loadFromFile("../src/images/missionbg.jpg");
    Sprite s_quest;
    s_quest.setTexture(quest_texture);
    s_quest.setScale(0.6f, 0.6f);*/


    view.reset(FloatRect(0, 0, 640, 480));

    Clock clock;

    Music music;
    music.openFromFile("../src/musics/srednevekove-950.ogg");
    music.setLoop(true);
    music.play();

    Player p("hero.png", 32, 32, 96.0, 96.0);

    bool menu = true, deathView = false;
    while (window.isOpen()){
        if (menu) {
            menu = drawMenu(window);
            p.resetPlayer(32, 32, 96.0, 96.0);
        }
        else {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;

            Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                /*if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Tab) {
                        switch (showMissionText) {
                            case true: {
                                std::ostringstream playerHealthString, playerScore;
                                playerHealthString << p.health;
                                playerScore << p.playerScore;
                                std::ostringstream task;
                                task << getTextMission(getCurrentMission(p.x));
                                text.setString("Health: " + playerHealthString.str()+"\n" + "Score: " + playerScore.str()+"\n" + task.str());
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
                    }*/
            }


            p.update(time, map1);

            window.setView(view);
            window.clear();
            map1.drawMap(window);

            /*if (!showMissionText) {
                std::ostringstream playerHealthString, playerScore;
                playerHealthString << p.health;
                playerScore << p.playerScore;
                std::ostringstream task;
                task << getTextMission(getCurrentMission(p.x));
                text.setString("Health: " + playerHealthString.str()+"\n" + "Score: " + playerScore.str()+"\n" + task.str());
                text.setPosition(view.getCenter().x + 125, view.getCenter().y - 110);
                s_quest.setPosition(view.getCenter().x + 115, view.getCenter().y - 130);
                window.draw(s_quest);
                window.draw(text);
            }*/

            window.draw(p.sprite);
            window.display();
            if (!p.life)
                deathView = true;
        }
        if (deathView){
            menu = drawDeathView(window);
            if (!menu)
                window.close();
            else
                deathView = false ;
        }
    }
    return false;
}

void gameRunnig(){
    if (startGame())
        gameRunnig();
}

#endif //PROJECT_2D_GAME_GAME_H
