//
// Created by kolya on 10/12/2021.
//

#ifndef PATTERNS_FILTER_H
#define PATTERNS_FILTER_H

#include "../Delegation/Algorithm.h"

class Filter{
protected:
    Algorithm* algorithm;
public:
    Filter(){}
    ~Filter() {}

    virtual int getResult() {
        return algorithm->runAlgorithm();
    }
//    virtual std::string getAlgorithm() {}
};

#endif //PATTERNS_FILTER_H
