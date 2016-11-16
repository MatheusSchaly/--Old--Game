#include <iostream>
#include <stdlib.h>

#include "map.h"

// Creates the map's array:

int randomize (int n) {

    return rand() % n+1;

}

// Show's the map's place:

std::string mapPlace (int n) {

    std::string terrain;

    switch (n) {
        case 0:
            terrain = "the sea";
            break;
        case 1:
            terrain = "lake";
            break;
        case 2:
            terrain = "hills";
            break;
        case 3:
            terrain = "a forest";
            break;
        case 4:
            terrain = "a open field";
            break;
        default:
            terrain = "a road";
            break;
    }

    return terrain;

}

