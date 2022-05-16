#include <iostream>
#include "Dictionary.h"
#include "Person.h"
#include "Node.h"
#include "List.h"

int main() {
    Dictionary *d = new Dictionary();
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;

    std::cout << "************INSERT************" << std::endl;
    Person *ellen = new Person("Ellen", "Avrumova", 18);
    d->insert(ellen);
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;
    Person *boris = new Person("Boris", "Avrumov", 22);
    d->insert(boris);
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;
    Person *bob = new Person("Bob", "Bobby", 30);
    d->insert(bob);
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;

    std::cout << "************RETRIEVAL************" << std::endl;
    Person *guy = new Person("Guy", "The", 5);
    try {
        d->retrieve(guy);
    } catch(int e) {
        std::cout << "ERROR NOT_FOUND: " << e << std::endl;
    }
    d->insert(guy);
    std::cout << d->getAll() << std::endl;
    std::cout << d->retrieve(guy)->get_name() << std::endl;
    std::cout << std::endl;

    std::cout << "************DESTRUCTOR************" << std::endl;
    d->~Dictionary();
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;

    std::cout << "************FILL THE LIST************" << std::endl;
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
    d->insert(a);
    d->insert(b);
    d->insert(c);
    d->insert(k);
    d->insert(e);
    d->insert(f);
    d->insert(g);
    d->insert(h);
    d->insert(i);
    d->insert(j);
    std::cout << d->getAll() << std::endl;
    std::cout << std::endl;

    return 0;
}