#pragma once
#include "Node.h"

#define NOT_FOUND 1

class List {
    private:
        Node *head;
    public:
        List();
        ~List();
        Person* locate(Person *p, int index);
        void insert(Person *p);
        void insert(Person *p, int index);
        std::string toString();
        void remove(int index);
        Person* search(Person *p);
};