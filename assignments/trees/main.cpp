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

   std::cout << "Setup: " << t->get_debug_String() << std::endl;
   int v = 15;

   try {
       int x = t->search(v);
       std::cout << "Found: " << x << std::endl;
   } catch(int e) {
       std::cout << v << " not found\n";
   }

   t->insert(22);
   std::cout << "Insert 22: " << t->get_debug_String() << std::endl;
   t->insert(3);
   std::cout << "Insert 3: " << t->get_debug_String() << std::endl;

   try {
        int x = t->rsearch(v);
        std::cout << "Found " << x << " recursively" << std::endl;
   } catch(int e) {
       std::cout << v << " not found\n";
   }

   t->rinsert(2);
   std::cout << "Insert 2 recursively: " << t->get_debug_String() << std::endl;
   t->rinsert(9);
   std::cout << "Insert 9 recursively: " << t->get_debug_String() << std::endl;
   t->rinsert(8);
   std::cout << "Insert 8 recursively: " << t->get_debug_String() << std::endl;

   std::cout << "Tree sum: " << t->treesum() << std::endl;

   std::cout << t->get_debug_String() << std::endl;

   BSTree *tr = new BSTree();
   tr->setup();
   std::cout << tr->get_debug_String() << std::endl;
   std::cout << tr->deleteNode(3) << std::endl;
   std::cout << tr->deleteNode(5) << std::endl;
   std::cout << tr->deleteNode(20) << std::endl;
   std::cout << tr->get_debug_String() << std::endl;

   return 0;
}