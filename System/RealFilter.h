//
// Created by kolya on 10/11/2021.
//

#ifndef PATTERNS_REALFILTER_H
#define PATTERNS_REALFILTER_H

#include "Filter.h"
#include "../Delegation/Algorithms.h"

class RealFilter : public Filter {
private:
    std::string analyzeAlgorithm;
public:
    RealFilter() {
        analyzeAlgorithm = "default";
        printf("Initiate filter: %s\n", analyzeAlgorithm.c_str());
        algorithm = new BlackList();
    }
    RealFilter(std::string init) {
        analyzeAlgorithm = init;
        printf("Initiate filter: %s\n", analyzeAlgorithm.c_str());
        if (strcmp(init.c_str(), (const char*)("BlackList")) == 0)
            algorithm = new BlackList();
        else if (strcmp(init.c_str(), (const char*)("ContentFiltering")) == 0)
            algorithm = new ContentFiltering();
        else if (strcmp(init.c_str(), (const char*)("AnalyzeMessageFields")) == 0)
            algorithm = new AnalyzeMessageFields();
    }
    void setAlgorithm(std::string setter) { analyzeAlgorithm = setter; }
    void getResult() { algorithm->runAlgorithm(); }
};

#endif //PATTERNS_REALFILTER_H
