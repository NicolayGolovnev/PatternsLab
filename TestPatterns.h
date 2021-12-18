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
#include "Builder/LetterBuilder.h"
#include "Builder/Director.h"
#include "System/FilterTraining.h"
#include "State/ReadyState.h"
#include "State/ExecuteState.h"
#include "State/InitState.h"
#include "Visitor/JSONExportVisitor.h"
#include "System/Config.h"
#include "Memento/ConfigHistory.h"

using namespace std;

void testDelegate() {
    printf("##########\tDELEGATION\t##########\n");
    RealFilter* rf1 = new RealFilter("ContentFiltering");
    rf1->getResult();

    RealFilter* rf2 = new RealFilter("AnalyzeMessageFields");
    rf2->getResult();

    RealFilter* rf3 = new RealFilter();
    rf3->getResult();

    printf("##########\t##########\t##########\n\n");

    delete rf1;
    delete rf2;
    delete rf3;
}

void testProxy() {
    printf("\a##########\tPROXY\t##########\n");
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
    printf("##########\t#####\t##########\n\n");

    delete filter1;
    delete proxyFilter;
}

void testAdapter() {
    printf("##########\tADAPTER\t##########\n");
    OutsideProtection* protection1 = new OutsideProtection();
    printf("Run protection1 without source and email\n");
    protection1->runProtection();

    printf("Run filter1 by protection1\n");
    Filter* filter1 = new Adapter(protection1);
    filter1->getResult();

    OutsideProtection* protection2 = new OutsideProtection("my source", "test@test.test");
    printf("\nRun protection2 with source and email\n");
    protection2->runProtection();

    printf("Run filter2 by protection2\n");
    Filter* filter2 = new Adapter(protection2);
    filter2->getResult();
    printf("##########\t#######\t##########\n");

    delete protection1;
    delete protection2;
    delete filter1;
    delete filter2;
}

void testDecoratorFilter() {
    printf("##########\tDECORATOR\t##########\n");
    printf("Made a 2 default filter: BlackList and ContentFiltering\n");
    Filter* blackListFilter = new RealFilter("BlackList");
    blackListFilter->getResult();
    Filter* contentFilteringFilter = new RealFilter("ContentFiltering");
    contentFilteringFilter->getResult();

    printf("\nNow made decorators for this filters\n");
    Filter* decorator1 = new FilterPercentWrapper(new FilterRecomendationWrapper(blackListFilter));
    decorator1->getResult();
    Filter* decorator2 = new FilterPercentWrapper(new FilterRecomendationWrapper(contentFilteringFilter));
    decorator2->getResult();
    printf("##########\t#########\t##########\n");

    delete blackListFilter;
    delete contentFilteringFilter;
    delete decorator1;
    delete decorator2;
}

void testComposite() {
    cout << "##########\tCOMPOSITE\t###########\n";
    cout << "Make a 1 user\n";
    Component* user1 = new User("ADEPT", "5");
    cout << user1->operation() << std::endl;

    cout << "\nMake a group of user1, user2 and 2 group of user3\n";
    Component* user2 = new User("user2", "2");
    Component* user3 = new User("user3", "3");
    Component* list = new Composite;
    Component* group1 = new Composite;
    group1->add(user1);
    group1->add(user2);
    cout << group1->operation() << std::endl;
    list->add(group1);
    list->add(user3);
    cout << list->operation() << std::endl;
    cout << "##########\t#########\t###########\n";
    delete user1;
    delete user2;
    delete user3;
    delete list;
    delete group1;
}

void testIterator() {
    cout << "##########\tITERATOR\t###########\n";
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
    cout << "##########\t########\t###########\n";
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;
    delete letter;
}

void testBuilder() {

    list<string>* recipients = new list<string>();
    recipients->push_back("recipient1");
    recipients->push_back("recipient2");
    recipients->push_back("recipient3");
    vector<Content*>* contents = new vector<Content*>();
    contents->push_back(new Audio("Shrek_2.mp3"));
    contents->push_back(new Picture());
    contents->push_back(new Text("Some manga"));

    cout << "##########\tBUILDER\t##########" << endl;
    cout << "Build letter from builder:" << endl;
    LetterBuilder* builder = new LetterBuilder();
    builder->hiddenInfo("hidden");
    builder->sender("Some sender");
    builder->recipientList(recipients);
    builder->content(contents);
    Letter* testLetter = builder->build();
    cout << testLetter->toString();
    cout << endl << "Build letter from director:" << endl;
    Director& dir = Director::getInstance();
    Letter* let1 = dir.makeRequiredLetter();
    cout << let1->toString() << endl;

    Letter* let2 = dir.makeFullLetter();
    cout << let2->toString() << endl;

    cout << "##########\t#######\t##########" << endl;

    delete recipients;
    delete contents;
    delete builder;
    delete testLetter;
    delete let1;
    delete let2;
}

void testPrototype() {
    cout << "##########\tPROTOTYPE\t##########" << endl;
    cout << "Create a empty letter: ";
    Letter* letter = new Letter();
    cout << letter->toString();

    cout << "Try a clone this letter to another" << endl;
    Letter* clone = letter->clone();
    cout << clone->toString();

    cout << "Add a hidden info to the first letter and lets out both letters" << endl;
    letter->setHiddenInfo("Prototype's pattern test");
    cout << "1. " << letter->toString();
    cout << "2. " << clone->toString();
    cout << "##########\t#########\t##########" << endl;

    delete letter;
    delete clone;
}

void testStates() {
    cout << "##########\tSTATE\t##########\n";
    cout << "Create a filter-training and get result from him" << endl;
    FilterTraining* ft = new FilterTraining();
    ft->printCurrentState();
    int result = ft->getResultsOfTraining();

    cout << endl << "Now change state to execute and try run algorithm" << endl;
    ft->changeStateTo(new ExecuteState);
    result = ft->getResultsOfTraining();
    cout << "##########\t#####\t##########\n";
}

void testStrategy() {
    cout << "##########\tSTRATEGY\t##########\n";
    cout << "Create algorithm based on the black-list:\n";
    Algorithm* alg1 = new BlackList();
    cout << alg1->runAlgorithm() << "\twhich means SPAM" << endl;
    cout << "Now change algorithm which based on the content filtering:" << endl;
    alg1 = new ContentFiltering();
    cout << alg1->runAlgorithm() << "\twhich means PROBABLY SPAM" << endl;
    cout << "##########\t########\t##########\n";
}

void testVisitor() {
    cout << "##########\tVISITOR\t##########" << endl;
    cout << "Get a JSON from default letter + some added content" << endl;
    Director& dir = Director::getInstance();
    Letter* letter = dir.makeRequiredLetter();
    letter->insertContent(new Audio("Shrek_2.mp3"));
    letter->insertContent(new Picture());
    Visitor* visitor = new JSONExportVisitor();
    string str = visitor->visit(letter);
    cout << "Our JSON: " << str << endl;
    cout << "##########\t#######\t##########" << endl;
}

void testMemento() {
    cout << "##########\tMEMENTO\t##########" << endl;
    cout << "Make config with test state and change it after saving" << endl;
    Config* cfg = new Config("test state");
    ConfigHistory* cfgHistory = new ConfigHistory(cfg);
    cfgHistory->save();
    cfg->changeState("changing state");
    cfgHistory->showHistory();
    cout << "Save new state and show history" << endl;
    cfgHistory->save();
    cfgHistory->showHistory();
    cout << "And we can make undo:" << endl;
    cfgHistory->undo();
    cfgHistory->showHistory();
    cout << "##########\t#######\t##########";
}

#endif // PATTERNS_TESTPATTERNS_H