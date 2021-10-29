//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_CONTENT_H
#define PATTERNS_CONTENT_H

#include <string>
#include "../Prototype/ClonableCollection.h"

class Content : public ClonableCollection {
public:
    virtual std::string getContent() = 0;
    virtual Content* clone() = 0;
};

#endif //PATTERNS_CONTENT_H
