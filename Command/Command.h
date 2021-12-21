//
// Created by kolya on 12/19/2021.
//

#ifndef PATTERNS_COMMAND_H
#define PATTERNS_COMMAND_H


class Command {
public:
    virtual void execute() const = 0;
};


#endif //PATTERNS_COMMAND_H
