//
// Created by kolya on 12/19/2021.
//

#ifndef PATTERNS_CONFIGHISTORY_H
#define PATTERNS_CONFIGHISTORY_H


#include <vector>
#include <iostream>
#include "Memento.h"
#include "../System/Config.h"

class ConfigHistory {
private:
    Config* config;
    std::vector<Memento*> history;
public:
    ConfigHistory(Config* config) {
        this->config = config;
    }

    void save() {
        this->history.push_back(this->config->save());
    }

    void undo() {
        if (!this->history.size())
            return;
        Memento* memento = this->history.back();
        this->history.pop_back();
        this->config->restore(memento);
    }

    void showHistory() const {
        std::cout << "List of config's history:\n";
        for (Memento* memento : this->history) {
            std::cout << "\t" << memento->getSnapshotDate() << "\n";
        }
    }
};


#endif //PATTERNS_CONFIGHISTORY_H
