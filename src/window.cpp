#include "window.h"

Window::Window(int w, int h, std::string t) {
    width = w; height = h; title = t;
    new(&app) sf::RenderWindow(sf::VideoMode(width, height), title,
                         sf::Style::Titlebar | sf::Style::Close);
    tileList.loadFromFile("tilelist.png");
    font.loadFromFile("font.ttf");

    isStartSet = 0;
    isFinishSet = 0;
    size = 32;
    cols = width / size;
    rows = height / size;
    cell = new Cell**[cols];
    for(int i=0; i<cols; i++) {
        cell[i] = new Cell*[rows];
    }
    for(int i = 0; i<cols; i++) {
        for(int j = 0; j<rows; j++) {
            cell[i][j] = new Cell(sf::Vector2i(i*size,j*size),&tileList,&app);
        }
    }
}

int Window::mainLoop() {
    sf::Event event;

    while (app.isOpen()) {
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                app.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                app.close();
            if (event.type == sf::Event::MouseButtonReleased)
                onMouseRelease(event.mouseButton.button,
                               event.mouseButton.x, event.mouseButton.y);
            if (event.type == sf::Event::MouseButtonPressed)
                onMousePress(event.mouseButton.button,
                               event.mouseButton.x, event.mouseButton.y);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                sf::Vector2i pos = sf::Mouse::getPosition(app);
                onMouse(pos.x,pos.y);
            }
        }

        app.clear();

        drawSprites(1);
        drawColsRows();

        app.display();
    }

    return 0;
}

int Window::onMouseRelease(sf::Mouse::Button button, int x, int y) {
    Cell *pointer;
    if ((pointer = cell[x/size][y/size]) != NULL) {
        if (button == sf::Mouse::Left) {
            if (isStartSet == 0) {
                isStartSet = 1;
                pointer->change("start");
            } else {
                if (isFinishSet == 0) {
                    isFinishSet = 1;
                    pointer->change("finish");
                }
            }
        }
    }
    return 0;
}

int Window::onMousePress(sf::Mouse::Button button, int x, int y) {
    /*Cell *pointer;
    if ((pointer = cell[x/size][y/size]) != NULL) {
        if (button == sf::Mouse::Right) {
            pointer->change("wall");
        }
    }*/
    return 0;
}

int Window::onMouse(int x, int y) {
    Cell *pointer;
    if ((pointer = cell[x/size][y/size]) != NULL) {
        std::string deletedType;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            deletedType = pointer->change("free");
        else
            deletedType = pointer->change("wall");

        if (deletedType == "finish") isFinishSet = 0;
        if (deletedType == "start") isStartSet = 0;
    }
    return 0;
}

int Window::drawText(std::string text, int x, int y, int size) {
    sf::Text outputText;
    outputText.setFont(font);
    outputText.setPosition(x,y);
    outputText.setString(text);
    outputText.setCharacterSize(size);
    outputText.setColor(sf::Color(255, 255, 255));
    app.draw(outputText);
    return 0;
}

int Window::drawSprites(int border) {
    for(int i = border; i<cols; i++) {
        for(int j = border; j<rows; j++) {
            cell[i][j]->step();
        }
    }
    return 0;
}

int Window::drawColsRows() {
    for(int i=0; i<rows; i++) {
        std::string str = "";
        str += toString(i);
        drawText(str,10,i*32+5,16);
    }

    for(int i=0; i<cols; i++) {
        std::string str = "";
        str += toString(i);
        drawText(str,i*32+8,10,16);
    }
    return 0;
}

std::string Window::toString(int number) {
    std::string str = "";
    for(str = ""; number; number /= 10)
        str += (char)('0' + number%10);
    reverse(str.begin(), str.end());
    return str;
}

Window::~Window() {

}
