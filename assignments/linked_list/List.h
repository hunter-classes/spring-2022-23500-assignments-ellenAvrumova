#pragma once
#include "Node.h"

class List {
    private:
        Node *head;

    public:
        List();
        ~List();
        std::string locate(int index);
        void insert(std::string data);
        void insert(std::string data, int index);
        std::string toString(); //for testsing and debugging
        void remove(int index);
};

class OList {
    private:
        OListNode *head;

    public:
        OList();
        ~OList();
        void insert(int value);
        std::string toString();
        bool contains(int value);
        int get(int loc);
        void remove(int loc);
        void reverse();
        int length();
};