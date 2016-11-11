#include <iostream>

#include "map.h"
#include "general.h"
#include "movement.h"
#include "foes.h"

int main() {

    int territoriesQuantity, line, col, i, j, n, m, movement, x, y, life, foesQuantity, foeNumber;
    bool verticalMovement, horizontalMovement, positionFound = false;
    std::string direction, checkDirectionChange, mapMessage;

    // Assigns the map's limits:

    std::cout << "Assign the map's line: ";
    line = readIntPositiveNumber();
    std::cout << "Assign the map's col: ";
    col = readIntPositiveNumber();

    line += 2;
    col += 2;

    int map[line][col];

    territoriesQuantity = 5;
    foesQuantity = 4;

    // Creates the map's array:

    // Creates all left columns:
    j = 0;
    for (i = 0; i < line; i++) {
        map[i][j] = 0;
    }

    // Creates all right columns:
    for (i = 0; i < line; i++) {
        map[i][col - 1] = 0;
    }

    // Creates middle top part:
    i = 0;
    for (j = 1; j < col - 1; j++) {
        map[i][j] = 0;
    }

    // Creates middle bottom part:

    for (i = 0; i < col - 1; i++) {
        map[line - 1][i] = 0;
    }

    // Randomize the map's center:
    for (i = 1; i < line - 1; i++) {
        for (j = 1; j < col - 1; j++) {
            map[i][j] = randomize (territoriesQuantity);
        }
    }

    // Shows the map's array:
    std::cout << "\nMap's array:\n";
    for (i = 0; i < line; i++) {
        for (j = 0; j < col; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Alocates the character's initial position:

    int charPosition;

    for (i = 1; i < line; i++) {
        for (j = 1; j < col; j++) {
            if (map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4) { ;
                n = i;
                m = j;
                positionFound = true;
                j = col;
                i = line;
            }
        }
    }
    i = n;
    j = m;

    // Moves the character:

    life = 0;

    while (life < 20) {

        life++;
        std::cout << "Character's position at the array: " << i << "  " << j << std::endl;
        std::cout << "Your position on the map is: " << map[i][j] << std::endl;
        std::cout << "and you are in " << mapPlace (map[i][j]) << std::endl;

        do {

            x = i;
            y = j;

            verticalMovement = false;
            horizontalMovement = false;

            // Prompt the direction:

            direction = checkDirection();
            std::cout << "The character's direction is: " << direction << "\n\n";

            // Moves the character:

            if (direction == "up" || direction == "down") {
                i = movingVertically (direction, i);
                verticalMovement = true;
            } else {
                j = movingHorizontally (direction, j);
            }

            if (map[i][j] == 0) {
                std::cout << "You don't know how to swim, you can't go to the sea!";
                if (verticalMovement) {
                    i = x;
                } else {
                    j = y;
                }
            }

            if (map[i][j] == 1) {
                std::cout << "You don't know how to swim, you can't go to a lake!";
                if (verticalMovement) {
                    i = x;
                } else {
                    j = y;
                }

            }

            if (map[i][j] == 2) {
                std::cout << "You don't know how to climb mountains., you can't go to the hills!";
                if (verticalMovement) {
                    i = x;
                } else {
                    j = y;
                }
            }

            if (map[i][j] == 3) {
                std::cout << "You are in a forest, and ";
                foeNumber = randomize (foesQuantity);
                mapMessage = territoryMessage (foeNumber, 3);
                std::cout << mapMessage << std::endl << std::endl;
            }

            if (map[i][j] == 4) {
                std::cout << "You are in a an open field, and ";
                foeNumber = randomize(foesQuantity);
                mapMessage = territoryMessage(foeNumber, 4);
                std::cout << mapMessage << std::endl << std::endl;
            }

            if (map[i][j] == 5) {
                std::cout << "You are in a an open field, and ";
                foeNumber = randomize(foesQuantity);
                mapMessage = territoryMessage(foeNumber, 5);
                std::cout << mapMessage << std::endl << std::endl;
            }

        } while (i == x && j == y);
    }
}