//
// Created by kolya on 11/3/2021.
//

#ifndef PATTERNS_FILTERTRAINING_H
#define PATTERNS_FILTERTRAINING_H

using namespace std;

#include <string>
#include <vector>
#include "../State/State.h"
#include "RealFilter.h"
#include <typeinfo>

class State;

class FilterTraining {
private:
    State* state;
    string sample;
    std::vector<int>* resultsOfTraining;
    string trainingAlgorithm;
    RealFilter* filter;
public:
    FilterTraining();
    void changeStateTo(State* state1);
    void executeTraining();
    int getResultsOfTraining();
    void printCurrentState();
};


#endif //PATTERNS_FILTERTRAINING_H
