//
// Created by kolya on 10/21/2021.
//

#ifndef PATTERNS_FILTERRECOMENDATIONWRAPPER_H
#define PATTERNS_FILTERRECOMENDATIONWRAPPER_H


#include "DecoratorFilter.h"
#include "../System/FilterResult.h"

class FilterRecomendationWrapper : public DecoratorFilter {
private:
    std::string recomendation;
public:
    FilterRecomendationWrapper(Filter* filter) : DecoratorFilter(filter) {
        recomendation = "none";
    }
    int getResult() override {
        int result = DecoratorFilter::getResult();
        switch (result){
            case SPAM: recomendation = "This is a spam"; break;
            case PROBABLY: recomendation = "This is a probably spam"; break;
            case MAYBE: recomendation = "This is a maybe spam"; break;
            case SMALL: recomendation = "Chance of being spam is extremely small"; break;
            case NOT_SPAM: recomendation = "No recomendation - not spam"; break;
        }
        std::printf("FilterRecomendationWrapper: recomendation = %s\n", recomendation.c_str());

        return result;
    }
};


#endif //PATTERNS_FILTERRECOMENDATIONWRAPPER_H
