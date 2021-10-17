#include "../RealFilter.h"

RealFilter::RealFilter() {
    printf("Initiate filter: default\n");
    algorithm = new BlackList();
}

RealFilter::RealFilter(std::string init) {
    printf("Initiate filter: %s\n", init.c_str());
    if (strcmp(init.c_str(), (const char*)("BlackList")) == 0)
        algorithm = new BlackList();
    else if (strcmp(init.c_str(), (const char*)("ContentFiltering")) == 0)
        algorithm = new ContentFiltering();
    else if (strcmp(init.c_str(), (const char*)("AnalyzeMessageFields")) == 0)
        algorithm = new AnalyzeMessageFields();
}

void RealFilter::setAlgorithm(std::string setter) {
    analyzeAlgorithm = setter;
}

void RealFilter::getResult() {
    algorithm->runAlgorithm();
}