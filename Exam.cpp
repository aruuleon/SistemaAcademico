#include "Exam.h"
#include <string>
#include <iostream>
Exam::Exam(){
};
Exam::Exam(int id, Fecha date){
    setId(id);
    setDate(date);
    setState(true);
};
int Exam::getId() const{
    return _id;
};
Fecha Exam::getDate() const{
    return _date;
};
bool Exam::getState() const{
    return _state;
};
void Exam::setId(int id){
    _id = id;
};
void Exam::setDate(Fecha date){
    _date = date;
};
void Exam::setState(bool state){
    _state = state;
};
void Exam::show(){
    std::cout << "FECHA DE EXAMEN: " << getDate().toString() << std::endl;
    std::cout << "ID DE EXAMEN   : " << getId() << std::endl;
}