#include <iostream>
#include "knights.h"

char me = 'N';
char offBoard = ' ';
char path = '#';
int counter = 0;
int result[5][5];

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

void print_result() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(j == 4) {
                std::cout << result[i][j];
            }
            else {
                std::cout << result[i][j] << ":";
            }
        }
        std::cout << std::endl;
    }
}

void solve(std::string chess[], int lines, int row, int col, bool &solved) {
    //check if puzzle is solved
    if(counter == 25) {
        // print_board(chess, lines);
        solved = true;
        return;
    }

    //base cases
    if(chess[row][col] == offBoard || chess[row][col] == me) {
        return;
    }

    chess[row][col] = me;
    //usleep(800);
    //print_board(chess,lines);
    counter++;
    result[row-2][col-2] = counter; //save location and counter in 2D array

    if (!(solved)) solve(chess, lines, row+2, col+1, solved);
    if (!(solved)) solve(chess, lines, row+2, col-1, solved);
    if (!(solved)) solve(chess, lines, row-2, col+1, solved);
    if (!(solved)) solve(chess, lines, row-2, col-1, solved);
    if (!(solved)) solve(chess, lines, row+1, col+2, solved);
    if (!(solved)) solve(chess, lines, row+1, col-2, solved);
    if (!(solved)) solve(chess, lines, row-1, col+2, solved);
    if (!(solved)) solve(chess, lines, row-1, col-2, solved);

    //backtrack after all directions have been checked and puzzle is not solved yet
    if(!solved) {
        chess[row][col] = path;
        counter--;
        result[row-2][col-2] = 0;
    }
}
