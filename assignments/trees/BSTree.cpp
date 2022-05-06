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
    root = n;
    n = new Node(20);
    root->setRight(n);
    Node *n2 = new Node(30);
    n->setRight(n2);
    n2 = new Node(15);
    n->setLeft(n2);
    n2 = new Node(5);
    root->setLeft(n2);
    n = new Node(3);
    n2->setLeft(n);
    n = new Node(8);
    n2->setRight(n);
}

int BSTree::rsearch(int value) {
    return rsearch(value, root);
}

int BSTree::rsearch(int value, Node *p) {
    if(p == nullptr) {
        throw 1;
    }
    if(p->getData() == value) {
        return value;
    }
    if(p->getData() < value) {
        return rsearch(value, p->getRight());
    }
    return rsearch(value, p->getLeft());
}

int BSTree::rinsert(int value) {
    return rinsert(value, root);
}

int BSTree::rinsert(int value, Node *p) {
    Node *insert = new Node(value);
    if(p == nullptr) {
        throw 1;
    }
    if(p->getData() == value) {
        return value;
    }
    if(p->getData() < value && p->getRight() == nullptr) {
        p->setRight(insert);
        return value;
    }
    else if(p->getData() > value && p->getLeft() == nullptr) {
        p->setLeft(insert);
        return value;
    }
    else if(p->getData() < value) {
        return rinsert(value, p->getRight());
    }
    else {
        return rinsert(value, p->getLeft());
    }
}

int BSTree::treesum(Node *n) {
    if(n == nullptr) {
        return 0;
    }
    else {
        return n->getData() + treesum(n->getLeft()) + treesum(n->getRight());
    }
}

int BSTree::treesum() {
    return treesum(root);
}

int BSTree::deleteNode(int value) {
    Node *t = root;
    Node *prev = t;
    while(t != nullptr) {
        int tval = t->getData();
        int preVal = prev->getData();
        if(tval == value) {
            if((t->getLeft() == nullptr && t->getRight() == nullptr)) { //delete a leaf
                if(tval < preVal) {
                    prev->setLeft(nullptr);
                }
                else {
                    prev->setRight(nullptr);
                }
                return value;
            }
            else if((t->getLeft() != nullptr && t->getRight() == nullptr) || (t->getLeft() == nullptr && t->getRight() != nullptr)) { //delete a node with 1 child
                if(t->getRight() != nullptr) {
                    prev->setLeft(t->getRight());
                    return value;
                }
                prev->setRight(t->getLeft());
                return value;
            }
            else if(t->getLeft() != nullptr && t->getRight() != nullptr) { //delete a node with 2 children
                Node *big = t;
                Node *small = t;
                while(big->getRight() != nullptr){
                    big = big->getRight();
                }
                while(small->getLeft() != nullptr) {
                    small = small->getLeft();
                }
                if(tval < preVal) {
                    prev->setLeft(small);
                    while(small->getRight() != nullptr) {
                        small = small->getRight();
                    }
                    small->setRight(t->getRight());
                }
                else {
                    prev->setRight(big);
                    while(big->getLeft() != nullptr) {
                        big = big->getLeft();
                    }
                    big->setLeft(t->getLeft());
                }
                return value;
            }
        }
        else if(t->getData() < value) {
            prev = t;
            t = t->getRight();
        }
        else {
            prev = t;
            t = t->getLeft();
        }
    }
    throw 1;
}