//
// Created by kolya on 10/25/2021.
//

#ifndef PATTERNS_LETTERBUILDER_H
#define PATTERNS_LETTERBUILDER_H


#include <list>
#include "../System/Letter.h"
#include "Builder.h"

class LetterBuilder : public Builder<Letter*> {
private:
    Letter* letter;
    void builder() override { letter = new Letter(); }
public:
    LetterBuilder() { this->builder(); }
    ~LetterBuilder() { delete letter; }
    void sender(string sender) { letter->setSender(sender); }
    void recipientList(list<string>* recipients) {
        for (string recipient : *recipients)
            letter->addRecipient(recipient);
    }
    void hiddenInfo(string hiddenInfo) { letter->setHiddenInfo(hiddenInfo); }
    void title(string title) { letter->setTitle(title); }
    void content(vector<Content*>* contents) {
        for (Content* content : *contents)
            letter->insertContent(content);
    }
    Letter* build() override {
        return letter;
    }

};


#endif //PATTERNS_LETTERBUILDER_H
