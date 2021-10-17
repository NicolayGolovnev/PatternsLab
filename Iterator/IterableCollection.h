//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_ITERABLECOLLECTION_H
#define PATTERNS_ITERABLECOLLECTION_H

#include "Iterator.h"

class IterableCollection {
public:
    virtual Iterator<Content*>* createIterator() = 0;
};


#endif //PATTERNS_ITERABLECOLLECTION_H
