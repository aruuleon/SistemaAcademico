#include "Career.h"
#include <cstring>
#include <iostream>

Career::Career(){

};
Career::Career(std::string name, std::string studyType, int id, int duration) {
    setName(name);
    setStudyType(studyType);
    setId(id);
    setDuration(duration);
    setState(true);
};
std::string Career::getName() const {
    return _name;
};
int Career::getId() const {
    return _id;
};
std::string Career::getStudyType() const {
    return _studyType;
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
void Career::setId(int id) {
    _id = id;
};
void Career::setStudyType(std::string studyType) {
    strcpy(_studyType, studyType.c_str());
};
void Career::setDuration(int duration) {
    _duration = duration;
};
void Career::setState(bool state) {
    _state = state;
};
void Career::show(){
    std::cout << "NOMBRE: " << getName() << std::endl;
    std::cout << "TIPO DE ESTUDIO: " << getStudyType() << std::endl;
    // std::cout << "ID CARRERA: " << getId() << std::endl;
    std::cout << "DURACION: " << getDuration() << " ANIOS" << std::endl;
};