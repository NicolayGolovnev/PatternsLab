//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_PICTURE_H
#define PATTERNS_PICTURE_H

#include "Content.h"

class Picture : public Content {
private:
    std::string value;
public:
    Picture() {
        value = "There can be a default picture";
    }
    Picture(std::string init) {
        value = init;
    }
    void getContent() override {
        std::printf("Picture: %s\n", value.c_str());
    }
};

#endif //PATTERNS_PICTURE_H
