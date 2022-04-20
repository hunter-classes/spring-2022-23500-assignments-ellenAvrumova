#include <iostream>
#include <unistd.h>

#include "stacks.h"
#include "queue.h"

int main() {
    std::cout << "********** STACKS **********" << std::endl;
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

    std::cout << "\n********** QUEUES **********" << std::endl;
    Queue *q = new Queue();
    q->enqueue(3);
    q->enqueue(5);
    q->enqueue(4);

    q->print(); // 3 5 4

    std::cout << "REMOVE " << q->sequeue() << std::endl; // 3
    q->print(); // 5 4

    q->enqueue(10);
    q->print(); // 5 4 10
    std::cout << q->front() << std::endl; //5
    
    q->enqueue(15);
    q->print(); // 5 4 10 15

    q->enqueue(21);
    q->print(); // 21 5 4 10 15

    std::cout << "REMOVE " << q->sequeue() << std::endl; // 5

    q->enqueue(13);
    q->print(); // 21 13 4 10 15


    return 0;
}