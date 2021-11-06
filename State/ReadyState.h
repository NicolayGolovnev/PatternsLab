//
// Created by kolya on 11/3/2021.
//

#ifndef PATTERNS_READYSTATE_H
#define PATTERNS_READYSTATE_H


#include "State.h"

class ReadyState : public State {
public:
    bool start(FilterTraining* filterTraining) override ;
    bool stop(FilterTraining* filterTraining) override ;
};


#endif //PATTERNS_READYSTATE_H
