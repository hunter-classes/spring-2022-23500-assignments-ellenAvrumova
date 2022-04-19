#include <iostream>
#include "stacks.h"
#include "List.h"

Stack::Stack() {
    stack = new List();
    length = 0;
}

Stack::~Stack() {
    stack->~List();
}

void Stack::push(int item) {
    stack->insert(item);
    length++;
}

int Stack::pop() {
    if(length == 0) {
        throw STACK_ERR_EMPTY;
    }
    int pop = stack->locate(0);
    stack->remove(0);
    length--;
    return pop;
}

int Stack::top() {
    return stack->locate(0);
}

bool Stack::is_empty() {
    std::cout << std::boolalpha;
    return length == 0;
}




