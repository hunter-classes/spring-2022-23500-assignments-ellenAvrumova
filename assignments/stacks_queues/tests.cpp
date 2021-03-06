#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "stacks.h"
#include "queue.h"

Stack *s = new Stack();

TEST_CASE("EMPTY") {
    CHECK(s->is_empty() == true);
}

TEST_CASE("PUSH") {
    s->push(3);
    CHECK(s->top() == 3);
    s->push(21);
    CHECK(s->top() == 21);
    s->push(14);
    CHECK(s->top() == 14);
    s->push(8);
    CHECK(s->top() == 8);
    s->push(9);
    CHECK(s->top() == 9);
    s->push(13);
    CHECK(s->top() == 13);
    s->push(26);
    CHECK(s->top() == 26);
}

TEST_CASE("NOT EMPTY") {
    CHECK(s->is_empty() == false);
}

TEST_CASE("POP") {
    s->pop();
    CHECK(s->top() == 13);
    s->pop();
    CHECK(s->top() == 9);
    s->pop();
    CHECK(s->top() == 8);
    s->pop();
    CHECK(s->top() == 14);
    s->pop();
    CHECK(s->top() == 21);
    s->pop();
    CHECK(s->top() == 3);
    s->pop();

    try {
        s->top();
    } catch(int e) {
        CHECK(e == STACK_ERR_EMPTY);
    }
    try {
        s->pop();
    } catch(int e) {
        CHECK(e == STACK_ERR_EMPTY);
    }
}

TEST_CASE("EMPTY") {
    CHECK(s->is_empty() == true);
}

TEST_CASE("DESTRUCTOR") {
    s->~Stack();
    try {
        s->top();
    } catch(int e) {
        CHECK(e == STACK_ERR_EMPTY);
    }
}

Queue *a = new Queue();

TEST_CASE("IS EMPTY") {
    CHECK(a->is_empty() == true);
}

TEST_CASE("ENQUEUE") {
    a->enqueue(5);
    CHECK(a->front() == 5);
    CHECK(a->printQueue() == "5 ");
    a->enqueue(10);
    CHECK(a->front() == 5);
    CHECK(a->printQueue() == "5 10 ");
    a->enqueue(15);
    CHECK(a->front() == 5);
    CHECK(a->printQueue() == "5 10 15 ");
    a->enqueue(20);
    CHECK(a->printQueue() == "5 10 15 20 ");
    a->enqueue(25);
    CHECK(a->printQueue() == "5 10 15 20 25 ");

    try {
        a->enqueue(30);
    } catch(int e) {
        CHECK(e == QUEUE_ERR_FULL);
    }
    CHECK(a->front() == 5);
}

TEST_CASE("IS FULL") {
    CHECK(a->is_full() == true);
}

TEST_CASE("SEQUEUE") {
    a->sequeue();
    CHECK(a->front() == 10);
    CHECK(a->printQueue() == "10 15 20 25 ");
    a->sequeue();
    CHECK(a->front() == 15);
    CHECK(a->printQueue() == "15 20 25 ");
    a->sequeue();
    CHECK(a->front() == 20);
    CHECK(a->printQueue() == "20 25 ");
    a->sequeue();
    CHECK(a->front() == 25);
    CHECK(a->printQueue() == "25 ");
    a->sequeue();
    CHECK(a->printQueue() == "");

    try {
        a->front();
    } catch(int e) {
        CHECK(e == QUEUE_ERR_EMPTY);
    }
    try {
        a->sequeue();
    } catch(int e) {
        CHECK(e == QUEUE_ERR_EMPTY);
    }

    CHECK(a->is_empty() == true);

    a->enqueue(2);
    CHECK(a->front() == 2);
    a->enqueue(4);
    a->enqueue(6);
    a->enqueue(8);
    a->enqueue(10);
    CHECK(a->printQueue() == "2 4 6 8 10 ");
}

TEST_CASE("IS FULL") {
    CHECK(a->is_full() == true);
}

TEST_CASE("DESTRUCTOR") {
    a->~Queue();
    try {
        a->sequeue();
    } catch(int e) {
        CHECK(e == QUEUE_ERR_EMPTY);
    }
}
