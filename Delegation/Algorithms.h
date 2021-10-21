//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_ALGORITHMS_H
#define PATTERNS_ALGORITHMS_H

#include <cstdio>
#include "Algorithm.h"
#include "../System/FilterResult.h"

class BlackList : public Algorithm {
public:
    int runAlgorithm() override {
        printf("BlackList algorithm - running!\n");
        return SPAM;
    }
};

class ContentFiltering : public Algorithm {
public:
    int runAlgorithm() override {
        printf("Content filtering algorithm - running!\n");
        return PROBABLY;
    }
};

class AnalyzeMessageFields : public Algorithm {
public:
    int runAlgorithm() override {
        printf("Analyze message fields algorithm - running!\n");
        return NOT_SPAM;
    }
};

#endif //PATTERNS_ALGORITHMS_H
