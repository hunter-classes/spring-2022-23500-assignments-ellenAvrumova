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
    //this way makes a new node and prints a new list when inserting twices
    /**
    Node *new_node = new Node(data);//create a new node

    //insert the new node
    //head->setNext(new_node);
    new_node->setNext(head);
    head = new_node;
    */
    //Node *temp = new Node(data);
    //this->head = temp;
    
    //now can insert any number of items in a list
    Node *temp = new Node(data);
    temp->setNext(head);
    this->head = temp;
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

void List::insert(std::string data, int index) {
    Node *new_node = new Node(data);
    Node *walker = head;
    Node *temp;
    
    if(index == 0) {
       new_node->setNext(walker);
       head = new_node;
    }
    else {
        int counter = 0;
        while(walker != nullptr && counter < index-1) {
            walker = walker->getNext();
            counter++;
        }

        temp = walker->getNext();
        walker->setNext(new_node);
        new_node->setNext(temp);
    }
}

void List::remove(int index) {
    Node *walker = head;
    Node *temp;

    if(index == 0) {
        head = walker->getNext();
    }

    else {
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