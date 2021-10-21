//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_ADAPTER_H
#define PATTERNS_ADAPTER_H

#include "OutsideProtection.h"
#include "../System/Filter.h"

class Adapter : public Filter {
private:
    OutsideProtection* adaptable;
    int initProtect() {
        std::printf("Initial protocol of initProtect: source - %s,\temail - [DATA DELETED]\n", adaptable->getSource().c_str());
        std::printf("Inititial run of outside protection - Initial complete\n");
        if (adaptable->runProtection() == "Source is protected!")
            return 200;
        else
            return 404;
    }
public:
    Adapter() { adaptable = new OutsideProtection(); }
    Adapter(OutsideProtection* protection) { adaptable = protection; }
    ~Adapter() { delete adaptable; }

    int getResult() override {
        return this->initProtect();
    }

};

void testAdapter() {
    std::printf("##########\tADAPTER\t##########\n");
    OutsideProtection* protection1 = new OutsideProtection();
    std::printf("Run protection1 without source and email\n");
    protection1->runProtection();

    std::printf("Run filter1 by protection1\n");
    Filter* filter1 = new Adapter(protection1);
    filter1->getResult();

    OutsideProtection* protection2 = new OutsideProtection("my source", "test@test.test");
    std::printf("\nRun protection2 with source and email\n");
    protection2->runProtection();

    std::printf("Run filter2 by protection2\n");
    Filter* filter2 = new Adapter(protection2);
    filter2->getResult();
    std::printf("##########\t#######\t##########\n");
}

#endif //PATTERNS_ADAPTER_H
