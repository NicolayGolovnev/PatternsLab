//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_COMPONENT_H
#define PATTERNS_COMPONENT_H

#include <string>

class Component {
protected:
    Component* parent;
public:
    virtual ~Component() {}
    void setParent(Component* iparent) { this->parent = iparent; }
    Component* getParent() { return this->parent; }
    virtual void add(Component* component) {}
    virtual void remove(Component* component) {}
    virtual bool isComposite() { return false; }
    virtual std::string operation() = 0;
};

#endif //PATTERNS_COMPONENT_H
