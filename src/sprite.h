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
public:
    virtual int step() {return 0;}
    virtual int destroy() {return 0;}
    Sprite(){}
    Sprite(sf::Vector2i pos, sf::Texture* texture, sf::RenderWindow* app) {
        this->app = app;
        position = pos;
        spriteIndex.setTexture(*texture);
        spriteIndex.setPosition(position.x,position.y);
    }
};

// CELL
class Cell : public Sprite {
private:
    std::string type;

public:
    int step();
    std::string change(std::string);

    Cell() : Sprite() {}
    Cell(sf::Vector2i arg0, sf::Texture* arg1, sf::RenderWindow* arg2) :
         Sprite(arg0, arg1, arg2) {
             change("free");
         }
};

#endif
