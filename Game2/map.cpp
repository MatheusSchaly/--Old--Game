#include <iostream>
#include <stdlib.h>

#include "map.h"

int creatingMapArray (int height, int width) {

    int i, j, map[height][width], iRand;

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            iRand = rand() % 3;
            map[i][j] = iRand;
        }
    }

    std::cout << std::endl;

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    return map[i][j];
}

int creatingMapPlaces (int height, int width) {

    int i, j, map[height][width];

    std::cout << std::endl;

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    return map[height][width];
}