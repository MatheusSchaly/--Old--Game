#ifndef FOES_H
#define FOES_H

void foeInteraction (int foeNumber, int territory, int &life); // Creates the foes' interactions:
std::string chooseFightOrFlee (); // Choosing between fight or flee.
void giantCombat (int &life, int &foeLife); // Calculates the damages giant's damage and character's damage.
void receivesDamage (int foeDamage, int &life); // Informs the damage done by the foe, and reduces the character's life.
void dealsDamage (int characterDamage, int &giantLife); // Informs the damage done by you, and reduces the foes' life.

#endif
