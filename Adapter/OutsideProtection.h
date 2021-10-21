//
// Created by kolya on 10/17/2021.
//

#ifndef PATTERNS_OUTSIDEPROTECTION_H
#define PATTERNS_OUTSIDEPROTECTION_H

#include <cstring>

class OutsideProtection {
private:
    std::string source;
    std::string email;

public:
    OutsideProtection() { source = "none"; email = "none@none.none";}
    OutsideProtection(std::string _source, std::string _email) {
        source = _source;
        email = _email;
    }
    OutsideProtection(OutsideProtection* protection) { source = protection->source; email = protection->email; }
    ~OutsideProtection() {}

    std::string getSource() { return source; }
    void setEmail(std::string _email) { email = _email; }

    std::string runProtection() {
        std::printf("Initial protocol of protect: source - %s,\temail - %s\n", source.c_str(), email.c_str());
        std::printf("Running...\n");
        std::printf("Running...38\n");
        std::printf("Running...72\n");
        std::printf("Running...91\n");
        std::printf("Running...99\n");
        std::printf("Analyzing complete: source is protected!\n");
        return "Source is protected!";
    }
};

#endif //PATTERNS_OUTSIDEPROTECTION_H
