#include <fstream>
#include <string>
#include <unistd.h>

int load_board(std::string filename, std::string *chess);
void print_board(std::string chess[], int lines);
void solve(std::string chess[], int lines, int row, int col, bool &solved);
void print_result();