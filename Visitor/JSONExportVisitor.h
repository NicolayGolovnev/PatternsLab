//
// Created by kolya on 11/6/2021.
//

#ifndef PATTERNS_JSONEXPORTVISITOR_H
#define PATTERNS_JSONEXPORTVISITOR_H

#include <list>
#include "Visitor.h"
#include "../Content/Audio.h"
#include "../Content/Picture.h"
#include "../Content/Text.h"

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

class JSONExportVisitor : public Visitor {
public:
    string visit(Letter *letter) override {
        string result = "{\"sender\":\"" + letter->getSender() + "\",";
        result += "\"recipientList\":[";
        list<string>* list = letter->getRecipientList();
        for (auto str : *list){
            result += "\"" + str + "\",";
        }
        result.pop_back(); result += "],";
        result += "\"hiddenInfo\":\"" + letter->getHiddenInfo() + "\",";
        result += "\"title\":\"" + letter->getTitle() + "\",";
        result += "\"content\":[";
        auto vctr = letter->getContent();
        for (Content* content : *vctr){
            result += "{";
            if (instanceof<Audio>(content))
                result += "\"audioValue\":\"" + content->getContent() + "\"";
            else if (instanceof<Picture>(content))
                result += "\"pictureValue\":\"" + content->getContent() + "\"";
            else if (instanceof<Text>(content))
                result += "\"textValue\":\"" + content->getContent() + "\"";
            result += "},";
        }
        result.pop_back(); result += "]}";
        return result;
    }

};


#endif //PATTERNS_JSONEXPORTVISITOR_H
