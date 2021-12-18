//
// Created by kolya on 12/19/2021.
//

#ifndef PATTERNS_CONFIG_H
#define PATTERNS_CONFIG_H


#include <string>
#include "../Memento/Memento.h"

class Config {
private:
    int countOfLetters;
    std::string filterName;
    std::string state;
public:
    Config(std::string initState) {
        state = initState;
        countOfLetters = 0;
        filterName = "";
    }

    void changeState(std::string change) {
        state = change;
    }

    Memento* save() {
        return new Memento(countOfLetters, filterName, state);
    }

    void restore(Memento* mem) {
        this->countOfLetters = mem->getCountOfLetters();
        this->filterName = mem->getFilterName();
        this->state = mem->getState();
    }

    std::string printState() {
        return "State of config - " + state;
    }

};


#endif //PATTERNS_CONFIG_H
