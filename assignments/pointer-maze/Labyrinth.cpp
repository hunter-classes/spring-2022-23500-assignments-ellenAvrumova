#include "Labyrinth.h"

std::vector<bool> collectItems(Item i, std::vector<bool> items) {
    //the first, second, and third values of items holds the boolean values for
    //foundSpellbook, foundPotion, and foundWand respectively
    if(i == Item::SPELLBOOK) { items[0] = true; }
    if(i == Item::POTION) { items[1] = true; }
    if(i == Item::WAND) { items[2] = true; }
    return items;
}

bool foundAllItems(std::vector<bool> i) {
    return i[0] && i[1] && i[2];
}

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    std::vector<bool> items(3, false);
    
    for(int i = 0; i < moves.length(); i++) {
        items = collectItems(start->whatsHere, items); //updates items with new bool values

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
        items = collectItems(start->whatsHere, items);

        if(foundAllItems(items)) {
            return true;
        }
    }
    return foundAllItems(items);
}
