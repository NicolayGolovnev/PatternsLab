//
// Created by kolya on 10/26/2021.
//

#ifndef PATTERNS_CLONABLECOLLECTION_H
#define PATTERNS_CLONABLECOLLECTION_H

class ClonableCollection {
public:
    virtual ClonableCollection* clone() = 0;
};


#endif //PATTERNS_CLONABLECOLLECTION_H
