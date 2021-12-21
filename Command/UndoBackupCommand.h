//
// Created by kolya on 12/21/2021.
//

#ifndef PATTERNS_UNDOBACKUPCOMMAND_H
#define PATTERNS_UNDOBACKUPCOMMAND_H


#include "Command.h"
#include "../Memento/ConfigHistory.h"

class UndoBackupCommand : public Command {
private:
    ConfigHistory* history;
public:
    UndoBackupCommand(ConfigHistory* cfg) {
        history = cfg;
    }
    void execute() const override {
        history->undo();
    }

};


#endif //PATTERNS_UNDOBACKUPCOMMAND_H
