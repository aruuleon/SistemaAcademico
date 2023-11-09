#include "Career.h"
#include <cstring>

Career::Career(){

};
Career::Career(std::string name, int careerId, int studioType, int duration) {
    setName(name);
    setCareerId(careerId);
    setStudioType(studioType);
    setDuration(duration);
    setState(true);
};
std::string Career::getName() const {
    return _name;
};
int Career::getCareerId() const {
    return _careerId;
};
int Career::getStudioType() const {
    return _studioType;
};
int Career::getDuration() const {
    return _duration;
};
bool Career::getState() const {
    return _state;
};
void Career::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void Career::setCareerId(int careerId) {
    _careerId = careerId;
};
void Career::setStudioType(int studioType) {
    _studioType = studioType;
};
void Career::setDuration(int duration) {
    _duration = duration;
};
void Career::setState(bool state) {
    _state = state;
};