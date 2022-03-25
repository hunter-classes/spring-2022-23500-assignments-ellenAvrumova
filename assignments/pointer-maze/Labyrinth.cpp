#include "Labyrinth.h"

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    bool foundSpellbook = false;
    bool foundPotion = false;
    bool foundWand = false;

    for(int i = 0; i < moves.length(); i++) {
        if(start->whatsHere == Item::SPELLBOOK) {
            foundSpellbook = true;
        }
        if(start->whatsHere == Item::POTION) {
            foundPotion = true;
        }
        if(start->whatsHere == Item::WAND) {
            foundWand = true;
        }

        if(moves.at(i) == 'N') {
            if(start->north == nullptr) {
                return false;
            }
            start = start->north;
        }
        if(moves.at(i) == 'S') {
            if(start->south == nullptr) {
                return false;
            }
            start = start->south;
        }
        if(moves.at(i) == 'E') {
            if(start->east == nullptr) {
                return false;
            }
            start = start->east;
        }
        if(moves.at(i) == 'W') {
            if(start->west == nullptr) {
                return false;
            }
            start = start->west;
        }

        if(start->whatsHere == Item::SPELLBOOK) {
            foundSpellbook = true;
        }
        if(start->whatsHere == Item::POTION) {
            foundPotion = true;
        }
        if(start->whatsHere == Item::WAND) {
            foundWand = true;
        }

        if(foundSpellbook && foundPotion && foundWand) {
            return true;
        }
    }
    if(foundSpellbook && foundPotion && foundWand) {
        return true;
    }
    return false;
}
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
    // (void) start;
    // (void) moves;
    // return false;