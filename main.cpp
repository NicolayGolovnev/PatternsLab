#include <iostream>
#include "Delegation/Delegate.h"
#include "Proxy/Proxy.h"
#include "Adapter/Adapter.h"
#include "Decorator/Decorator.h"
#include "Composite/Component.h"
#include "Composite/User.h"
#include "Composite/Composite.h"

void getListOfUser() {
    std::cout << "##########\tCOMPOSITE\t###########\n";
    std::cout << "Make a 1 user\n";
    Component* user1 = new User("ADEPT", "5");
    std::cout << user1->operation() << std::endl;

    std::cout << "\nMake a group of user1, user2 and 2 group of user3\n";
    Component* user2 = new User("user2", "2");
    Component* user3 = new User("user3", "3");
    Component* list = new Composite;
    Component* group1 = new Composite;
    group1->add(user1);
    group1->add(user2);
    std::cout << group1->operation() << std::endl;
    list->add(group1);
    list->add(user3);
    std::cout << list->operation() << std::endl;
    std::cout << "##########\t#########\t###########\n";
    delete user1;
    delete user2;
    delete user3;
    delete list;
    delete group1;
}

int main() {
    getListOfUser();
    return 0;
}
