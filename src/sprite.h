#ifndef SPRITE_PROJECT
#define SPRITE_PROJECT

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// SPRITE
class Sprite {
protected:
    sf::Vector2i position;
    sf::IntRect texture_coords;
    sf::Sprite sprite_index;
    sf::RenderWindow* app;
public:
    virtual int step() {return 0;}
    virtual int destroy() {return 0;}
    Sprite(){}
    Sprite(sf::Vector2i pos, sf::Texture* texture, sf::RenderWindow* app) {
        this->app = app;
        position = pos;
        int spriteSize = 32;
        texture_coords = sf::IntRect(0,0,spriteSize,spriteSize);
        sprite_index.setTexture(*texture);
        sprite_index.setTextureRect(texture_coords);
        sprite_index.setPosition(position.x,position.y);
    }
};

// CELL
class Cell : public Sprite {

public:
    int step() {app->draw(sprite_index); return 0;}

    Cell() : Sprite() {}
    Cell(sf::Vector2i arg0, sf::Texture* arg1, sf::RenderWindow* arg2) :
         Sprite(arg0, arg1, arg2) {
             int spriteSize = 32;
             texture_coords = sf::IntRect(0,3*spriteSize,spriteSize,spriteSize);
             sprite_index.setTextureRect(texture_coords);
         }
};

#endif
