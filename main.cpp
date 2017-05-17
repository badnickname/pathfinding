#include <SFML/Graphics.hpp>
#include "src/window.h"

int main() {
    Window win(640,480,"Pathfinding");
    win.mainLoop();
    return 0;
}
