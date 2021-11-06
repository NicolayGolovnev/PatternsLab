//
// Created by kolya on 11/4/2021.
//

#include <iostream>
#include "State.h"
#include "InitState.h"
#include "ReadyState.h"
#include "ExecuteState.h"

bool InitState::start(FilterTraining *filterTraining) {
    std::cout << "Start of initialize a FilterTraining" << std::endl;
    return true;
}

bool InitState::stop(FilterTraining *filterTraining) {
    std::cout << "Initialize of FilterTraining is successes" << std::endl;
    filterTraining->changeStateTo(new ReadyState);
    return true;
}

bool ReadyState::start(FilterTraining *filterTraining) {
    std::cout << "Start of execute a FilterTraining" << std::endl;
    filterTraining->changeStateTo(new ExecuteState);
    return true;
}

bool ReadyState::stop(FilterTraining *filterTraining) {
    std::cout << "Error: could not stop a FilterTraining" << std::endl;
    return false;
}

bool ExecuteState::start(FilterTraining *filterTraining) {
    std::cout << "Error: could not start a FilterTraining" << std::endl;
    return false;
}

bool ExecuteState::stop(FilterTraining *filterTraining) {
    std::cout << "Execute of FilterTraining is successes" << std::endl;
    std::cout << "Stop of executing..." << std::endl;
    filterTraining->changeStateTo(new ReadyState);
    return true;
}