#include <iostream>

#include "foes.h"

// Shows the map's message:

std::string territoryMessage (int foeNumber, int territory) {

    std::string mapMessage, empty;
    empty = "there is no one there.";

    switch (territory) {

        case 3:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see a furies giant.";
                std::cout << "Choose fight or flee:";
                    break;
                case 3:
                    mapMessage = "you came into an ambush.";
                    break;
                case 4:
                    mapMessage = "there are sleepy monkeys in the trees around you.";
                    break;
            }

        case 4:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see a troll.";
                    break;
                case 3:
                    mapMessage = "you see a group of people.";
                    break;
                case 4:
                    mapMessage = "there are wild bulls all around the field.";
                    break;
            }

        case 5:
            switch (foeNumber) {
                case 1:
                    mapMessage = empty;
                    break;
                case 2:
                    mapMessage = "you see an orc.";
                    break;
                case 3:
                    mapMessage = "you see a wagon coming at your direction.";
                    break;
                case 4:
                    mapMessage = "there are sheep blocking the road.";
                    break;
            }
    }

    return mapMessage;

}

