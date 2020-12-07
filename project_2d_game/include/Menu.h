//
// Created by Admin on 07.12.2020.
//

#ifndef PROJECT_2D_GAME_MENU_H
#define PROJECT_2D_GAME_MENU_H

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
            if (menuNum == 1)
                return "Game";
            if (menuNum == 2) {
                /*window.display();
                while (!Keyboard::isKeyPressed(Keyboard::Escape));*/
            }
            if (menuNum == 3)  {
                window.close();
                return "Exit";
            }

            button.play();
        }
        return "Menu";
    }
};

class Death{
private:
    Font _font;
    Text _text;
    Texture _texture;
    Sprite _sprite;
public:
    Death(String font, String text, String texture){
        _font.loadFromFile(font);
        _text.setFont(_font);
        _text.setString(text);
        _text.setFillColor(Color::Black);

        _texture.loadFromFile("../src/images/missionbg.jpg");
        _sprite.setTexture(_texture);

        _text.setPosition(250, 200);
        _sprite.setPosition(200, 0);
    }

    void drawDeath(RenderWindow &window){
        window.draw(_sprite);
        window.draw(_text);
    }

    String control(RenderWindow &window){
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
        return "Death";
    }
};

#endif //PROJECT_2D_GAME_MENU_H
