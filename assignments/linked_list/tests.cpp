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

//************************** OLIST BEGINNING **************************
OList *l2 = new OList();

TEST_CASE("Insert") {
    l2->insert(3);
    l2->insert(7);
    l2->insert(5);
    CHECK(l2->toString() == "3-->5-->7-->nullptr");

    l2->insert(2);
    l2->insert(4);
    l2->insert(8);
    CHECK(l2->toString() == "2-->3-->4-->5-->7-->8-->nullptr");
}

TEST_CASE("Contains") {
    CHECK(l2->contains(2) == true);
    CHECK(l2->contains(4) == true);
    CHECK(l2->contains(8) == true);
    CHECK(l2->contains(1) == false);
    CHECK(l2->contains(6) == false);
}

TEST_CASE("Get") {
    CHECK(l2->get(0) == 2);
    CHECK(l2->get(5) == 8);
    CHECK(l2->get(3) == 5);
    CHECK(l2->get(6) == INT_MIN); //out of range
}

TEST_CASE("Remove") {
    l2->remove(0);
    CHECK(l2->toString() == "3-->4-->5-->7-->8-->nullptr");
    l2->remove(2);
    CHECK(l2->toString() == "3-->4-->7-->8-->nullptr");
    l2->remove(3);
    CHECK(l2->toString() == "3-->4-->7-->nullptr");
    l2->remove(4);
    CHECK(l2->toString() == "3-->4-->7-->nullptr"); //out of range so nothing changes
}

OList *l3 = new OList();

TEST_CASE("Reverse") {
    l2->reverse();
    CHECK(l2->toString() == "7-->4-->3-->nullptr");

    for(int i = 0; i < 10; i++) {
        l3->insert(i);
    }
    CHECK(l3->toString() == "0-->1-->2-->3-->4-->5-->6-->7-->8-->9-->nullptr");

    l3->reverse();
    CHECK(l3->toString() == "9-->8-->7-->6-->5-->4-->3-->2-->1-->0-->nullptr");
}

TEST_CASE("Destructor") {
    l2->~OList();
    CHECK(l2->toString() == "nullptr");

    l3->~OList();
    CHECK(l3->toString() == "nullptr");
}