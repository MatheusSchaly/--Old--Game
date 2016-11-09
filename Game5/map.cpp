#include <iostream>
#include <stdlib.h>

#include "map.h"

// Creates the map's array:

int randomize (int n) {

    return rand() % n;

}

// Show's the map's place:

std::string mapPlace (int n) {

    std::string terrain;

    switch (n) {
        case 0:
            terrain = "Lake";
            break;
        case 1:
            terrain = "Hills";
            break;
        case 2:
            terrain = "Florest";
            break;
        case 3:
            terrain = "Open field";
            break;
        default:
            terrain = "Road";
            break;
    }

    return terrain;

}