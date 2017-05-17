#include "window.h"

Window::Window(int w, int h, std::string t) {
    width = w; height = h; title = t;
    new(&app) sf::RenderWindow(sf::VideoMode(width, height), title,
                         sf::Style::Titlebar | sf::Style::Close);
    tileList.loadFromFile("tilelist.png");

    int size = 32;
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

    app.clear();
    for(int i = 0; i<cols; i++) {
        for(int j = 0; j<rows; j++) {
            cell[i][j]->step();
        }
    }

    while (app.isOpen()) {
        while (app.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                app.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                    app.close();
        }
        app.display();
    }

    return 0;
}

Window::~Window() {

}
