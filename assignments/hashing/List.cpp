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

void List::insert(Person *p) {
    Node *temp = new Node(p);
    temp->setNext(head);
    this->head = temp;
}

std::string List::toString() {
    Node *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s += walker->getPerson()->get_name() + "-->";
        walker = walker->getNext();
    }
    s += "nullptr";
    return s;
}

void List::insert(Person *p, int index) {
    Node *tmp = new Node(p);
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

Person* List::locate(Person *p, int index) {
    Node *walker = head;

    while(walker != nullptr && index > 0) {
        walker = walker->getNext();
        index--;
    }
    if(walker) {
        return walker->getPerson();
    }
    else {
        return nullptr;
    }
}

Person* List::search(Person *p) {
    Node* walker = head;
    while(walker != nullptr) {
        if(walker->getPerson() == p) {
           return walker->getPerson();
        }
        walker = walker->getNext();
    }
    throw NOT_FOUND;
}