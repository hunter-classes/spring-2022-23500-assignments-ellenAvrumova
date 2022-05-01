#pragma once
#include "Node.h"
#include <string>

class BSTree {
    private:
        Node *root;
    public:
        BSTree();
        void insert(int d);
        std::string get_debug_String();
        std::string traverse(Node *n);
        void setup();
        int search(int value);
};