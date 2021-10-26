//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_COMPONENT_H
#define PATTERNS_COMPONENT_H

#include <string>

class Component {
public:
    virtual ~Component() {}
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual bool isComposite() { return false; }
    virtual std::string operation() = 0;
};

#endif //PATTERNS_COMPONENT_H
