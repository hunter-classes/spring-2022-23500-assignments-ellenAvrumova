#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool foundSpellbook = false;
    bool foundPotion = false;
    bool foundWound = false;

    for(int i = 0; i < moves.length(); i++) {
        if(moves.at(i) == 'N') {
            if(start->north == nullptr) {
                return false;
            }
        }
        if(moves.at(i) == 'S') {
            if(start->south == nullptr) {
                return false;
            }
        }
        if(moves.at(i) == 'E') {
            if(start->east == nullptr) {
                return false;
            }
        }
        if(moves.at(i) == 'W') {
            if(start->west == nullptr) {
                return false;
            }
        }
        if(start->whatsHere == Item::SPELLBOOK) {
            foundSpellbook = true;
        }
        if(start->whatsHere == Item::POTION) {
            foundSpellbook = true;
        }
        if(start->whatsHere == Item::WAND) {
            foundSpellbook = true;
        }
    }

    if(foundSpellbook && foundPotion && foundWound) {
            return true;
    }
    return false;
}
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
    // (void) start;
    // (void) moves;
    // return false;