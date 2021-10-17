//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_LETTER_H
#define PATTERNS_LETTER_H

#include <string>
#include "../Content/Content.h"
#include "../Iterator/IterableCollection.h"
#include "../Iterator/IteratorContent.h"

using namespace std;

class Letter : public IterableCollection{
private:
    string sender;
    vector<string>* recipientList;
    string hiddenInfo;
    string title;
    vector<Content*>* content;
public:
    Letter() {
        sender = "none";
        recipientList = NULL;
        hiddenInfo = "";
        title = "test";
        content = new vector<Content*>();
    }
    void insertContent(Content* content1) {
        content->push_back(content1);
    }
    Iterator<Content*>* createIterator() override {
        return new IteratorContent(content);
    }
};

#endif //PATTERNS_LETTER_H
