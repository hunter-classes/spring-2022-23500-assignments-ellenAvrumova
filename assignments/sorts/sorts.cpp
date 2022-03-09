#include <iostream>
#include "sorts.h"

void print_vector(std::vector<int> a) {
    for(auto i : a) {
        std::cout << i << " , ";
    }
    std::cout << "\n";
}

int find_min_index(std::vector<int> a, int start_index, int stop_index) {
    int min_index = start_index;
    for(int i = start_index; i < stop_index; i++) { //stop_index = length so we don't actually need it
        if(a[i] < a[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

std::vector<int> ssort(std::vector<int> a) {
    int min_index, j, temp;
    int length = a.size();
    //loop through the vector from 0 to end
    for(int i = 0; i < length; i++) {
        //find the smallest value from i to the end
        min_index = find_min_index(a,i,length);

        //swap it into the position i
        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }
    return a;
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> merged;

    int l = 0;
    int r = 0;
    while(l < right.size() && r < right.size()) {
        if(left[l] < right[r]) {
            merged.push_back(left[l]);
            l++;
        }
        else {
            merged.push_back(right[r]);
            r++;
        }
    }
    //add any extra elements in left
    while(l < left.size()) {
        merged.push_back(left[l]);
        l++;
    }
    //add any extra elements in right
    while(r < right.size()) {
        merged.push_back(right[l]);
        r++;
    }
    return merged;
}

std::vector<int> msort(std::vector<int> v) {
    std::vector<int> merged;

    if(v.size() < 2) {
        return v;
    }
    
    std::vector<int> left; 
    for(int i = 0; i < v.size() / 2; i++) { 
        left.push_back(v[i]);
    }
    std::vector<int> right; 
    for(int i = v.size() / 2; i < v.size(); i++) { 
        right.push_back(v[i]);
    }
    
    merged = merge(ssort(left), ssort(right));

    return merged;
}
