#include <iostream>

#include "map.h"
#include "general.h"
#include "movement.h"

int main() {

    int territoriesQuantity, height, width, i, j;
    bool positionFound = false;
    std::string direction;

    // Assigns the map's limits:

    std::cout << "Assign the map's height: ";
    height = readIntPositiveNumber();
    std::cout << "Assign the map's width: ";
    width = readIntPositiveNumber();

    int map[height][width];

    territoriesQuantity = 4;

    // Creates the map's array:

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            map[i][j] = randomize(territoriesQuantity);
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

    // Alocates the character's inicial position:

    int charPosition;

    for (i=0; i < height; i++) {
        for (j=0; j < width; j++) {
            if (map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4) {
                charPosition = map[i][j];
                positionFound = true;
                std::cout << "Character's position at the array: " << i << "  " << j << std::endl;
                j = width;
                i = height;
            }
        }
    }
    std::cout << "Character's terrain: " << charPosition << "\nType of terrain: " << mapPlace(charPosition);

    // Prompt the direction:

    direction = checkDirection();
    std::cout << "The character's direction: " << direction;

    // Moves the character:

    charPosition = charPosition (direction);
    std::cout << "Char's position: " << charPosition;

}