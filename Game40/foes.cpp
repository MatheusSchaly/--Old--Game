#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#include "foes.h"
#include "general.h"

// Creates the foes' interactions:

void foeInteraction (int foeNumber, int territory, int &life) {

    std::vector <std::string> words2, words3, words4;
    std::vector <int> prob1;
    std::string empty, fightOrFlee, giantAction, talkOrRun;
    int giantLife;

    giantLife = 100;
    empty = "there is no one there.";

    switch (territory) {

        case 3:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see a furious giant, choose: ";
                    words2 = {"fight", "flee"};
                    fightOrFlee = checkWords (2, words2);
                    std::cout << std::endl;
                    while (giantLife > 0 && life > 0 && fightOrFlee == "fight") {
                        if (fightOrFlee == "fight") {
                            words3 = {"He tries to grab you, ", "He tries to seize you, "};
                            prob1 = {50, 50};
                            giantAction = randomizeWordsWithProbability (2, prob1, words3);
                        }
                        if (giantAction == "He tries to grab you, " || giantAction == "He tries to seize you, ") {
                            std::cout << giantAction;
                            giantCombat (life, giantLife);
                        }
                        if (giantLife > 0 && life > 0) {
                            fightOrFlee = checkWords (2, words2);
                            std::cout << std::endl;
                        }
                    }
                    if (fightOrFlee == "fight") {
                        if (life > 0) {
                            std::cout << "You've killed the beast!\n";
                        }
                        else {
                            if (giantLife <= 0) {
                                std::cout << "You've killed the beast, but died while doing so!";
                            }
                            else {
                                std::cout << "You've died trying to kill the beast!";
                            }
                        }
                    }
                    break;
                case 3:
                    std::cout << "you came into an ambush, with approximately 20 men, choose: ";
                    words4 = {"talk", "run"};
                    talkOrRun = checkWords (2, words4);
                    std::cout << std::endl;
                    if (talkOrRun == "run") {
                        ambushCombat (life);
                        if (life < 1) {
                            std::cout << "You've died trying to scape!";
                        }
                    }
                    else {
                        ambushTalk (life);
                    }
                    break;
                default:
                    std::cout << "there are sleepy monkeys in the trees around you, choose: ";
                    break;
            }
            break;

        case 4:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see a troll, choose: ";
                    break;
                case 3:
                    std::cout << "you see a group of people, choose: ";
                    break;
                default:
                    std::cout << "there are wild bulls all around the field, choose: ";
                    break;
            }
            break;

        default:
            switch (foeNumber) {
                case 1:
                    std::cout << empty;
                    break;
                case 2:
                    std::cout << "you see an orc, choose: ";
                    break;
                case 3:
                    std::cout << "you see a wagon coming at your direction, choose: ";
                    break;
                default:
                    std::cout << "there are sheep blocking the road, choose: ";
                    break;
            }
            break;
    }

}

// Ambush talk:

void ambushTalk (int &life) {

    std::vector <std::string> words5;
    std::string answer;
    int i;


    std::cout << "I'm just a pious priest going to the church / Do you dare to point your weapons to a friend? Choose: ";
    words5 = {"priest", "friend"};
    answer = checkWords (2, words5);

    if (answer == "priest") {
        std::cout << "Unknown man: \"If you are really a priest, you know how to read and write. So spell the word used to address the king, you have three chances:\" ";
        std::cin >> answer;
        std::transform (answer.begin(), answer.end(), answer.begin(), ::tolower);
        i = 0;
        do {
            i++;
            if (answer != "lord") {
                if (i == 1) {
                    std::cout << "Unknown man: \"That's not right \"priest\", try it again:\" ";
                    std::cin >> answer;
                    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                }
                if (i == 2) {
                    std::cout << "Unknown man: \"I'm smelling a lie:\" ";
                    std::cin >> answer;
                    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                }
                if (i == 3) {
                    std::cout << "Unknown man: \"And liars must die!\"";
                }
            }
        } while (i < 4 && answer != "lord");
        if (answer != "lord") {
            std::cout << "\nYou've died in the ambush.";
            life = 0;
        }
        else {
            std::cout << "Unknown man: \"Good job priest, you can follow you path safely.\"";
        }
    }
}

