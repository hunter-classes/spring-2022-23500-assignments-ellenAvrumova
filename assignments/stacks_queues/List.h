#pragma once
#include "Node.h"

class List {
    private:
        Node *head;

    public:
        List();
        ~List();
        int locate(int index);
        void insert(int data);
        void insert(int data, int index);
        std::string toString();
        void remove(int index);
};