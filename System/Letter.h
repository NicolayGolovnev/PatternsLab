//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_LETTER_H
#define PATTERNS_LETTER_H

#include <string>
#include "../Content/Content.h"
#include "../Iterator/IterableCollection.h"
#include "../Iterator/IteratorContent.h"
#include "../Prototype/ClonableCollection.h"
#include "../Visitor/VisitableCollection.h"

using namespace std;

class Letter : public IterableCollection, public ClonableCollection, public VisitableCollection {
private:
    string sender;
    list<string>* recipientList;
    string hiddenInfo;
    string title;
    vector<Content*>* content;
public:
    Letter() {
        sender = "none";
        recipientList = new list<string>();
        hiddenInfo = "none";
        title = "Empty letter";
        content = new vector<Content*>();
    }
    Letter(Letter& sample) {
        sender = sample.sender;
        recipientList = new list<string>();
        *recipientList = *(sample.recipientList);
        hiddenInfo = sample.hiddenInfo;
        title = sample.title;
        content = new vector<Content*>();
        for (Content* varContent : *(sample).content)
            content->push_back(varContent->clone());
//        *content = *(sample.content);
    }
//    ~Letter() { delete recipientList; delete content; }
    void addRecipient(string recipient) {
        if (recipientList == NULL)
            recipientList = new list<string>();
        recipientList->push_back(recipient);
    }
    void setSender(string _sender) { sender = _sender; }
    void setHiddenInfo(string info) { hiddenInfo = info; }
    void setTitle(string _title) { title = _title; }
    void insertContent(Content* content1) {
        content->push_back(content1);
    }
    Iterator<Content*>* createIterator() override {
        return new IteratorContent(content);
    }
    string toString() {
        string listRec = "", listCont = "\n";
        for (string s : *recipientList)
            listRec += s + " ";
        for (Content* c : *content)
            listCont += c->getContent();
        return "Letter[\n\tsender=" + sender + "\n\trecipients=" + listRec + "\n\thiddenInfo=" + hiddenInfo +
            "\n\ttitle=" + title + "\n\tcontents=" + listCont + "]\n";
    }

    Letter* clone() override { return new Letter(*this); }

    const string &getSender() const { return sender; }

    list<string> *getRecipientList() const { return recipientList; }

    const string &getHiddenInfo() const { return hiddenInfo; }

    const string &getTitle() const { return title; }

    vector<Content *> *getContent() const { return content; }

    std::string accept(Visitor *visitor) override { return visitor->visit(this); }
};

#endif //PATTERNS_LETTER_H
