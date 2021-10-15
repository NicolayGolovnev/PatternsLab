//
// Created by kolya on 10/12/2021.
//

#ifndef PATTERNS_PROXYFILTER_H
#define PATTERNS_PROXYFILTER_H

#include "Filter.h"
#include "RealFilter.h"

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
    virtual void getResult(){
        log();
        filter->getResult();
    }
};

#endif //PATTERNS_PROXYFILTER_H
