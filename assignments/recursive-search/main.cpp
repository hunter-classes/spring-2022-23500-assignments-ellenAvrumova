#include <iostream>
#include "knights.h"

int main() {
    std::string chess[27];
    int lines;
    lines = load_board("chessboard.dat", chess);
    print_board(chess,lines);
    bool solved = false;
    //solve(chess, lines, 2, 2, solved);
    solve(chess, lines, 3, 6, solved);
    std::cout << "Done!" << std::endl;
    return 0;
}