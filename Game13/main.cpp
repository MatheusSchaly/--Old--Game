#include <iostream>

#include "map.h"
#include "general.h"
#include "movement.h"
#include "foes.h"

int main() {

    int territoriesQuantity, line, col, i, j, n, m, movement, life, foesQuantity, foeNumber, charPosition;
    bool verticalMovement, horizontalMovement;
    std::string direction, checkDirectionChange, mapMessage;

    // Assigns the map's limits:

    std::cout << "Assign the map's line: ";
    line = readIntPositiveNumber();
    std::cout << "Assign the map's col: ";
    col = readIntPositiveNumber();

    line += 2;
    col += 2;

    int map[line][col];

    // Assigns the quantity of different territories and foes:

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

    for (i = 1; i < line; i++) {
        for (j = 1; j < col; j++) {
            if (map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) { ;
                n = i;
                m = j;
                j = col;
                i = line;
            }
        }
    }
    i = n;
    j = m;

    // Shows character's spawn:

    std::cout << "You've spawned in " << mapPlace(map[i][j]) << ".\n";

    // Moves the character:

    life = 0;

    while (life < 20) {

        life++;
        std::cout << "Character's position at the array: " << i << "  " << j << std::endl;

        do {

            n = i;
            m = j;

            verticalMovement = false;
            horizontalMovement = false;

            // Prompt the direction:

            std::cout << "\nWhich direction do you want to move? ";
            direction = checkFourWords ("up", "down", "left", "right");

            // Moves the character:

            if (direction == "up" || direction == "down") {
                i = movingVertically (direction, i);
                verticalMovement = true;
            } else {
                j = movingHorizontally (direction, j);
            }

            // Checks the territories' availability:

            if (map[i][j] == 0) {
                std::cout << "You don't know how to swim, you can't go to the sea!";
                if (verticalMovement) {
                    i = n;
                } else {
                    j = m;
                }
            }

            if (map[i][j] == 1) {
                std::cout << "You don't know how to swim, you can't go to a lake!";
                if (verticalMovement) {
                    i = n;
                } else {
                    j = m;
                }

            }

            if (map[i][j] == 2) {
                std::cout << "You don't know how to climb mountains, you can't go to the hills!";
                if (verticalMovement) {
                    i = n;
                } else {
                    j = m;
                }
            }

        } while (i == n && j == m);

        // Shows where the character is and what he has found:

        std::cout << "You are in " << mapPlace(map[i][j]) << ", and ";
        foeNumber = randomize (foesQuantity);
        mapMessage = territoryMessage (foeNumber, map[i][j]);
        std::cout << mapMessage << std::endl;

    }
}