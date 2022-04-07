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
    while(l < left.size() && r < right.size()) {
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
        merged.push_back(right[r]);
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
    
    merged = merge(msort(left), msort(right));

    return merged;
}

std::vector<int> qsort(std::vector<int> list) {
    int i,j;
    // base case
    if (list.size() <= 1){
        return list;
    }

    // select a pivot value.
    // for now, just pick list[0]
    int pivot = list[0];
  
    // make 2 new vectors
    std::vector<int> lower,higher;

    // copy all the values < pivot value to lower
    // copy all the values >= pivot value to higher;
    for (i = 1; i < list.size(); i++){
        if (list[i] < pivot){
            lower.push_back(list[i]);
        }
        else {
        higher.push_back(list[i]);
        }
    }
  
    lower = qsort(lower);
    higher = qsort(higher);

    // copy everything back into list
    for (i = 0; i < lower.size(); i++){
        list[i]=lower[i];
    }

    list[i] = pivot;
    i++;

    for (j = 0; j < higher.size(); j++){
        list[i] = higher[j];
        i++;
    }
  
    // return the sorted list
    return list; 
}

void qsort2(std::vector<int> &list, int low, int high) {
    if(low < high) {
        int pivotIndex = low + (high - low) / 2;
        int pivotValue = list[pivotIndex];
        int i = low, j = high;
        int temp;
        while(i <= j) {
            while(list[i] < pivotValue) {
                i++;
            }
            while(list[j] > pivotValue) {
                j--;
            }
            if(i <= j) {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                i++;
                j--;
            }
        }
        int partition = i;

        qsort2(list, low, partition - 1);
        qsort2(list, partition, high);
    }
}

void print_help(char *command_name) {
    std::cout << "Usage: "<< command_name;
    std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
    std::cout << " -m MAX_ELEMENT_SIZE\n";
    std::cout << " -s DATA_SET_SIZE\n";
    std::cout << " -a[s|m|q|Q]: s - selection, m - merge, q - quick, Q - quick2\n";
}