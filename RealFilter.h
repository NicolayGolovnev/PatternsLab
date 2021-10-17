//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_REALFILTER_H
#define PATTERNS_REALFILTER_H

#include "Filter.h"
#include "Delegation/Algorithms.h"

class RealFilter : public Filter {
private:
    std::string analyzeAlgorithm;
public:
    RealFilter();
    RealFilter(std::string init);
    void setAlgorithm(std::string setter);
    void getResult();
};

#endif //PATTERNS_REALFILTER_H
