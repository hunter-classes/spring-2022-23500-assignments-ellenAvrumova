#include <iostream>
#include "BSTree.h"

BSTree::BSTree() {
    root = nullptr;
}

void BSTree::insert(int value) {
    Node *newnode = new Node(value);
    Node *p = root;
    Node *trailer;

    while(p != nullptr) {
        trailer = p;
        if(p->getData() == value) {
            return;
        }
        if(p->getData() < value) {
            p = p->getRight();
        }
        else {
            p = p->getLeft();
        }
    }
    //handle the special case of the tree being empty(null)
    if(root == nullptr) {
        root = newnode;
    }
    else {
        if(trailer->getData() < value) {
            trailer->setRight(newnode);
        }
        else {
            trailer->setLeft(newnode);
        }
    }

}

int BSTree::search(int value) {
    Node *t = root;
    while(t != nullptr) {
        int tval = t->getData();
        if (tval == value) {
            return value;
        }
        if(tval < value) {
        t = t->getRight();
        }
        else {
            t = t->getLeft();
        }
    }
    //if we get here then the value isn't in the tree
    //normally, if we had a tree of objects we could return null but since we only have an int
    //we can't return an int to represent not found so we'll throw an exception
    throw 1; //we should define our exception
    //return;
}

std::string BSTree::traverse(Node *n) {
    std::string a,b,c;
    if(n == nullptr) {
        return "";
    }
    else {
        a =  traverse(n->getLeft());
        b = std::to_string(n->getData());
        c =  traverse(n->getRight());
        return a + ", " + b+ ", " + c;
    }
}

std::string BSTree::get_debug_String() {
    return traverse(root);
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