#include <iostream>
#include "List.h"

List::List() {
    head = nullptr;
}

List::~List() {
    Node *trailer;
    std::cerr << "Destructor" << std::endl;
    while(head != nullptr) {
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}

void List::insert(std::string data) {
    Node *temp = new Node(data);
    temp->setNext(head);
    this->head = temp;
}

std::string List::toString() {
    Node *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s = s + walker->getData() + "-->";
        walker = walker->getNext();
    }
    s += "nullptr"; //last value prints nullptr
    return s;
}

std::string List::locate(int index) {
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
        return "";
    }
}

//piggybacking
void List::insert(std::string data, int index) {
    Node *tmp = new Node(data);
    Node *walker = head;
    Node *trailer = nullptr; //this one follows behind walker

    while(walker != nullptr && index > 0) {
        trailer = walker; //this goes until it pointes to the pointer before the insertion point
        walker = walker->getNext();
        index -= 1;
    }

    //first check to see if we're trying to insert beyond the end
    if(index > 0) {
        std::cout << "TOO FAR" << std::endl;
        //throw std::out_of_range("Out of range");
    }

    //inserting at location 0 will have trailer = nullptr
    //so we have to deal with that special case
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

    if(!walker) { //walker == nullptr
        std::cout << "TOO FAR" << std::endl;
        //throw std::out_of_range("Out of range");
    }
    //delete at location 0
    if(trailer == nullptr) {
        head = walker->getNext();
        delete walker;
    }
    else { //delete normally
        trailer->setNext(walker->getNext());
        delete walker;
    }
}

int List::length(){
  int l = 0;
  Node *walker = head;
  while (walker){
    l++;
    walker = walker->getNext();
  }
  return l;
}