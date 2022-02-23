#include <iostream>
#include "knights.h"

int main() {
    std::string chess[9];
    int lines = load_board("chessboard.dat", chess);
    //print_board(chess,lines);
    
    bool solved = false;
    solve(chess, lines, 2, 2, solved);
    std::cout << "Done!" << std::endl;

    print_result();
    return 0;
}