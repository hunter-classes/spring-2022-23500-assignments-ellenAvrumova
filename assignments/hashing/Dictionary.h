#pragma once
#include "List.h"

#define NOT_FOUND 1

class Dictionary {
    private:
        List* arr[10];
    public:
        Dictionary();
        ~Dictionary();
        void insert(Person *p);
        Person* retrieve(Person *p);
        std::string getAll();
        int hash(std::string name);
};