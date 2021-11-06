//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_AUDIO_H
#define PATTERNS_AUDIO_H

#include "Content.h"

class Audio : public Content {
private:
    std::string value;
public:
    Audio() {
        value = "There can be a default audio file";
    }
    Audio(std::string init) {
        value = init;
    }
    std::string getContent() override {
        return value;
    }
    Audio* clone() override { return new Audio(*this); }
};

#endif //PATTERNS_AUDIO_H
