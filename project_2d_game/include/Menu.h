//
// Created by Admin on 07.12.2020.
//

#ifndef PROJECT_2D_GAME_MENU_H
#define PROJECT_2D_GAME_MENU_H

#include <sstream>

const int windowWidth = 1600;
const int windowHeight = 960;

class Menu{
private:
    SoundBuffer buttonBuffer;
    Sound button;
    Texture menuTexture, menuBackground;
    Sprite menu1, menu2, menu3, menuBg;
public:
    Menu(const String& sound, const String& menu, const String& bgMenu){
        buttonBuffer.loadFromFile(sound);
        button.setBuffer(buttonBuffer);
        button.setVolume(10);

        menuTexture.loadFromFile(menu);
        menuBackground.loadFromFile(bgMenu);

        menu1.setTexture(menuTexture);
        menu2.setTexture(menuTexture);
        menu3.setTexture(menuTexture);
        menuBg.setTexture(menuBackground);

        menu1.setTextureRect(IntRect(142,100, 571, 190));
        menu1.setPosition(windowWidth/2 - 571/2, 30);

        menu2.setTextureRect(IntRect(142,320, 571, 190));
        menu2.setPosition(windowWidth/2- 571/2, 220);

        menu3.setTextureRect(IntRect(142,760, 571, 190));
        menu3.setPosition(windowWidth/2- 571/2, 410);
        menuBg.setPosition(0, 0);
        menuBg.setScale(2.5f, 3.4f);
    }

    void drawMenu(RenderWindow & window) {
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
    }

    String controlMenu(RenderWindow &window){

        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        int menuNum = 0;

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
            button.play();
            if (menuNum == 1)
                return "Game";
            if (menuNum == 2)
                return "Settings";
            if (menuNum == 3)  {
                window.close();
                return "Exit";
            }

        }
        return "Menu";
    }
};

class Banner{
private:
    Font _font;
    Text _text;
    Texture _texture;
    Sprite _sprite;
public:
    Banner(String font, String text, String texture){
        _font.loadFromFile(font);
        _text.setFont(_font);
        _text.setString(text);
        _text.setFillColor(Color::Black);

        _texture.loadFromFile("../src/images/missionbg.jpg");
        _sprite.setTexture(_texture);

        _text.setPosition(250, 200);
        _sprite.setPosition(200, 0);
    }

    void drawBanner(RenderWindow &window){
        window.draw(_sprite);
        window.draw(_text);
    }

    String control(RenderWindow &window, String currentMode){
        Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Space)
                    return "Menu";
            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Escape)
                    return "Exit";

        }
        return currentMode;
    }
};

void drawStats(RenderWindow &window, Player &player){
    Texture texture;
    texture.loadFromFile("../src/images/missionbg.jpg");
    Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(0.3f, 0.2f);
    sprite.setPosition(view.getCenter().x - 320, view.getCenter().y + 120);

    Font font;
    font.loadFromFile("../src/fonts/20011.ttf");
    std::ostringstream playerHealthString, playerScore;
    playerHealthString << player.health;
    playerScore << player.playerScore;
    Text text("Health - " + playerHealthString.str() + "\nScore - " + playerScore.str(), font, 14);
    text.setPosition(view.getCenter().x - 310, view.getCenter().y + 130);
    text.setColor(Color::Black);
    window.draw(sprite);
    window.draw(text);
}

#endif //PROJECT_2D_GAME_MENU_H
