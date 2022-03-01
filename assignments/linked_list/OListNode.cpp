#include <iostream>
#include "Node.h"

OListNode::OListNode() : next(nullptr) { //sets the next as nullptr
}

OListNode::OListNode(int data) {
    this->data = data;
    this->next = nullptr;
}

OListNode::OListNode(int data, OListNode *next) {
    this->data = data;
    this->next = next;
}

void OListNode::setData(int data) {
    this->data = data;
}

void OListNode::setNext(OListNode *next) {
    this->next = next;
}

int OListNode::getData() {
    return this->data;
}

OListNode *OListNode::getNext() {
    return this->next;
}