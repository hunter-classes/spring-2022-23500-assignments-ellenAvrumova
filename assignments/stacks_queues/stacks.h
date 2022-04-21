#pragma once
#include "List.h"

#define STACK_ERR_EMPTY 1
#define STACK_ERR_FULL 2
#define STACK_ERR_OTHER 4

class Stack {
    private:
        List *stack;
        int length;
    public:
        Stack();
        ~Stack();
        void push(int item);
        int pop(); // remove and return the top item
        int top(); // return but do not remove the top item
        bool is_empty(); // return true if empty, false otherwise
};