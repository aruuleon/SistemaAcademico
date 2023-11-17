#include "Subject.h"
#include <cstring>
#include <iostream>

Subject::Subject() {

};
Subject::Subject(std::string name, int subjectId, int careerId, int duration) {
    setName(name);
    setSubjectId(subjectId);
    setCareerId(careerId);
    setDuration(duration);
    setState(true);
};
std::string Subject::getName() const {
    return _name;
};
int Subject::getSubjectId() const {
    return _subjectId;
};
int Subject::getCareerId() const {
    return _careerId;
};
int Subject::getDuration() const {
    return _duration;
};
int Subject::getyearCareer() const {
    return _yearCareer;
};
bool Subject::getState() const {
    return _state;
};
void Subject::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void Subject::setSubjectId(int subjectId) {
    _subjectId = subjectId;
};
void Subject::setCareerId(int careerId) {
    _careerId = careerId;
};
void Subject::setDuration(int duration) {
    _duration = duration;
};
void Subject::setYearCareer(int yearCareer) {
    _yearCareer = yearCareer;
};
void Subject::setState(bool state) {
    _state = state;
};
void Subject::show(){
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "ID MATERIA     : " << getSubjectId() << std::endl;
    std::cout << "ID CARRERA     : " << getCareerId() << std::endl; 
    std::cout << "DURACION       : " << getDuration() << std::endl; 
};