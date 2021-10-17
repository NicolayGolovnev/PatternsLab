//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_COMPOSITE_H
#define PATTERNS_COMPOSITE_H

#include <list>
#include "Component.h"

class Composite : public Component{
protected:
    std::list<Component*> child;
public:
    void add(Component* component) override {
        this->child.push_back(component);
        component->setParent(this);
    }
    void remove(Component* component) override {
        child.remove(component);
        component->setParent(NULL);
    }
    bool isComposite() override { return true; }
    std::string operation() override {
        std::string result = "";
        for (Component* c : child) {
            if (c == child.back())
                result += c->operation();
            else
                result += c->operation() + "+";
        }
        return "Group(" + result + ")";
    }
};

#endif //PATTERNS_COMPOSITE_H
