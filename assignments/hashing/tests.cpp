#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

Dictionary *d = new Dictionary();
Person *a = new Person("Marnie", "Mcmillan", 1);
Person *b = new Person("Kelise", "Talley", 2);
Person *c = new Person("Om", "Mcpherson", 3);
Person *k = new Person("Catriona", "Hogan", 4);
Person *e = new Person("Ernest", "Conroy", 5);
Person *f = new Person("Aniya", "Adamson", 6);
Person *g = new Person("Hattie", "Powell", 7);
Person *h = new Person("Aariz", "Mendoza", 8);
Person *i = new Person("Zaina", "Lees", 9);
Person *j = new Person("Griff", "Diaz", 10);

Person *ellen = new Person("Ellen", "Avrumova", 18);
Person *boris = new Person("Boris", "Avrumov", 22);

TEST_CASE("CONSTRUCTOR") {
    CHECK(d->getAll() == "");
}

TEST_CASE("HASH FUNCTION") {
    CHECK(d->hash(a->get_name()) == 3);
    CHECK(d->hash(b->get_name()) == 0);
    CHECK(d->hash(c->get_name()) == 7);
    CHECK(d->hash(k->get_name()) == 6);
    CHECK(d->hash(e->get_name()) == 5);
    CHECK(d->hash(f->get_name()) == 1);
    CHECK(d->hash(g->get_name()) == 0);
    CHECK(d->hash(h->get_name()) == 7);
    CHECK(d->hash(i->get_name()) == 8);
    CHECK(d->hash(j->get_name()) == 2);
}

TEST_CASE("INSERT") {
    d->insert(a);
    CHECK(d->getAll() == "Mcmillan, Marnie-->nullptr | ");
    d->insert(b);
    CHECK(d->getAll() == "Talley, Kelise-->nullptr | Mcmillan, Marnie-->nullptr | ");
    d->insert(c);
    CHECK(d->getAll() == "Talley, Kelise-->nullptr | Mcmillan, Marnie-->nullptr | Mcpherson, Om-->nullptr | ");
    d->insert(k);
    CHECK(d->getAll() == "Talley, Kelise-->nullptr | Mcmillan, Marnie-->nullptr | Hogan, Catriona-->nullptr | Mcpherson, Om-->nullptr | ");
    d->insert(e);
    CHECK(d->getAll() == "Talley, Kelise-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mcpherson, Om-->nullptr | ");
    d->insert(f);
    CHECK(d->getAll() == "Talley, Kelise-->nullptr | Adamson, Aniya-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mcpherson, Om-->nullptr | ");
    d->insert(g);
    CHECK(d->getAll() == "Powell, Hattie-->Talley, Kelise-->nullptr | Adamson, Aniya-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mcpherson, Om-->nullptr | ");
    d->insert(h);
    CHECK(d->getAll() == "Powell, Hattie-->Talley, Kelise-->nullptr | Adamson, Aniya-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mendoza, Aariz-->Mcpherson, Om-->nullptr | ");
    d->insert(i);
    CHECK(d->getAll() == "Powell, Hattie-->Talley, Kelise-->nullptr | Adamson, Aniya-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mendoza, Aariz-->Mcpherson, Om-->nullptr | Lees, Zaina-->nullptr | ");
    d->insert(j);
    CHECK(d->getAll() == "Powell, Hattie-->Talley, Kelise-->nullptr | Adamson, Aniya-->nullptr | Diaz, Griff-->nullptr | Mcmillan, Marnie-->nullptr | Conroy, Ernest-->nullptr | Hogan, Catriona-->nullptr | Mendoza, Aariz-->Mcpherson, Om-->nullptr | Lees, Zaina-->nullptr | ");
}

TEST_CASE("RETRIEVE") {
    try {
        d->retrieve(ellen);
        CHECK(d->retrieve(ellen) == ellen);
    } catch(int e) {
        CHECK(e == NOT_FOUND);
    }
    try {
        d->retrieve(boris);
        CHECK(d->retrieve(boris) == boris);
    } catch(int e) {
        CHECK(e == NOT_FOUND);
    }
    CHECK(d->retrieve(a) == a);
    CHECK(d->retrieve(c) == c);
    CHECK(d->retrieve(f) == f);
    d->insert(boris);
    CHECK(d->retrieve(boris) == boris);
    d->insert(ellen);
    CHECK(d->retrieve(ellen) == ellen);
}

