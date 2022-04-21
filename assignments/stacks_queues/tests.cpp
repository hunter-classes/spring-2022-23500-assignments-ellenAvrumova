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

