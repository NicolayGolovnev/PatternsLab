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
    std::string getContent() override {
        return "Picture: " + value + "\n";
    }
    Picture* clone() override { return new Picture(*this); }
};

#endif //PATTERNS_PICTURE_H
