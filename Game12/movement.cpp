#include <iostream>
#include <algorithm>

#include "movement.h"
#include "foes.h"
#include "map.h"

// Checks character's direction:

std::string checkDirection () {

    std::string direction;

    do {
        std::cout << "\nWhich direction do you want to move? (up / down / left / right)\n";
        std::cin >> direction;
        std::transform (direction.begin(), direction.end(), direction.begin(), ::tolower);
    } while (direction != "up" && direction != "down" && direction != "left" & direction != "right");

    return direction;

}

// Moves the character vertiaclly:

int movingVertically (std::string direction, int i) {

    if (direction == "up") {
        i--;
    } else {
        i++;
    }

    return i;

}

// Moves the character horizontally:

int movingHorizontally (std::string direction, int j) {

    if (direction == "left") {
        j--;
    } else {
        j++;
    }

    return j;

}

// Shows where the character is and what he has found:

void movement (int foesQuantity, int map) {

    int foeNumber;
    std::string mapMessage;

    std::cout << "You are in " << mapPlace(map) << ", and ";
    foeNumber = randomize (foesQuantity);
    mapMessage = territoryMessage (foeNumber, map);
    std::cout << mapMessage << std::endl << std::endl;

}

