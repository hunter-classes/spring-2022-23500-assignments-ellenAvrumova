#include <iostream>
#include <unistd.h>

#include "stacks.h"
#include "queue.h"

int main() {
    Stack *s = new Stack();
    std::cout << s->is_empty() << std::endl;
    s->push(5);
    std::cout << s->top() << std::endl;
    std::cout << s->is_empty() << std::endl;
    s->push(8);
    std::cout << s->top() << std::endl;
    s->push(10);
    std::cout << s->top() << std::endl;

    std::cout << s->pop() << std::endl;
    std::cout << s->pop() << std::endl;
    std::cout << s->pop() << std::endl;

    try{
        std::cout << s->pop() << std::endl;
    } catch(int e) {
        std::cout << "Error code: " << e << " : STACK EMPTY" << std::endl;
    }
    std::cout << s->is_empty() << std::endl;

    return 0;
}