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
    std::cout << q->is_empty() << std::endl; //true
    std::cout << q->is_full() << std::endl; //false

    q->enqueue(3);
    q->enqueue(5);
    q->enqueue(4);
    std::cout << q->is_empty() << std::endl; //false
    std::cout << q->is_full() << std::endl; //false

    std::cout << q->printQueue() << std::endl; // 3 5 4

    std::cout << "REMOVE " << q->sequeue() << std::endl; // 3
    std::cout << q->printQueue() << std::endl; // 5 4

    q->enqueue(10);
    std::cout << q->printQueue() << std::endl; // 5 4 10
    
    q->enqueue(15);
    std::cout << q->printQueue() << std::endl; // 5 4 10 15

    q->enqueue(21);
    std::cout << q->printQueue() << std::endl; // 21 5 4 10 15

    std::cout << "REMOVE " << q->sequeue() << std::endl; // 5

    q->enqueue(13);
    std::cout << q->printQueue() << std::endl; // 21 13 4 10 15
    
    std::cout << q->is_empty() << std::endl; //false
    std::cout << q->is_full() << std::endl; //true

    Queue *t = new Queue();

    t->enqueue(5);
    t->enqueue(10);
    t->enqueue(15);
    t->enqueue(20);
    t->enqueue(25);
    std::cout << t->printQueue() << std::endl;
    t->sequeue();
    t->sequeue();
    t->sequeue();
    t->sequeue();
    t->sequeue();
    std::cout << t->printQueue() << std::endl;
    t->enqueue(1);
    t->enqueue(3);
    t->enqueue(7);
    t->enqueue(9);
    std::cout << t->printQueue() << std::endl;

    return 0;
}