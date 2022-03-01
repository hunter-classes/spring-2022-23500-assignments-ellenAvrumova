#pragma once
#include <string>

class Node{
    private:
        std::string data;
        Node *next;

    public:
        Node();
        Node(std::string data);
        Node(std::string data, Node *next);

        void setData(std::string data);
        void setNext(Node *next);

        std::string getData();
        Node *getNext();
};

class OListNode {
    private:
        int data;
        OListNode *next;

    public:
        OListNode();
        OListNode(int data);
        OListNode(int data, OListNode *next);

        void setData(int data);
        void setNext(OListNode *next);

        int getData();
        OListNode *getNext();
};