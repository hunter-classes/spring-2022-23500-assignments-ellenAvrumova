#pragma once
#include "Person.h"

class Node {
    private:
        Person *p;
        Node *next;
    public:
        Node();
        Node(Person *p);
        Node(Person *p, Node *next);
        void setPerson(Person *p);
        void setNext(Node *next);
        Person getPerson();
        Node *getNext();
};