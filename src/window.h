#ifndef WINDOW_PROJECT
#define WINDOW_PROJECT

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "sprite.h"

class Window {
private:
    sf::RenderWindow app;
    std::string title;
    int width, height;
    sf::Texture tileList;

    Cell ***cell;
    int cols, rows;
public:
    Window(int, int, std::string);
    int mainLoop();
    ~Window();
};

#endif
