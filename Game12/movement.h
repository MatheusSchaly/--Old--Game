#ifndef MOVEMENT_H
#define MOVEMENT_H

std::string checkDirection (); // Checks character's direction.
int movingVertically (std::string direction, int i); // Moves the character vertically.
int movingHorizontally (std::string direction, int j); // Moves the character horizontally.
void movement (int foesQuantity, int map); // Shows where the character is and what he has found.

#endif
