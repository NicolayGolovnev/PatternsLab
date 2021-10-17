//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_LETTER_H
#define PATTERNS_LETTER_H

#include <cstring>
#include <list>
#include "../Content/Content.h"

using namespace std;

class Letter{
private:
    string sender;
    list<string> recipientList;
    string hiddenInfo;
    string title;
    list<Content*> content;

public:

};

#endif //PATTERNS_LETTER_H
