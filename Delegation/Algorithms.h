//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_ALGORITHMS_H
#define PATTERNS_ALGORITHMS_H

#include <cstdio>
#include "Algorithm.h"

class BlackList : public Algorithm {
public:
    void runAlgorithm() override {
        printf("BlackList algorithm - running!\n");
    }
};

class ContentFiltering : public Algorithm {
public:
    void runAlgorithm() override {
        printf("Content filtering algorithm - running!\n");
    }
};

class AnalyzeMessageFields : public Algorithm {
public:
    void runAlgorithm() override {
        printf("Analyze message fields algorithm - running!\n");
    }
};

#endif //PATTERNS_ALGORITHMS_H
