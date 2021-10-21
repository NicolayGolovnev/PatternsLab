//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_DECORATOR_H
#define PATTERNS_DECORATOR_H

#include "FilterPercentWrapper.h"
#include "../System/RealFilter.h"
#include "FilterRecomendationWrapper.h"

void testDecoratorFilter() {
    std::printf("Made a 2 default filter: BlackList and ContentFiltering\n");
    Filter* blackListFilter = new RealFilter("BlackList");
    blackListFilter->getResult();
    Filter* contentFilteringFilter = new RealFilter("ContentFiltering");
    contentFilteringFilter->getResult();

    std::printf("\nNow made decorators for this filters\n");
    Filter* decorator1 = new FilterPercentWrapper(new FilterRecomendationWrapper(blackListFilter));
    decorator1->getResult();
    Filter* decorator2 = new FilterPercentWrapper(new FilterRecomendationWrapper(contentFilteringFilter));
    decorator2->getResult();
}

#endif //PATTERNS_DECORATOR_H
