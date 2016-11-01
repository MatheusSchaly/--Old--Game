#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <stdio.h>

int main() {

    int map[9][9], i, j, iRand;

    for (i=0; i < 10; i++) {
        for (j=0; j < 10; j++) {
            iRand = rand() % 9;
            map [i][j] = iRand;
        }
    }

    std::cout << std::endl;

    for (i=0; i < 10; i++) {
        for (j=0; j < 10; j++) {
            std::cout << map[i][j] << "  ";
        }
        std::cout << std::endl;
    }

}