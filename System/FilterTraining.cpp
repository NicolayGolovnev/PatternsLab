//
// Created by kolya on 11/4/2021.
//

#include <vector>
#include <iostream>
#include "FilterTraining.h"
#include "../State/InitState.h"

FilterTraining::FilterTraining() {
    state = new InitState();
    sample = "default";
    resultsOfTraining = new std::vector<int>();
    trainingAlgorithm = "unknown";
    filter = new RealFilter();
    state->stop(this);
}

void FilterTraining::changeStateTo(State *state1) {
    std::cout << "Change state to " << typeid(*state1).name() << std::endl;
    if (this->state != nullptr)
        delete this->state;
    this->state = state1;
}

void FilterTraining::executeTraining() {
    int result = filter->getResult();
    resultsOfTraining->push_back(result);
}

int FilterTraining::getResultsOfTraining() {
    if (!state->start(this)) {
        std::cout << "Could not run a training module - he is already running" << std::endl;
        return -1;
    }
    else {
        // Не выполняем, так как мы уже запустили выполнение алгоритма
        //state->start(this);
        this->executeTraining();
        state->stop(this);
        return resultsOfTraining->back();
    }
}

void FilterTraining::printCurrentState() {
    std::cout << "Current state is " << typeid(*state).name() << std::endl;
}