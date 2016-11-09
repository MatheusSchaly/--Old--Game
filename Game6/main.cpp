#include <iostream>

#include "map.h"
#include "general.h"
#include "movement.h"

int main() {

    int territoriesQuantity, height, width, i, j, n, m, movement;
    bool positionFound = false;
    std::string direction, checkDirectionChange;

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
            if (map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4) { ;
                n = i;
                m = j;
                positionFound = true;
                j = width;
                i = height;
            }
        }
    }
    i = n;
    j = m;

    // Moves the character:

    n = 0;

    while (n < 2) {
        n++;
        std::cout << "Character's position at the array: " << i << "  " << j << std::endl;
        std::cout << "Your position on the map is: " << map[i][j] << std::endl;
        std::cout << "and you are in " << mapPlace (map[i][j]) << std::endl;

        // Prompt the direction:

        direction = checkDirection();
        std::cout << "The character's direction: " << direction << std::endl <<std::endl;

        // Moves the character:

        if (direction == "up") {
            i--;
        }
        else {
            if (direction == "down") {
                i++;
            } else {
                if (direction == "left") {
                    j--;
                } else {
                    j++;
                }
            }
        }

    }

}