#ifndef SPRITE_PROJECT
#define SPRITE_PROJECT

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// SPRITE
class Sprite {
protected:
    sf::Vector2i position;
    sf::IntRect textureCoords;
    sf::Sprite spriteIndex;
    sf::RenderWindow* app;
    sf::Font* font;
    sf::Text outputText;
public:
    virtual int step() {return 0;}
    virtual int destroy() {return 0;}
    Sprite(){}
    Sprite(sf::Vector2i pos, sf::Texture* texture,
           sf::RenderWindow* app, sf::Font* usingFont) {
        this->app = app;
        font = usingFont;
        position = pos;
        spriteIndex.setTexture(*texture);
        spriteIndex.setPosition(position.x,position.y);

        outputText.setFont(*font);
        outputText.setPosition(position.x+7,position.y+5);
        outputText.setColor(sf::Color(0,0,0));
        outputText.setString("0");
        outputText.setCharacterSize(16);
    }
};

// CELL
class Cell : public Sprite {
private:
    std::string type;
    int amount;

    std::string toString(int);
public:
    int step();
    int checkAmount();
    std::string getType();
    int setAmount(int);
    std::string change(std::string);

    Cell() : Sprite() {}
    Cell(sf::Vector2i arg0, sf::Texture* arg1, sf::RenderWindow* arg2, sf::Font* arg3) :
         Sprite(arg0, arg1, arg2, arg3) {
             amount = -1;
             change("free");
         }
};

#endif
