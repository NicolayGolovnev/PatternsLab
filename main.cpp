#include <iostream>
#include "RealFilter.h"
#include "ProxyFilter.h"

void testDelegate(){
    RealFilter* rf1 = new RealFilter("ContentFiltering");
    rf1->getResult();

    RealFilter* rf2 = new RealFilter("AnalyzeMessageFields");
    rf2->getResult();

    RealFilter* rf3 = new RealFilter();
    rf3->getResult();

    delete rf1;
    delete rf2;
    delete rf3;
}

void testProxy(){
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
}

int main() {
    testProxy();
    return 0;
}
