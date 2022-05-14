#include <iostream>
#include "Node.h"

Node::Node() : next(nullptr) { //sets the next as nullptr
}

Node::Node(Person *p) {
    this->p = p;
    this->next = nullptr;
}

Node::Node(Person *p, Node *next) {
    this->p = p;
    this->next = next;
}

void Node::setPerson(Person *p) {
    this->p = p;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Person* Node::getPerson() {
    return this->p;
}

Node* Node::getNext() {
    return this->next;
}