#include <iostream>
#include <stdlib.h>

#include "map.h"

// Creates the map's array:

int creatingMapArray () {

    return rand() % 4;

}

// Creates the map's places, and shows it.

int creatingMapPlaces (int i, int j, int map) {

    std::string Terreno;

    switch (map) {
        case 0:
            Terreno = "Lake";
            break;
        case 1:
            Terreno = "Hills";
            break;
        case 2:
            Terreno = "Florest";
            break;
        case 3:
            Terreno = "Open field";
            break;
        default:
            Terreno = "Road";
            break;
    }

    std::cout << Terreno << ",  ";

}