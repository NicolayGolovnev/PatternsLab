//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_DECORATORFILTER_H
#define PATTERNS_DECORATORFILTER_H


#include "../System/Filter.h"

class DecoratorFilter : public Filter {
protected:
    Filter* filter;
public:
    DecoratorFilter(Filter* fl) : filter(fl) {}
    int getResult() override {
        return filter->getResult();
    }

};

#endif //PATTERNS_DECORATORFILTER_H
