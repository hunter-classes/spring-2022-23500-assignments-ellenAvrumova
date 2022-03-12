#include <iostream>
#include "sorts.h"
#include "mode.h"

int main() {
    int size = 20;
    int max_val = 100;

    srand(time(nullptr));

    /**
    std::vector<int> left{1,2,5,6,10,15};
    std::vector<int> right{3,7,8,12,16,19,20};

    std::cout << "Left Vector: ";
    print_vector(left);
    std::cout << "Right Vector: ";
    print_vector(right);
    std::vector<int>m = merge(left,right);
    std::cout << "Left and Right merge sorted: ";
    print_vector(m);
    */

    std::vector<int> b(size);
    for(int i = 0; i < size; i++) {
        b[i] = rand()%max_val;
    }

    std::cout << "Unsorted vector: ";
    print_vector(b);
    std::cout << "Merge sorted vector: ";
    print_vector(msort(b));

    std::cout << "Find the largest value: " << largest(b) << std::endl;
    std::cout << "Find the mode: " << mode(b) << std::endl;
    std::cout << "Count the mode: " << count(b,mode(b)) << std::endl;


    return 0;
}