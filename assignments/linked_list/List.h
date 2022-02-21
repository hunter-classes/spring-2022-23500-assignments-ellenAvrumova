#pragma once
#include "Node.h"

class List {
    private:
        Node *head;

    public:
        List();
        void insert(std::string data);
        std::string toString();
        //insert at location
        //delete at location
        //destructor
};