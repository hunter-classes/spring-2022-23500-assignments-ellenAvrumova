#include <iostream>
#include "List.h"
#include <climits>

List::List() {
    head = nullptr;
}

List::~List() {
    Node *trailer;
    while(head != nullptr) {
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}

void List::insert(int data) {
    Node *temp = new Node(data);
    temp->setNext(head);
    this->head = temp;
}

std::string List::toString() {
    Node *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s += std::to_string(walker->getData()) + "-->";
        walker = walker->getNext();
    }
    s += "nullptr";
    return s;
}

int List::locate(int index) {
    std::string result = "";
    Node *walker = head;

    while(walker != nullptr && index > 0) {
        walker = walker->getNext();
        index--;
    }
    if(walker) {
        return walker->getData();
    }
    else {
        return INT_MIN;
    }
}

void List::insert(int data, int index) {
    Node *tmp = new Node(data);
    Node *walker = head;
    Node *trailer = nullptr;

    while(walker != nullptr && index > 0) {
        trailer = walker;
        walker = walker->getNext();
        index -= 1;
    }

    if(index > 0) {
        throw std::out_of_range("Out of range");
        return;
    }

    if(trailer == nullptr) {
        tmp->setNext(head);
        head = tmp;
    }
    else {
        tmp->setNext(walker);
        trailer->setNext(tmp);
    }
}

void List::remove(int index) {
    Node *walker = head;
    Node *trailer = nullptr;

    while(walker != nullptr && index > 0) {
        trailer = walker;
        walker = walker->getNext();
        index -= 1;
    }

    if(!walker) {
        throw std::out_of_range("Out of range");
        return;
    }
    if(trailer == nullptr) {
        head = walker->getNext();
        delete walker;
    }
    else {
        trailer->setNext(walker->getNext());
        delete walker;
    }
}