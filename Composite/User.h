//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_USER_H
#define PATTERNS_USER_H

#include "Component.h"

class User : public Component {
private:
    std::string login;
    std::string privilege;
public:
    User(std::string login, std::string privilege) {
        this->login = login;
        this->privilege = privilege;
    }
    std::string operation() override {
        return "User[login = " + login + ", privilege = " + privilege + "]";
    }
};


#endif //PATTERNS_USER_H
