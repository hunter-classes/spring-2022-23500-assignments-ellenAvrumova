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
        std::string get_debug_String_helper(Node *n);
        void setup();
};