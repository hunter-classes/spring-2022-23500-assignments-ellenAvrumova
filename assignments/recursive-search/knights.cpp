#include <iostream>
#include "knights.h"

char me = 'N';
char offBoard = ' ';
char visited = '*';
int counter = 0;
char wall = ':';

int load_board(std::string filename, std::string *chess) {
    std::ifstream infile(filename);
    int i = 0;
    while(std::getline(infile,chess[i])) {
        i++;
    }
    return i;
}

void print_board(std::string chess[], int lines) {
    //std::cout << "[0;0H\n";
    for(int i = 0; i < lines; i++) {
        std::cout << chess[i] << std::endl;
    }
    std::cout << std::endl;
}

void solve(std::string chess[], int lines, int row, int col, bool &solved) {
    if(counter == 25) {
        print_board(chess, lines);
        solved = true;
        return;
    }

    if(chess[row][col] == offBoard || isdigit(chess[row][col]) ) {
        return;
    }

    usleep(100000);
    print_board(chess,lines);

    counter++;
    if(counter > 9 && !solved) {
        chess[row][col-1] = ('0' + (counter/10));
        chess[row][col] = ('0' + (counter%10));
    }
    else {
        chess[row][col] = ('0' + counter);
    }
    
    if (!(solved)) solve(chess, lines, row+2, col+3, solved);
    if (!(solved)) solve(chess, lines, row+2, col-3, solved);
    if (!(solved)) solve(chess, lines, row-2, col+3, solved);
    if (!(solved)) solve(chess, lines, row-2, col-3, solved);
    if (!(solved)) solve(chess, lines, row+1, col+6, solved);
    if (!(solved)) solve(chess, lines, row+1, col-6, solved);
    if (!(solved)) solve(chess, lines, row-1, col+6, solved);
    if (!(solved)) solve(chess, lines, row-1, col-6, solved);
}