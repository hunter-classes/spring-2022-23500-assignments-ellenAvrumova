#pragma once

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue {
    private:
        int queue[5];
        int size;
        int head;
        int tail;
        int counter;
    public:
        Queue();
        void enqueue(int item); // add an item to the back of the queue
        int sequeue(); // remove and return the item from the front of the queue
        int front(); // return but do not remove the item from the front of the queue
        bool is_empty();
        bool is_full();
        void print();
};