//
// Created by kolya on 12/19/2021.
//

#ifndef PATTERNS_MEMENTO_H
#define PATTERNS_MEMENTO_H


#include <string>
#include <utility>
#include <ctime>

class Memento {
private:
    std::string name;
    std::string date;

    int countOfLetters;
    std::string filterName;
    std::string state;
public:
    Memento(int cnt, std::string filterName, std::string state) {
        countOfLetters = cnt;
        this->filterName = filterName;
        this->state = state;

        std::time_t now = std::time(0);
        this->date = std::ctime(&now);
    }

    int getCountOfLetters() const {
        return countOfLetters;
    }

    const std::string &getFilterName() const {
        return filterName;
    }

    const std::string &getState() const {
        return state;
    }

    std::string getSnapshotDate() {
        return "Snapshot00-" + this->date + "/{state = " + state.substr(0, 9) + "...}/";
    }
};


#endif //PATTERNS_MEMENTO_H
