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

#endif //PATTERNS_ADAPTER_H
