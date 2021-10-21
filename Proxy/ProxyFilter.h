//
// Created by kolya on 10/12/2021.
//

#ifndef PATTERNS_PROXYFILTER_H
#define PATTERNS_PROXYFILTER_H

#include "../System/Filter.h"
#include "../System/RealFilter.h"

class ProxyFilter : public Filter {
private:
    RealFilter* filter;
    void log(){
        printf("\n[ProxyLog]\tResult: ");
    }

public:
    ProxyFilter(){
        filter = new RealFilter();
    }
    void initFilter(RealFilter* inpFilter){
        if (filter != NULL)
            delete filter;
        filter = inpFilter;
    }
    virtual int getResult() override {
        log();
        return filter->getResult();
    }
};

#endif //PATTERNS_PROXYFILTER_H
