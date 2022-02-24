#pragma once
#include "Node.h"

class List {
    private:
        Node *head;

    public:
        List();
        ~List();
        std::string locate(int index);
        void insert(std::string data);
        void insert(std::string data, int index);
        std::string toString();
        void remove(int index);
};