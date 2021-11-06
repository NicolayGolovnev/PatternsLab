//
// Created by kolya on 11/3/2021.
//

#ifndef PATTERNS_STATE_H
#define PATTERNS_STATE_H

#include "../System/FilterTraining.h"
class FilterTraining;

class State {
public:
    virtual bool start(FilterTraining* filterTraining) = 0;
    virtual bool stop(FilterTraining* filterTraining) = 0;
};

#endif //PATTERNS_STATE_H
