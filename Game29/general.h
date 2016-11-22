#include <vector>

#ifndef GENERAL_H
#define GENERAL_H

int readIntPositiveNumber (); // Validates a positive integer number.
int readIntIntervalNumber (int upperLimit, int lowerLimit); // Validates a number between limits.
// std::string checkFourWords (std::string word1, std::string word2, std::string word3, std::string word4); // Validates four words.
std::string checkTwoWords (std::string word1, std::string word2); // Validates two words.
int randomizeNumber (int n); // Randomizes a number.
std::string randomizeUpToFiveWords (std::string word1, std::string word2, std::string word3, std::string word4, std::string word5); // Randomizes up to five words.
int randomizeNumberWithProbability (int nQuantity, std::vector <int> probability); // Randomizes an vector with probabilities.
std::string checkWords (int wordQuantity, std::vector <std::string> word); // Checks words.

#endif
