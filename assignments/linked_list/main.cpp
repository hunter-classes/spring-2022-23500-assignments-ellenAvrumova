#include <iostream>
#include "Node.h"
#include "List.h"

int main(int argc, char *argv[]) {
/**
    Node *p1 = new Node();
    p1->setData("hello"); // same as (*p1).setData 

    Node *p2 = new Node("World");

    p1->setNext(p2);

    std::cout << p1->getData() << std::endl;
    std::cout << p2->getData() << std::endl;
    std::cout << p1->getNext()->getData() << std::endl;

    p2 = new Node("!");
    p1->getNext()->setNext(p2);
    std::cout << p1->getData() << std::endl;
    std::cout << p1->getNext()->getData() << std::endl;
    std::cout << p1->getNext()->getNext()->getData() << std::endl;

    Node *walker = p1;
    std::cout << walker->getData() << std::endl;

    walker = walker->getNext(); // equal to walker = p1->getNext();
    std::cout << walker->getData() << std::endl;

    walker = walker->getNext(); // equal to walker = p1->getNext();
    std::cout << walker->getData() << std::endl;

    walker = p1;
    while(walker != nullptr) {
        std::cout << walker->getData() << std::endl;
        walker = walker->getNext(); // equal to walker = p1->getNext();
    }
    
    // at this point walker points to (refers to) nullptr
    // and if we try to dereference it, we get a segmentation fault
    // std::cout << walker->getData() << std::endl; (gives segfault)
*/

    List *l1 = new List();
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");

    std::cout << l1->toString() << std::endl;
    return 0;
}