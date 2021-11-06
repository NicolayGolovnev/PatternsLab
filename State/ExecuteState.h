//
// Created by kolya on 11/3/2021.
//

#ifndef PATTERNS_EXECUTESTATE_H
#define PATTERNS_EXECUTESTATE_H


#include "State.h"

class ExecuteState : public State {
public:
    bool start(FilterTraining* filterTraining) override ;
    bool stop(FilterTraining* filterTraining) override ;
};


#endif //PATTERNS_EXECUTESTATE_H
