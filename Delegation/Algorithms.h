//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_ALGORITHMS_H
#define PATTERNS_ALGORITHMS_H

#include <cstdio>
#include "Algorithm.h"

class BlackList : public Algorithm {
public:
    void runAlgorithm();
};

class ContentFiltering : public Algorithm {
public:
    void runAlgorithm();
};

class AnalyzeMessageFields : public Algorithm {
public:
    void runAlgorithm();
};

#endif //PATTERNS_ALGORITHMS_H
