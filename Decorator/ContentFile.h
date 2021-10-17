//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_CONTENTFILE_H
#define PATTERNS_CONTENTFILE_H

#include <cstdio>
#include "DecoratorFile.h"

class ContentFile : public DecoratorFile {
private:
    int size;
public:
    ContentFile(Content* content) : DecoratorFile(content) {
        size = 0;
    }
    ContentFile(Content* content, int inpSize) : DecoratorFile(content) {
        size = inpSize;
    }
    void getContent() {
        std::printf("ContentFile[size = %d]:\t", size);
        DecoratorFile::getContent();
    }
};

#endif //PATTERNS_CONTENTFILE_H
