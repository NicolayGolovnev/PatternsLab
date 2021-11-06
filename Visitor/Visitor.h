//
// Created by kolya on 11/6/2021.
//

#ifndef PATTERNS_VISITOR_H
#define PATTERNS_VISITOR_H


#include "../System/Letter.h"

class Letter;

class Visitor {
public:
    virtual std::string visit(Letter* letter) = 0;
};


#endif //PATTERNS_VISITOR_H
