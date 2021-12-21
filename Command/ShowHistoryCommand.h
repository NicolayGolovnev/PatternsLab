//
// Created by kolya on 12/21/2021.
//

#ifndef PATTERNS_SHOWHISTORYCOMMAND_H
#define PATTERNS_SHOWHISTORYCOMMAND_H


#include "Command.h"
#include "../Memento/ConfigHistory.h"

class ShowHistoryCommand : public Command {
private:
    ConfigHistory* history;
public:
    ShowHistoryCommand(ConfigHistory* cfg) {
        history = cfg;
    }

    void execute() const override {
        history->showHistory();
    }
};


#endif //PATTERNS_SHOWHISTORYCOMMAND_H
