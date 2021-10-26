//
// Created by kolya on 10/25/2021.
//

#ifndef PATTERNS_BUILDER_H
#define PATTERNS_BUILDER_H


template <class T>
class Builder {
public:
    Builder() {}
    ~Builder() {}
    virtual void builder() = 0;
    virtual T build() = 0;
};


#endif //PATTERNS_BUILDER_H
