#include <iostream>
#include <stdlib.h>

#include "map.h"

int main() {

    int height, width, map;

    std::cout << "Assign the map's height: ";
    std::cin >> height;
    std::cout << "Assign the map's width: ";
    std::cin >> width;

    std::cout << "\nMap's array:";
    map = creatingMapArray (height, width);
    std::cout << "\nMap's places:";
    map = creatingMapPlaces (height, width);

}