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
            terrain = "lake";
            break;
        case 1:
            terrain = "hills";
            break;
        case 2:
            terrain = "a florest";
            break;
        case 3:
            terrain = "a open field";
            break;
        default:
            terrain = "a road";
            break;
    }

    return terrain;

}