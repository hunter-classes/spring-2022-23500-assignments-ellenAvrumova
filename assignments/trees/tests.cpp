#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

BSTree *t = new BSTree();

TEST_CASE("SETUP") {
    t->setup();
    CHECK(t->get_debug_String() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
}

TEST_CASE("SEARCH") {
    try {
        t->search(2); //not in the tree
        CHECK(t->search(2) == 2);
    } catch(int e) {
        CHECK(e == 1);
    }
    try {
        t->search(15);
        CHECK(t->search(15) == 15);
    } catch(int e) {
        CHECK(e == 1);
    }
    try {
        t->search(8);
        CHECK(t->search(8) == 8);
    } catch(int e) {
        CHECK(e == 1);
    }
}

TEST_CASE("RECRUSIVE SEARCH") {
    try {
        t->rsearch(2);
        CHECK(t->rsearch(2) == 2);
    } catch(int e) {
        CHECK(e == 1);
    }
    try {
        t->rsearch(15);
        CHECK(t->rsearch(15) == 15);
    } catch(int e) {
        CHECK(e == 1);
    }
    try {
        t->rsearch(8);
        CHECK(t->rsearch(8) == 8);
    } catch(int e) {
        CHECK(e == 1);
    }

}

TEST_CASE("INSERT") {
    t->insert(13);
    CHECK(t->get_debug_String() == ", 3, , 5, , 8, , 10, , 13, , 15, , 20, , 30, ");
    t->insert(8);
    CHECK(t->get_debug_String() == ", 3, , 5, , 8, , 10, , 13, , 15, , 20, , 30, ");
    t->insert(7);
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 8, , 10, , 13, , 15, , 20, , 30, ");
}

TEST_CASE("RECURSIVE INSERT") {
    t->rinsert(14);
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 8, , 10, , 13, , 14, , 15, , 20, , 30, ");
    t->rinsert(5);
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 8, , 10, , 13, , 14, , 15, , 20, , 30, ");
    t->rinsert(2);
    CHECK(t->get_debug_String() == ", 2, , 3, , 5, , 7, , 8, , 10, , 13, , 14, , 15, , 20, , 30, ");
}

TEST_CASE("TREESUM") {
    CHECK(t->treesum() == 127);
}

TEST_CASE("DELETE") {
    t->deleteNode(2); //delete a leaf
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 8, , 10, , 13, , 14, , 15, , 20, , 30, ");
    t->deleteNode(8); //delete a node with 1 child
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 10, , 13, , 14, , 15, , 20, , 30, ");
    t->deleteNode(20); //delete a node with 2 children
    CHECK(t->get_debug_String() == ", 3, , 5, , 7, , 10, , 13, , 14, , 15, , 30, ");
    t->deleteNode(5);
    CHECK(t->get_debug_String() == ", 3, , 7, , 10, , 13, , 14, , 15, , 30, ");
    try {
        t->deleteNode(2); //not in the tree
    } catch(int e) {
        CHECK(e == 1);
    }
    CHECK(t->get_debug_String() == ", 3, , 7, , 10, , 13, , 14, , 15, , 30, ");
}