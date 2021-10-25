//
// Created by kolya on 10/12/2021.
//

#ifndef PATTERNS_PROXYFILTER_H
#define PATTERNS_PROXYFILTER_H

#include "../System/Filter.h"
#include "../System/RealFilter.h"

class ProxyFilter : public Filter {
private:
    RealFilter* filter = NULL;
    void log(){
        printf("\n[ProxyLog]\tResult: ");
    }

public:
    ProxyFilter() {}
    ~ProxyFilter() {}
    void initFilter(RealFilter* inpFilter){
        if (filter != NULL)
            delete filter;
        filter = inpFilter;
    }
    int getResult() override {
        if (filter == NULL) {
            printf("Proxy filter didn't initialize!");
            return -1;
        }
        log();
        return filter->getResult();
    }
};

#endif //PATTERNS_PROXYFILTER_H
