#include <iostream>
#include <climits>
#include "mode.h"

int count(std::vector<int> v, int value) {
    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == value) {
            count++;
        }
    }
    return count;
}

int largest(std::vector<int> v) {
    int max = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int mode(std::vector<int> v) {
    int mode = 0;
    int temp = 0;

    for(int i = 0; i < v.size(); i++) {
        if(count(v, v[i]) > temp) {
            temp = count(v,v[i]);
            mode = v[i];
        }
    }
    return mode;
}