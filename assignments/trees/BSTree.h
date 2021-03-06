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
        int rsearch(int value);
        int rsearch(int value, Node *p);
        int rinsert(int value);
        int rinsert(int value, Node *p);
        int treesum(Node *n);
        int treesum();
        int deleteNode(int value);
        int countLeaves(Node *n);
        int numLeaves();
        int height(Node *n);
        int height();
        bool cousins(int a, int b);
};