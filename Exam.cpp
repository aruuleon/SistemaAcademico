#include "Exam.h"
#include <string>
#include <iostream>
Exam::Exam(){
};
Exam::Exam(int id, int grade, Fecha date){
    setId(id);
    setGrade(grade);
    setDate(date);
    setState(true);
};
int Exam::getGrade() const{
    return _grade;
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
void Exam::setGrade(int grade){
    _grade = grade;
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
    std::cout << "NOTA DE EXAMEN : " << getGrade() << std::endl;
}