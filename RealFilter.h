//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_REALFILTER_H
#define PATTERNS_REALFILTER_H

#include <string>
#include "Algorithm.h"
#include "Algorithms.h"
#include "Filter.h"

using namespace std;

class RealFilter : public Filter {
private:
    string analyzeAlgorithm;
public:
    RealFilter();
    RealFilter(string init);
    void setAlgorithm(string setter);
    void getResult();
};

#endif //PATTERNS_REALFILTER_H
