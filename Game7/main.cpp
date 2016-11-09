#include <iostream>

#include "map.h"
#include "general.h"
#include "movement.h"

int main() {

    int territoriesQuantity, height, width, i, j, n, m, movement, x, y;
    bool verticalMovement, horizontalMovement, positionFound = false;
    std::string direction, checkDirectionChange;

    // Assigns the map's limits:

    std::cout << "Assign the map's height: ";
    height = readIntPositiveNumber();
    std::cout << "Assign the map's width: ";
    width = readIntPositiveNumber();

    int map[height][width];

    territoriesQuantity = 4;

    // Creates the map's array:

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            map[i][j] = randomize(territoriesQuantity);
        }
    }

    // Shows the map's array:

    std::cout << "\nMap's array:\n";
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Alocates the character's inicial position:

    int charPosition;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
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
        std::cout << "and you are in " << mapPlace(map[i][j]) << std::endl;

        do {

            x = i;
            y = j;

            verticalMovement = false;
            horizontalMovement = false;

            // Prompt the direction:

            direction = checkDirection();
            std::cout << "The character's direction is: " << direction << std::endl << std::endl;

            // Moves the character:

            if (direction == "up" || direction == "down") {
                i = movingVertically(direction, i, j);
                verticalMovement = true;
            } else {
                j = movingHorizontally(direction, i, j);
            }

            if (map[i][j] == 0) {
                std::cout << "You don't know how to swim, you can't go to a lake!";
                if (verticalMovement) {
                    i = x;
                }
                else {
                    j = y;
                }

            }
            if (map[i][j] == 1) {
                std::cout << "You do not know how to climb mountains., you can't go to the hills!";
                if (verticalMovement) {
                    i = x;
                }
                else {
                    j = y;
                }
            }

        } while (i == x && j == y);

    }

}