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
    // head = nullptr;
    // delete head;
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

//we need a pointer BEFORE the inerstion point
/**
 * 1) stop early
 *  tmp->setNext(w->getNext());
 *  w->setNext(tmp)
 * 
 * 2) send another pointer
 *  T = head
 *  while(t->getNext() != w) {
 *      t->getNext();
 *  }
 *  
 * We use piggybacking
 * That is, send a pointer one behind that trails walker
 * When walker points to Node n,
 * the trailer points to Node n-1
 */

void List::insert(std::string data, int index) {
    //Zamansky Code
    Node *tmp = new Node(data);
    Node *walker = head;
    Node *trailer = nullptr; //this one follows behind walker

    while(walker != nullptr && index > 0) {
        trailer = walker; //this goes until it pointes to the pointer before the insertion point
        walker = walker->getNext();
        index -= 1;
    }
    //walker is at n, trailer is at the point before the insertion
    //normally - temp->setNext(w); trailer->setNext(temp)
    //first check to see if we're trying to insert beyond the end
    //Note: we can insert a new last element

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
    /**
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
    */
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

    /**
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
    */
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