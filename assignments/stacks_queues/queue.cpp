#include <iostream>
#include "queue.h"

Queue::Queue(){
    size = 0;
    head = 0;
    tail = 0;
    counter = 0;
}

void Queue::enqueue(int item) {
    if(size >= 5) {
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
    if(size <= 0) {
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

void Queue::print() {
    if(tail <= head) {
        for (int i = 0; i < size; i++) {
            std::cout << queue[i] << " "; 
        }
    }
    else {
        for (int i = head; i < tail; i++) {
            std::cout << queue[i] << " ";
        }
    }
	std::cout << std::endl;
}

bool Queue::is_empty() {
    std::cout << std::boolalpha;
    return (head == 0 && tail == 0);
}

bool Queue::is_full() {
    return ((head == 0 && tail == 5) || (tail == head && !is_empty()));
}