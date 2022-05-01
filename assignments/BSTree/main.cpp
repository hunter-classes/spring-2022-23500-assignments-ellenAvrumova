#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main() {
    /** Video 2 Code
    Node *n = new Node(20);
    std::cout << n->getData() << std::endl;
    Node *n2 = new Node(30);
    n->setLeft(n2);
    n2 = new Node(40);
    n->setRight(n2);
    std::cout << n->getLeft()->getData() << std::endl;
    std::cout << n->getRight()->getData() << std::endl;
    */

   //Video 2 Task
   Node *n = new Node(10);
   Node *n2 = new Node(20);
   Node *n3 = new Node(30);
   n->setLeft(n2);
   n->getLeft()->setLeft(n3);
   Node *n4 = new Node(40);
   n->getLeft()->getLeft()->setLeft(n4);
   Node *n5 = new Node(50);
   n->setRight(n5);
   Node *n6 = new Node(60);
   n->getRight()->setRight(n6);
   Node *n7 = new Node(70);
   n->getRight()->setLeft(n7);

   std::cout << n->getData() << std::endl; //10
   std::cout << n->getLeft()->getData() << " " << n->getLeft()->getLeft()->getData() << " " << n->getLeft()->getLeft()->getLeft()->getData() << std::endl; //20 30 40
   std::cout << n->getRight()->getData() << " " << n->getRight()->getRight()->getData() << " " << n->getRight()->getLeft()->getData() <<std::endl; //50 60 70


   BSTree *t = new BSTree();
   t->setup();
   std::cout << t->get_debug_String_helper(n) << std::endl; //it traverses through 10 20 30 40 50 60 70, all the nodes

   return 0;
}