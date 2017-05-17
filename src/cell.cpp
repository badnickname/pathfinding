#include "sprite.h"

int Cell::step() {
    app->draw(spriteIndex);
    if (amount != -1) {
        app->draw(outputText);
    }
    return 0;
}

std::string Cell::getType() {
    return type;
}

int Cell::checkAmount() {
    //if (type == "finish") amount = 0;
    return amount;
}

int Cell::setAmount(int newAmount) {
    if (type != "wall" && amount == -1) {
        amount = newAmount;
        outputText.setString(toString(amount));

        if (type != "finish" && type != "start") change("checked");
        return 0;
    }
    return 1;
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
    if (newType == "checked") {
        imageIndex = 4;
    }
    if (newType == "steped") {
        imageIndex = 5;
    }
    if (newType == "current") {
        imageIndex = 1;
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

std::string Cell::toString(int number) {
    std::string str = "";
    for(str = ""; number; number /= 10)
        str += (char)('0' + number%10);
    reverse(str.begin(), str.end());
    return str;
}
