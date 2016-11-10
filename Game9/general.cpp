#include <iostream>

#include "general.h"

// Validate a positive integer number:

int readIntPositiveNumber () {

    int n;

    do {
        std::cin >> n;
        if (n < 1) {
            std::cout << "The number has to be positive:";
        }
    } while (n < 1);

    return n;

}

// Validate a number between limits:

int readIntIntervalNumber (int upperLimit, int lowerLimit) {

    int n;

    do {
        std::cin >> n;
        if (n < lowerLimit || n > upperLimit) {
            std::cout << "The number has to be between " << lowerLimit << " and " << upperLimit;
        }
    } while (n < lowerLimit || n > upperLimit);

}
