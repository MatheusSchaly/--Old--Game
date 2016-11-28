#include <iostream>
#include <vector>
#include <stdio.h>
#include <limits.h>

#include "map.h"
#include "general.h"
#include "movement.h"
#include "foes.h"

// Colors:

#define RED "\033[31m"
#define RESET "\033[0m"
#define V 9

int minDistance (int dist[], bool sptSet[]) {

    int min, v;

    min = INT_MAX, min_index;

    for (v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v], min_index = v;
        }
    }

    return min_index;

}

int printSolution (int dist[], int n) {

    int i;

    std::cout << "Vertex   Distance from Source\n";
    for (i = 0; i < V; i++) {
        printf ("%d \t\t %d\n", i, dist[i]);
    }

}

void dijkstra (int graph[V][V], int src) {

    int dist[V], count, u;
    bool sptSet[V];


    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX, sptSet[i] = false;
    }

    dist[src] = 0;

    for (count = 0; count < V-1; count++) {

        u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist, V);

}

// driver program to test above function
int main()
{
    /* Let us create the example graph discussed above */
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

int main() {

    int territoriesQuantity, line, col, i, j, n, m, x, y, positionToReplace, movement, life, foesQuantity, foeNumber, charPosition, insurmountable, territoriesChangesQuantity, mapHelper;
    bool verticalMovement, horizontalMovement;
    std::string direction, checkDirectionChange, mapMessage;
    std::vector <int> prob1, prob2;
    std::vector <std::string> words1;

    insurmountable = 0;
    territoriesChangesQuantity = 0;

    int graph[V][V] =
                       {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra (graph, 0);

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

    // Randomizes the map's center:

   /*
    * do {
        for (i = 1; i < territoriesQuantity + 1; i++) {
            std::cout << "Assign the probability to generate " << mapPlace(i) << ": ";
            n = readIntIntervalNumber (0, 100);
            prob1.push_back (n);
        }
        if (prob1[0] + prob1[1] >= 100) {
            std::cout << "\nThe probability of the sum of lakes and hills must be lower than 100.\n\n";
            prob1.clear();
        }
        if (prob1[0] + prob1[1] + prob1[2] + prob1[3] + prob1[4] != 100) {
            std::cout << "\nThe sum of probabilities must be exactly 100.\n\n";
            prob1.clear();
        }
    } while ((prob1[0] + prob1[1] >= 100) || prob1[0] + prob1[1] + prob1[2] + prob1[3] + prob1[4] != 100);
 */

    n = 0;

    prob1 = {50, 40, 10, 0, 0};

    // Opens closed paths:

    for (i = 1; i < line - 1; i++) {
        for (j = 1; j < col - 1; j++) {
            map[i][j] = randomizeNumberWithProbability (territoriesQuantity, prob1);
        }
    }

    // Lee (or Dijkstra's) algorithm to be tried:

    for (i = 1; i < line - 1; i++) {
        for (j = 1; j < col - 1; j++) {
            Lee (0, i, j);
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

    std::cout << "You've spawned in " << mapPlace (map[i][j]) << ".\n";
    std::cout << "Character's position at the array: " << i << "  " << j << std::endl;

    // Moves the character:

    life = 100;

    while (life > 0) {

        do {

            n = i;
            m = j;

            verticalMovement = false;
            horizontalMovement = false;

            // Prompt the direction:

            words1 = {"up", "down", "left", "right"};
            std::cout << "\n\nWhich direction do you want to move? ";
            direction = checkWords (4, words1);

            // Moves the character:

            if (direction == "up" || direction == "down") {
                i = movingVertically (direction, i);
                verticalMovement = true;
            } else {
                j = movingHorizontally (direction, j);
            }

            // Checks the territories' availability:

                territoryAvailability (map[i][j], i, j, n, m, verticalMovement);

            // Shows the character's position at the array:

            std::cout << "\nCharacter's position at the array: " << i << "  " << j;

        } while (i == n && j == m);

        // Character's location:

        x  = i;
        y = j;

        std::cout << "\nThe X represents the character in the map:\n";
        for (x = 0; x < line; x++) {
            for (y = 0; y < col; y++) {
                if (x != i || y != j) {
                    std::cout << map[x][y] << "  ";
                }
                else {
                    std::cout << RED << "X" << RESET << "  ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        // Creates the foes' interactions:

        std::cout << "You are in " << mapPlace(map[i][j]) << ", and ";
        prob2 = {50, 10, 15, 25};
        foeNumber = randomizeNumberWithProbability (foesQuantity, prob2);
        foeInteraction (foeNumber, map[i][j], life);

        }

    std::cout << "\nGame over";

}