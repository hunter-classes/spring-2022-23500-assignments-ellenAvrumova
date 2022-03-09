#include <iostream>
#include "sorts.h"
#include "mode.h"

int main() {
    int size = 20;
    int max_val = 100;

    srand(time(nullptr));

    std::vector<int> left{1,2,5,6,10,15};
    std::vector<int> right{3,7,8,12,16,19,20};

    std::cout << "Left Vector: ";
    print_vector(left);
    std::cout << "Right Vector: ";
    print_vector(right);
    std::vector<int>m = merge(left,right);
    std::cout << "Left and Right merge sorted: ";
    print_vector(m);

    std::vector<int> b(size);
    for(int i = 0; i < size; i++) {
        b[i] = rand()%max_val;
    }

    std::cout << "Unsorted vector: ";
    print_vector(b);
    std::cout << "Merge sorted vector: ";
    print_vector(msort(b));

    std::cout << "Count the second value: " << count(msort(b), msort(b)[1]) << std::endl; //sorted so it's easier to handcount
    std::cout << "Find the largest value: " << largest(b) << std::endl;
    std::vector<int> c{1,2,3,4,4,5,5,6,7,8,8,8,9};
    std::cout << "Find the mode: " << mode(c) << std::endl; //8




    return 0;
}