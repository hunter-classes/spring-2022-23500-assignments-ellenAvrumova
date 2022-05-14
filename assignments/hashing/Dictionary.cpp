#include <iostream>
#include <string>
#include "Dictionary.h"

Dictionary::Dictionary() {
    for(int i = 0; i < 10; i++) {
        arr[i] = new List();
    }
}

Dictionary::~Dictionary() {
    for(int i = 0; i < 10; i++) {
        arr[i]->~List();
    }
}

int Dictionary::hash(std::string name) {
    int sum = 0;
    for(int i = 0; i < name.length(); i++) {
        sum += int(name[i]);
    }
    return sum % 10;
}

void Dictionary::insert(Person *p) {
    int index = hash(p->get_name());
    arr[index]->insert(p);
}

Person* Dictionary::retrieve(Person *p) {
    int index = hash(p->get_name());
    if(arr[index] == nullptr) {
        return nullptr;
    }
    return arr[index]->search(p);
}

std::string Dictionary::getAll() {
    std::string all = "";
    for(int i = 0; i < 10; i++) {
        if(arr[i]->toString() != "nullptr") {
            all += arr[i]->toString();
            all += " | ";
        }
    }
    return all;
}

