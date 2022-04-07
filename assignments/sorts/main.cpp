#include <iostream>
#include "sorts.h"
#include "mode.h"

extern char *optarg;

int main(int argc, char *argv[]) {
    int size = 20;
    int max_val = 100;

    char algorithm = 's' ; //default to selection sort
    bool print = false; // do we print before and after sorting?
    char c;

    while ((c = getopt(argc, argv, "phs:m:a:")) != -1) { 
        switch (c) {
        case 'h' :
	        print_help(argv[0]);
	        exit(0);
	        break;
        case 'p' :
	        print = true;
	        break;
        case 's' :
	        size = std::stoi(optarg);
	        break;
        case 'm' :
	        max_val = std::stoi(optarg);
	        break;
        case 'a':
	        algorithm = optarg[0]; // or *optarg
        }
    }

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

   if(!print) {
       std::cout << "Printing is turned off." << std::endl;
   }
    srand(time(nullptr));
    std::vector<int> a(size);
    for(int i = 0; i < size; i++) {
        a[i] = rand()%max_val;
    }
    std::cout << "Unsorted vector: ";
    if (print) {
        print_vector(a);
    }

    std::cout << "Starting the sort!\n";
    struct timeval tp;
    
    gettimeofday(&tp,NULL);
    long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    if (algorithm == 's'){
        a = ssort(a);
    }
    else if (algorithm == 'm'){
        a = msort(a);
    }
    else if (algorithm == 'q'){
        a = qsort(a);
    }
    else if(algorithm == 'Q') {
        qsort2(a, 0, a.size()-1);
    }

    // std::cout << "Unsorted vector: ";
    // print_vector(a);
    // std::cout << "Merge sorted vector: ";
    // print_vector(msort(a));

    // std::cout << "Find the largest value: " << largest(a) << std::endl;
    // std::cout << "Find the mode: " << mode(a) << std::endl; //if there are 2 modes, it will return the last one
    // std::cout << "Find the mode2: " << mode2(a) << std::endl; //if there are 2 modes, it will return the first one
    // std::cout << "Count the mode: " << count(a,mode(a)) << std::endl;

    gettimeofday(&tp,NULL);
    long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

    long elapsed = current_time - start_time;

    std::cout << "Sorted vector: ";
    if (print) {
        print_vector(a);
    }

    std::cout << "Algorithm: " << algorithm << "\n";
    std::cout << "Time: " << elapsed << " ms" << "\n";

    return 0;
}