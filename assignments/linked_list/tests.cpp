#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "List.h"

List *l1 = new List();

TEST_CASE("Regular Insert") {
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    CHECK (l1->toString() == "c-->b-->a-->nullptr");
}

TEST_CASE("Insert at location") {
    l1->insert("d", 2);
    CHECK (l1->toString() == "c-->b-->d-->a-->nullptr");
    l1->insert("first", 0);
    CHECK (l1->toString() == "first-->c-->b-->d-->a-->nullptr");
    l1->insert("last", 5);
    CHECK (l1->toString() == "first-->c-->b-->d-->a-->last-->nullptr");
}

TEST_CASE("Locate") {
    CHECK(l1->locate(0) == "first");
    CHECK(l1->locate(1) == "c");
    CHECK(l1->locate(2) == "b");
    CHECK(l1->locate(3) == "d");
    CHECK(l1->locate(4) == "a");
    CHECK(l1->locate(5) == "last");
    CHECK(l1->locate(6) == "");
}

TEST_CASE("Remove") {
    l1->remove(0);
    CHECK (l1->toString() == "c-->b-->d-->a-->last-->nullptr");
    l1->remove(4);
    CHECK (l1->toString() == "c-->b-->d-->a-->nullptr");
    l1->remove(2);
    CHECK (l1->toString() == "c-->b-->a-->nullptr");
}

TEST_CASE("Destructor") {
    l1->~List();
    CHECK (l1->toString() == "nullptr");
}