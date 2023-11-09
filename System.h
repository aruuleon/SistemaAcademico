#pragma once
#include <string>

class System {
    private:
        char _name[20];
    public:
        System();
        System(std::string);
        std::string getName() const;
        void setName(std::string);
        void runProgram();
};