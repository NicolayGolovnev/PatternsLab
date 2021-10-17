//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_PROXY_H
#define PATTERNS_PROXY_H

#include "../System/RealFilter.h"
#include "ProxyFilter.h"

void testProxy() {
    std::printf("\a##########\tPROXY\t##########\n");
    RealFilter* filter1 = new RealFilter("ContentFiltering");
    ProxyFilter* proxyFilter = new ProxyFilter();

    printf("\nFilter: ");
    filter1->getResult();
    printf("Proxy filter: ");
    proxyFilter->getResult();

    printf("\nGet results from another (not default) filter with proxy.\n\n");
    proxyFilter->initFilter(filter1);
    printf("Filter: ");
    filter1->getResult();
    printf("Proxy filter: ");
    proxyFilter->getResult();
    std::printf("##########\t#####\t##########\n\n");

    delete filter1;
    delete proxyFilter;
}

#endif //PATTERNS_PROXY_H
