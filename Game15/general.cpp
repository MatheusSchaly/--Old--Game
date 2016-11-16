#include <iostream>
#include <algorithm>

#include "general.h"

// Validates four words:

std::string checkFourWords (std::string word1, std::string word2, std::string word3, std::string word4) {

    std::string wordChecked;

    do {
        std::cout << word1 << " / " << word2 << " / " << word3 << " / " << word4 << ":";
        std::cin >> wordChecked;
        std::transform (wordChecked.begin(), wordChecked.end(), wordChecked.begin(), ::tolower);
    } while (wordChecked != word1 && wordChecked != word2 && wordChecked != word3 & wordChecked != word4);

    return wordChecked;

}

// Validates two words:

std::string checkTwoWords (std::string word1, std::string word2) {

    std::string wordChecked;

    do {
        std::cout << word1 << " / " << word2 << ":";
        std::cin >> wordChecked;
        std::transform (wordChecked.begin(), wordChecked.end(), wordChecked.begin(), ::tolower);
    } while (wordChecked != word1 && wordChecked != word2);

    return wordChecked;

}

// Validates a positive integer number:

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
