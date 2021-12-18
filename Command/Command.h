//
// Created by kolya on 12/19/2021.
//

#ifndef PATTERNS_COMMAND_H
#define PATTERNS_COMMAND_H


#include "../Memento/Memento.h"
#include "../System/Config.h"

class Command {
private:
    Memento* backup;
public:
    void makeBackup(Config* cfg) {
        backup = cfg->save();
    }

    void undo(Config* cfg) {
        if (backup != nullptr)
            cfg->restore(backup);
        else
            std::cout << "Cannot find a config file for backup" << std::endl;
    }
};


#endif //PATTERNS_COMMAND_H
