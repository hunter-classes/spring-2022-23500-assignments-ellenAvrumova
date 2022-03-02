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

    //same thing as while loop
    for(walker = n1; walker != nullptr; walker = walker->getNext()) {
        std::cout << walker->getData() << std::endl;
    }
    
    // at this point walker points to (refers to) nullptr
    // and if we try to dereference it, we get a segmentation fault
    // std::cout << walker->getData() << std::endl; (gives segfault)

    List *l1 = new List();
    std::cout << "***Regular Insert***" << std::endl;
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    std::cout << l1->toString() << std::endl; //c b a

    std::cout << "***Insert at location***" << std::endl;
    l1->insert("d", 2);
    std::cout << l1->toString() << std::endl; //c b d a
    l1->insert("first", 0);
    std::cout << l1->toString() << std::endl; //first c b a
    l1->insert("last", 5);
    std::cout << l1->toString() << std::endl; //first c b a last

    std::cout << "***Locate***" << std::endl;
    std::cout << "First " << l1->locate(0) << std::endl; //first
    std::cout << "Second " << l1->locate(1) << std::endl; //c
    std::cout << "Third " << l1->locate(2) << std::endl; //b
    std::cout << "Fourth " << l1->locate(3) << std::endl; //d
    std::cout << "Fifth " << l1->locate(4) << std::endl; //a
    std::cout << "Sixth " << l1->locate(5) << std::endl; //last
    std::cout << "Seventh " << l1->locate(6) << std::endl; //nullptr

    std::cout << "***Remove***" << std::endl;
    l1->remove(0);
    std::cout << l1->toString() << std::endl; //c b d a last
    l1->remove(4);
    std::cout << l1->toString() << std::endl; //c b d a

    std::cout << "***Destructor***" << std::endl;
    l1->~List();
    std::cout << l1->toString() << std::endl; //nullptr
    return 0;
*/

    OList *l2 = new OList();

    std::cout << "***Insert***" << std::endl;
    l2->insert(2);
    std::cout << l2->toString() << std::endl; //2-->nullptr
    l2->insert(4);
    std::cout << l2->toString() << std::endl; //2-->4-->nullptr
    l2->insert(3);
    std::cout << l2->toString() << std::endl; //2-->3-->4-->nullptr
    l2->insert(1);
    std::cout << l2->toString() << std::endl; //1-->2-->3-->4-->nullptr

    
}