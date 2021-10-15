//
// Created by kolya on 10/12/2021.
//

#ifndef PATTERNS_FILTER_H
#define PATTERNS_FILTER_H

#include "Algorithm.h"
#include <string>

class Filter{
protected:
    Algorithm* algorithm;
public:
    Filter(){}

    virtual void getResult() {
        algorithm->runAlgorithm();
    }
};

#endif //PATTERNS_FILTER_H
