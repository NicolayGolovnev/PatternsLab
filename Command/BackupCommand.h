//
// Created by kolya on 12/21/2021.
//

#ifndef PATTERNS_BACKUPCOMMAND_H
#define PATTERNS_BACKUPCOMMAND_H


#include "Command.h"
#include "../Memento/ConfigHistory.h"

class BackupCommand : public Command {
private:
    ConfigHistory* history;
public:
    BackupCommand(ConfigHistory* cfg) {
        history = cfg;
    }

    void execute() const override {
        history->save();
    }
};


#endif //PATTERNS_BACKUPCOMMAND_H
