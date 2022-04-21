#include <iostream>
#include "List.h"
#include <climits>

List::List() {
    head = nullptr;
}

List::~List() {
    Node *trailer;
    //std::cerr << "Destructor" << std::endl;
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

//************************** OLIST BEGINNING **************************
OList::OList() {
    head = nullptr;
}

OList::~OList() {
    OListNode *trailer;
    //std::cerr << "Destructor" << std::endl;
    while(head != nullptr) {
        trailer = head;
        head = head->getNext();
        delete trailer;
    }
}

void OList::insert(int value) {
    OListNode *new_node = new OListNode(value);
    OListNode *walker = head;
    OListNode *trailer = nullptr;

    int counter = 0;
    while(walker != nullptr && walker->getData() < value) {
        trailer = walker;
        walker = walker->getNext();
        counter++;
    }
    if(counter == 0) {
        new_node->setNext(head);
        head = new_node;
        return;
    }
    else {
        new_node->setNext(walker);
        trailer->setNext(new_node);
    }
}

std::string OList::toString() {
    OListNode *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s += std::to_string(walker->getData()) + "-->";
        walker = walker->getNext();
    }
    s += "nullptr"; //last value prints nullptr
    return s;
}

bool OList::contains(int value) {
    std::cout << std::boolalpha;
    OListNode *walker = head;
    while(walker != nullptr) {
        if(walker->getData() == value) {
            return true;
        }
        walker = walker->getNext();
    }
    return false;
}

int OList::get(int loc) {
    OListNode *walker = head;

    while(walker != nullptr && loc > 0) {
        walker = walker->getNext();
        loc--;
    }
    if(walker) {
        return walker->getData();
    }
    else {
        return INT_MIN;
    }
}

void OList::remove(int loc) {
    OListNode *walker = head;
    OListNode *trailer = nullptr;

    while(walker != nullptr && loc > 0) {
        trailer = walker;
        walker = walker->getNext();
        loc -= 1;
    }

    if(!walker) { //walker == nullptr
        //throw std::out_of_range("Out of range");
        //std::cout << "OUT OF RANGE" << std::endl;
        return;
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

void OList::reverse() {
    OListNode *walker = head;
    OListNode *trailer = nullptr;

    while(walker != nullptr) {
        OListNode *tempNext = walker->getNext();
        walker->setNext(trailer); //changes arrow direction
        trailer = walker;
        walker = tempNext;
    }
    head = trailer;
}