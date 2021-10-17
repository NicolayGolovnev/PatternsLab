//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_ITERATORCONTENT_H
#define PATTERNS_ITERATORCONTENT_H

#include <vector>
#include "../Content/Content.h"
#include "../System/Letter.h"

class IteratorContent : public Iterator<Content*> {
private:
    std::vector<Content*>* collection;
    int cur;
public:
    IteratorContent(std::vector<Content*>* list) { collection = list; }
    ~IteratorContent() {}
    void first() override {
        cur = 0;
    }
    bool hasNext() override {
        return cur < collection->size();
    }
    void next() override {
        if (this->hasNext())
            cur++;
    }
    Content*& getCur() override {
        return collection->at(cur);
    }
};

#endif //PATTERNS_ITERATORCONTENT_H
