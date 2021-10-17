//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_DECORATORFILE_H
#define PATTERNS_DECORATORFILE_H

#include "../Content/Content.h"

class DecoratorFile : public Content {
protected:
    Content* content;
public:
    DecoratorFile(Content* content) : content(content) {}
    void getContent() override {
        content->getContent();
    }
};

#endif //PATTERNS_DECORATORFILE_H
