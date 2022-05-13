#include <iostream>
#include "Dictionary.h"
#include "Person.h"
#include "Node.h"
#include "List.h"

int main() {
    Person *ellen = new Person("Ellen", "Avrumova", 1);
    List *list = new List();
    Node e = ellen;
    list->insert(ellen);
    std::cout << list->toString() << std::endl;
    std::cout << e.getPerson().get_name() << std::endl;

    Person *bob = new Person("Bob", "Bobby", 2);
    list->insert(bob);
    std::cout << list->toString() << std::endl;
    Person *boris = new Person("Boris", "Avrumov", 6);
    list->insert(boris);
    std::cout << list->toString() << std::endl;
    list->remove(1);
    std::cout << list->toString() << std::endl;
    e.setPerson(bob);
    std::cout << e.getPerson().get_name() << std::endl;

    return 0;
}