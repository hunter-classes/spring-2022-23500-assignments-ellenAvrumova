#include <iostream>
#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

void BSTree::insert(int d) {

}

std::string BSTree::get_debug_String_helper(Node *n) {
    if(n == nullptr) {
        return "";
    }
    else {
        return (std::to_string(n->getData()) + "-->" + get_debug_String_helper(n->getLeft())  + "-->" + get_debug_String_helper(n->getRight()));
    }
}

std::string BSTree::get_debug_String() {
    if(root == nullptr) {
        return "";
    }
    else {
        return std::to_string(root->getData()) + std::to_string(root->getRight()->getData());
    }
}

void BSTree::setup() {
    Node *n = new Node(10);
    root =n;
    n = new Node(20);
    root->setLeft(n);
    n = new Node(30);
    root->setRight(n);
    n = new Node(40);
    root->getLeft()->setLeft(n);
}