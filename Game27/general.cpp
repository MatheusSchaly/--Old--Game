#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <vector>

#include "general.h"

// Checks words:

std::string checkWords (int wordQuantity, std::vector <std::string> word) {

    std::vector <std::string> lowercaseWord;
    std::string wordChecked;
    int i;
    bool validWord;

    validWord = false;
    lowercaseWord = word;

    do {
        for (i = 0; i < wordQuantity; i++) {
            std::cout << word[i] << " / ";
        }
        std::cout << ": ";
        std::cin >> wordChecked;
        std::transform (wordChecked.begin(), wordChecked.end(), wordChecked.begin(), ::tolower);

        for (i = 0; i < wordQuantity; i++) {
            std::transform (lowercaseWord[i].begin(), lowercaseWord[i].end(), lowercaseWord[i].begin(), ::tolower);
        }

        for (i = 0; i < wordQuantity; i++) {
            if (wordChecked == lowercaseWord[i]) {
                validWord = true;
            }
        }
    } while (!validWord);

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

// Validates a number between limits:

int readIntIntervalNumber (int lowerLimit, int upperLimit) {

    int n;

    do {
        std::cin >> n;
        if (n < lowerLimit || n > upperLimit) {
            std::cout << "The number has to be between " << lowerLimit << " and " << upperLimit;
        }
    } while (n < lowerLimit || n > upperLimit);

    return n;

}

// Randomizes a number:

int randomizeNumber (int n) {

    return rand() % n + 1;

}

// Randomizes an vector with probabilities:

int randomizeNumberWithProbability (int nQuantity, std::vector <int> probability) {

    int val, i, randomizedNumber;

    val = rand() % 100;
    randomizedNumber = 1;

    for (i = 1; i < nQuantity; i++) {
        probability [i] += probability [i - 1];
    }

    for (i =1; i < nQuantity; i++) {
        if (val < probability [i] && val >= probability [i - 1]) {
            randomizedNumber = i + 1;
            i = nQuantity;
        }
    }

    return randomizedNumber;

}

// Randomizes an vector of strings with probabilities:

std::string randomizeWordsWithProbability (int nQuantity, std::vector <int> probability, std::vector <std::string> words) {

    std::string randomizedWord;
    int randomizedNumber, i;

    randomizedNumber = randomizeNumberWithProbability (nQuantity, probability);

    for (i = 0; i < nQuantity; i++) {
        if (randomizedNumber == i + 1) {
            randomizedWord = words[i];
        }
    }

    return randomizedWord;

}