//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_ITERATOR_H
#define PATTERNS_ITERATOR_H

template <class T>
class Iterator {
    friend class IterableCollection;
public:
    virtual void next() = 0;
    virtual void first() = 0;
    virtual bool hasNext() = 0;
    virtual T& getCur() = 0;
};

#endif //PATTERNS_ITERATOR_H
