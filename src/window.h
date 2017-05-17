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

    sf::Font font;
    sf::Texture tileList;

    Cell ***cell;
    int cols, rows;
    int size;

    int isStartSet;
    int isFinishSet;
    int isBeginAnalysis;
    int isProcedCells;
    Cell* previousCell;

    int drawText(std::string,int,int,int);
    int drawColsRows();
    int drawSprites(int);
    int procCells(int);
    int startProc(int);
    int findNextCell(int);

    std::string toString(int);
    Cell* compareCells(int, Cell*, Cell*);

    int onKeyPressed(sf::Keyboard::Key);
    int onMouseRelease(sf::Mouse::Button, int, int);
    int onMousePress(sf::Mouse::Button, int, int);
    int onMouse(int, int);
public:
    Window(int, int, std::string);
    int mainLoop();
    ~Window();
};

#endif
