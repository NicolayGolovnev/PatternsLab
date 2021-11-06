
//
// Created by kolya on 11/6/2021.
//

#ifndef PATTERNS_VISITABLECOLLECTION_H
#define PATTERNS_VISITABLECOLLECTION_H

#include "Visitor.h"

class VisitableCollection {
public:
    virtual std::string accept(Visitor* visitor) = 0;
};


#endif //PATTERNS_VISITABLECOLLECTION_H
