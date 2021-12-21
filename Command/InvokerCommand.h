//
// Created by kolya on 12/21/2021.
//

#ifndef PATTERNS_INVOKERCOMMAND_H
#define PATTERNS_INVOKERCOMMAND_H


#include "Command.h"

class InvokerCommand {
private:
    Command* command;
public:
    void setCommand(Command* cmd) {
        command = cmd;
    }
    void executeCommand() {
        command->execute();
    }
};


#endif //PATTERNS_INVOKERCOMMAND_H
