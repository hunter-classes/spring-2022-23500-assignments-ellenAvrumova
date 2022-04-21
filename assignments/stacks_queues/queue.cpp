#include <iostream>
#include "queue.h"

Queue::Queue(){
    queue = new int[5];
    size = 0;
    head = 0;
    tail = 0;
    counter = 0;
}

Queue::~Queue() {
    delete[] queue;
}

void Queue::enqueue(int item) {
    if((head == 0 && tail == 5) || (tail == head && !is_empty())) {
        throw QUEUE_ERR_FULL;
    }
    if(tail == 5 && head != 0 && counter < head) {
        queue[counter] = item;
        tail = counter;
        counter++;
    }
    queue[tail] = item;
    size++;
    tail++;
}

int Queue::sequeue() {
    if(head == 0 && tail == 0) {
        throw QUEUE_ERR_EMPTY;
    }
    int front = queue[head];
    head++;
    size--;
    return front;
}

int Queue::front() {
    return queue[head];
}

bool Queue::is_empty() {
    std::cout << std::boolalpha;
    return (head == 0 && tail == 0);
}

bool Queue::is_full() {
    return ((head == 0 && tail == 5) || (tail == head && !is_empty()));
}

std::string Queue::printQueue() {
    std::string q = "";
    if(tail <= head) {
        for (int i = 0; i < size; i++) {
            q += std::to_string(queue[i]);
            q += " "; 
        }
    }
    else {
        for (int i = head; i < tail; i++) {
            q += std::to_string(queue[i]);
            q += " ";
        }
    }
    return q;
}