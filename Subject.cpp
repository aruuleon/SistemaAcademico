#include "Subject.h"
#include <cstring>
#include <iostream>

Subject::Subject() {

};
Subject::Subject(std::string name, std::string duration, int id, int yearCareer) {
    setName(name);
    setDuration(duration);
    setId(id);
    setCareerId(-1);
    setYearCareer(yearCareer);
    setState(true);
};
std::string Subject::getName() const {
    return _name;
};
int Subject::getId() const {
    return _id;
};
int Subject::getCareerId() const {
    return _careerId;
};
std::string Subject::getDuration() const {
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
void Subject::setId(int id) {
    _id = id;
};
void Subject::setCareerId(int careerId) {
    _careerId = careerId;
};
void Subject::setDuration(std::string duration) {
    strcpy(_duration, duration.c_str());
};
void Subject::setYearCareer(int yearCareer) {
    _yearCareer = yearCareer;
};
void Subject::setState(bool state) {
    _state = state;
};
void Subject::show(){
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "ID MATERIA     : " << getId() << std::endl;
    std::cout << "ID CARRERA     : " << getCareerId() << std::endl; 
    std::cout << "DURACION       : " << getDuration() << std::endl; 
};