#include <cstring>
#include "System.h"

System::System() {

};
System::System(std::string name) {
    setName(name);
};
std::string System::getName() const {
    return _name;
};
void System::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void System::runProgram() {

};