//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_DELEGATE_H
#define PATTERNS_DELEGATE_H

#include "../RealFilter.h"

void testDelegate() {
    std::printf("##########\tDELEGATION\t##########\n");
    RealFilter* rf1 = new RealFilter("ContentFiltering");
    rf1->getResult();

    RealFilter* rf2 = new RealFilter("AnalyzeMessageFields");
    rf2->getResult();

    RealFilter* rf3 = new RealFilter();
    rf3->getResult();

    std::printf("##########\t##########\t##########\n\n");

    delete rf1;
    delete rf2;
    delete rf3;
}

#endif //PATTERNS_DELEGATE_H
