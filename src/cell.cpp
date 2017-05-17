#include "sprite.h"

int Cell::step() {
    app->draw(spriteIndex);
    return 0;
}

std::string Cell::change(std::string newType) {
    int spriteSize = 32;
    int imageIndex = 0;
    std::string buffType = type;
    type = newType;
    if (newType == "wall") {
        imageIndex = 0;
    }
    if (newType == "free") {
        imageIndex = 3;
    }
    if (newType == "start") {
        imageIndex = 6;
    }
    if (newType == "finish") {
        imageIndex = 5;
    }
    textureCoords = sf::IntRect(0,imageIndex*spriteSize,
                                 spriteSize,spriteSize);
    spriteIndex.setTextureRect(textureCoords);
    return buffType;
}
