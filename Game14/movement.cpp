#include <iostream>

#include "movement.h"
#include "foes.h"
#include "map.h"

// Moves the character vertically:

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

