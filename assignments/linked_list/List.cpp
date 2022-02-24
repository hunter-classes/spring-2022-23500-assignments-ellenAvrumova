#include <iostream>
#include "List.h"

List::List() {
    head = nullptr;
}

List::~List() {
    head = nullptr;
    delete head;
}

void List::insert(std::string data) {
    //create a new node
    Node *new_node = new Node(data);

    //insert the new node
    //head->setNext(new_node);
    new_node->setNext(head);
    head = new_node;
}

std::string List::toString() {
    // if(head == nullptr) {
    //     return "";
    // }
    // return head->getData();
    Node *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }
    s += "nullptr";
    return s;
}

std::string List::locate(int index) {
    Node *walker = head;

    int counter = 0;
    while(walker != nullptr && counter < index-1) {
        walker = walker->getNext();
        counter++;
    }

    return walker->getNext()->getData();
}

void List::insert(std::string data, int index) {
    Node *new_node = new Node(data);
    Node *walker = head;
    Node *temp;
    
    int counter = 0;
    while(walker != nullptr && counter < index-1) {
        walker = walker->getNext();
        counter++;
    }

    temp = walker->getNext();
    walker->setNext(new_node);
    new_node->setNext(temp);
}

void List::remove(int index) {
    Node *walker = head;
    Node *temp;

    int counter = 0;
    while(walker != nullptr) {
        if(counter == index-1) {
            temp = walker->getNext();
            walker->setNext(walker->getNext()->getNext());
            break;
        }
        walker = walker->getNext();
        counter++;
    }
    delete temp;
}