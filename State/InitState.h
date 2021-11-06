//
// Created by kolya on 11/3/2021.
//

#ifndef PATTERNS_INITSTATE_H
#define PATTERNS_INITSTATE_H


#include "State.h"

class InitState : public State {
public:
    bool start(FilterTraining* filterTraining) override ;
    bool stop(FilterTraining* filterTraining) override ;
};

#endif //PATTERNS_INITSTATE_H
