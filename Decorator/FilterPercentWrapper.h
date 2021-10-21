//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_FILTERPERCENTWRAPPER_H
#define PATTERNS_FILTERPERCENTWRAPPER_H

#include <cstdio>
#include "DecoratorFilter.h"
#include <list>

class FilterPercentWrapper : public DecoratorFilter {
private:
    std::string percent;
public:
    FilterPercentWrapper(Filter* filter) : DecoratorFilter(filter) {
        percent = "0";
    }
    int getResult() override {
        int result = DecoratorFilter::getResult();
        switch (result){
            case SPAM: percent = "90 - 100"; break;
            case PROBABLY: percent = "65 - 90"; break;
            case MAYBE: percent = "40 - 65"; break;
            case SMALL: percent = "18 - 40"; break;
            case NOT_SPAM: percent = "0 - 18"; break;
        }
        std::printf("FilterPercentWrapper: percents = %s\n", percent.c_str());

        return result;
    }
};

#endif //PATTERNS_FILTERPERCENTWRAPPER_H
