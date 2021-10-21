#include <iostream>
#include "Delegation/Delegate.h"
#include "Proxy/Proxy.h"
#include "Adapter/Adapter.h"
#include "Composite/Component.h"
#include "Composite/User.h"
#include "Composite/Composite.h"
#include "System/Letter.h"
#include "Content/Text.h"
#include "Decorator/Decorator.h"
#include "Content/Audio.h"
#include "Content/Picture.h"

void testComposite() {
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

void testIterator() {
    std::cout << "##########\tITERATOR\t###########\n";
    Content* c1 = new Audio();
    Content* c2 = new Audio("Madonna.mp3");
    Content* c3 = new Text("Tolstoy");
    Content* c4 = new Audio("Hohotach.mp3");
    Content* c5 = new Picture();

    Letter* letter = new Letter();
    letter->insertContent(c1);
    letter->insertContent(c2);
    letter->insertContent(c3);
    letter->insertContent(c4);
    letter->insertContent(c5);
    Iterator<Content*>* iter = letter->createIterator();
    for (iter->first(); iter->hasNext(); iter->next()){
        Content* c = iter->getCur();
        std::printf("%s", c->getContent().c_str());
    }
    std::cout << "##########\t########\t###########\n";
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete letter;
}

int main() {
    testDecoratorFilter();
    return 0;
}
