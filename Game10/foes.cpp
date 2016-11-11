#include <iostream>

#include "foes.h"

// Shows the map's message:

std::string territoryMessage (int foeNumber, int territory) {

    std::string message, empty;
    empty = "there is no one there";

    switch (territory) {

        case 3:
            switch (foeNumber) {
                case 1:
                    message = empty;
                    break;
                case 2:
                    message = "you see a giant";
                    break;
                case 3:
                    message = "you came into an ambush";
                    break;
                case 4:
                    message = "there are sleepy monkeys in the trees around you";
                    break;
            }

        case 4:
            switch (foeNumber) {
                case 1:
                    message = empty;
                    break;
                case 2:
                    message = "you see a troll";
                    break;
                case 3:
                    message = "you see a group of people";
                    break;
                case 4:
                    message = "there are wild bulls all around the field";
                    break;
            }

        case 5:
            switch (foeNumber) {
                case 1:
                    message = empty;
                    break;
                case 2:
                    message = "you see an orc";
                    break;
                case 3:
                    message = "you see a wagon coming at your direction";
                    break;
                case 4:
                    message = "there are sheep blocking the road";
                    break;
            }
    }

    return message;

}

