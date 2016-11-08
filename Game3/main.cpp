#include <iostream>

#include "map.h"

int main() {

    int height, width, i, j;

    // Assigns the map's limits:

    std::cout << "Assign the map's height: ";
    std::cin >> height;
    std::cout << "Assign the map's width: ";
    std::cin >> width;

    int map[height][width];

    // Creates the map's array:

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            map[i][j] = creatingMapArray();
        }
    }

    // Shows the map's array:

    std::cout << "\nMap's array:\n";
    for (i=0; i < height; i++) {
        for (j = 0; j < width; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Creates the map's places, and shows it:
/*
    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            map[i][j] = creatingMapPlaces (i, j, map[i][j]);
        }
    }
*/
    // Character inicial position:

    int charPosition;

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            if (map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4) {
                charPosition = map[0][0];
            }
        }
    }
    std::cout << charPosition;

}