// Calculates the ambush's damage and character's damage:

void ambushCombat (int &life) {

    int foeDamage;

    foeDamage = randomizeNumber(10);

    if (foeDamage > 9) {
        std::cout << "You ran but you were pierced by an arrow in the chest.\n";
        foeDamage = round (life * 0.9);
        receivesDamage (foeDamage, life);
    }
    else {
        if (foeDamage > 7) {
            std::cout << "You ran but you were pierced by an arrow in your right leg.\n";
            foeDamage = round (life * 0.4);
            receivesDamage (foeDamage, life);
        }
        else {
            if (foeDamage > 4) {
                std::cout << "You ran but you were pierced by an arrow in your right arm.\n";
                foeDamage = round (life * 0.2);
                receivesDamage (foeDamage, life);
            }
            else {
                std::cout << "You escaped safely.\n";
                foeDamage = 0;
                receivesDamage (foeDamage, life);
            }
        }
    }
}

// Calculates the damages giant's damage and character's damage:

void giantCombat (int &life, int &foeLife) {

    int foeDamage, characterDamage;

        characterDamage = randomizeNumber(10);
        foeDamage = randomizeNumber (10);

        if (characterDamage > 9) {
            std::cout << "but while he is trying to do it, you strike him right in the face.\n";
            characterDamage *= 8;
            dealsDamage (characterDamage, foeLife);
        }
        else {
            if (characterDamage > 7) {
                std::cout << "but while he is trying to do it, you strike him right in the chest.\n";
                characterDamage *= 4;
                dealsDamage (characterDamage, foeLife);
            }
            else {
                if (characterDamage > 3) {
                    std::cout << "but while he is trying to do it, you strike him right in the leg.\n";
                    characterDamage *= 2;
                    dealsDamage (characterDamage, foeLife);
                }
                else {
                    std::cout << "you were not able to strike him.\n";
                    characterDamage = 0;
                    dealsDamage (characterDamage, foeLife);
                }
            }
        }

        if (foeDamage > 9) {
            std::cout << "Then, when he finally grabs you, he throws you eight meters away and you hit a sharp edge rock.\n";
            foeDamage *= 4;
            receivesDamage (foeDamage, life);
        }
        else {
            if (foeDamage > 7) {
                    std::cout << "Then, when he finally grabs you, he throws you six meters away and you hit a rotten tree.\n";
                    foeDamage *= 2;
                    receivesDamage (foeDamage, life);
            }
            else {
                if (foeDamage > 3) {
                    std::cout << "Then, when he finally grabs you, he throws you three meters away and you hit the ground.\n";
                    receivesDamage (foeDamage, life);
                }
                else {
                    std::cout << "And you successfully evades him.\n";
                    foeDamage = 0;
                    receivesDamage (foeDamage, life);
                }
            }
        }
}


// Informs the damage done by the foe, and reduces your life:

void receivesDamage (int foeDamage, int &life) {

    if (foeDamage > 0) {
        std::cout << "Receiving " << foeDamage << " of damage.\n";
        life -= foeDamage;
        std::cout << "Your current life is: " << life << "\n\n";
    }
    else {
        std::cout << "Don't receiving any damage.\n";
        std::cout << "Your current life is: " << life << "\n\n";
    }

}

// Informs the damage done by you, and reduces the foes' life:

void dealsDamage (int characterDamage, int &foesLife) {

    if (characterDamage > 0) {
        std::cout << "Dealing " << characterDamage << " of damage.\n";
        foesLife -= characterDamage;
        std::cout << "The foes current life is: " << foesLife << "\n\n";
    }
    else {
        std::cout << "Don't dealing any damage.\n";
        std::cout << "The foes current life is: " << foesLife << "\n\n";
    }

}