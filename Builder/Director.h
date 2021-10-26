//
// Created by kolya on 10/26/2021.
//

#ifndef PATTERNS_DIRECTOR_H
#define PATTERNS_DIRECTOR_H


#include <iostream>
#include "Builder.h"
#include "../System/Letter.h"
#include "LetterBuilder.h"
#include "../Content/Text.h"
#include "../Content/Picture.h"

class Director {
private:
//    static Director* instance;
//    Builder<Letter*>* builderLetter;
    Director() {}
    Director(const Director&);
    Director& operator=(Director&);
public:
    ~Director() {}
    static Director& getInstance() {
        static Director instance;
        cout << "Return a instance of director" << endl;
        return instance;
    }

    Letter* makeRequiredLetter() {
        LetterBuilder* letterBuilder = new LetterBuilder();
        letterBuilder->sender("Required sender");
        letterBuilder->recipientList(new list<string>{"recipient1", "recipient2", "recipient3"});
        letterBuilder->title("Required title");
        letterBuilder->content(new vector<Content*>{new Text("Required text")});
        return letterBuilder->build();
    }

    Letter* makeFullLetter() {
        LetterBuilder* letterBuilder = new LetterBuilder();
        letterBuilder->sender("Required sender");
        letterBuilder->hiddenInfo("There some hidden information");
        letterBuilder->recipientList(new list<string>{"recipient1"});
        letterBuilder->title("Required title");
        letterBuilder->content(new vector<Content*>{new Text("Required text"), new Picture()});
        return letterBuilder->build();
    }
};


#endif //PATTERNS_DIRECTOR_H
