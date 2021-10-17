//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_TEXT_H
#define PATTERNS_TEXT_H

#include "Content.h"

class Text : public Content {
private:
    std::string value;
public:
    Text() {
        value = "There can be a default audio file";
    }
    Text(std::string init) {
        value = init;
    }
    void getContent() override {
        std::printf("Text: %s\n", value.c_str());
    }
};

#endif //PATTERNS_TEXT_H
