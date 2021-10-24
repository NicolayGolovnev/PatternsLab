//
// Created by kolya on 10/24/2021.
//

#ifndef PATTERNS_TESTPATTERNS_H
#define PATTERNS_TESTPATTERNS_H

#include <iostream>
#include "System/RealFilter.h"
#include "Proxy/ProxyFilter.h"
#include "Adapter/OutsideProtection.h"
#include "Adapter/Adapter.h"
#include "Decorator/FilterPercentWrapper.h"
#include "Decorator/FilterRecomendationWrapper.h"
#include "Composite/Component.h"
#include "Composite/User.h"
#include "Composite/Composite.h"
#include "Content/Content.h"
#include "Content/Audio.h"
#include "Content/Text.h"
#include "Content/Picture.h"
#include "System/Letter.h"

void testDelegate() {
    std::printf("##########\tDELEGATION\t##########\n");
    RealFilter* rf1 = new RealFilter("ContentFiltering");
    rf1->getResult();

    RealFilter* rf2 = new RealFilter("AnalyzeMessageFields");
    rf2->getResult();

    RealFilter* rf3 = new RealFilter();
    rf3->getResult();

    std::printf("##########\t##########\t##########\n\n");

    delete rf1;
    delete rf2;
    delete rf3;
}

void testProxy() {
    std::printf("\a##########\tPROXY\t##########\n");
    RealFilter* filter1 = new RealFilter("ContentFiltering");
    ProxyFilter* proxyFilter = new ProxyFilter();

    printf("\nFilter: ");
    filter1->getResult();
    printf("Proxy filter: ");
    proxyFilter->getResult();

    printf("\nGet results from another (not default) filter with proxy.\n\n");
    proxyFilter->initFilter(filter1);
    printf("Filter: ");
    filter1->getResult();
    printf("Proxy filter: ");
    proxyFilter->getResult();
    std::printf("##########\t#####\t##########\n\n");

    delete filter1;
    delete proxyFilter;
}

void testAdapter() {
    std::printf("##########\tADAPTER\t##########\n");
    OutsideProtection* protection1 = new OutsideProtection();
    std::printf("Run protection1 without source and email\n");
    protection1->runProtection();

    std::printf("Run filter1 by protection1\n");
    Filter* filter1 = new Adapter(protection1);
    filter1->getResult();

    OutsideProtection* protection2 = new OutsideProtection("my source", "test@test.test");
    std::printf("\nRun protection2 with source and email\n");
    protection2->runProtection();

    std::printf("Run filter2 by protection2\n");
    Filter* filter2 = new Adapter(protection2);
    filter2->getResult();
    std::printf("##########\t#######\t##########\n");
}

void testDecoratorFilter() {
    std::printf("##########\tDECORATOR\t##########\n");
    std::printf("Made a 2 default filter: BlackList and ContentFiltering\n");
    Filter* blackListFilter = new RealFilter("BlackList");
    blackListFilter->getResult();
    Filter* contentFilteringFilter = new RealFilter("ContentFiltering");
    contentFilteringFilter->getResult();

    std::printf("\nNow made decorators for this filters\n");
    Filter* decorator1 = new FilterPercentWrapper(new FilterRecomendationWrapper(blackListFilter));
    decorator1->getResult();
    Filter* decorator2 = new FilterPercentWrapper(new FilterRecomendationWrapper(contentFilteringFilter));
    decorator2->getResult();
    std::printf("##########\t#########\t##########\n");
}

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

#endif // PATTERNS_TESTPATTERNS_H