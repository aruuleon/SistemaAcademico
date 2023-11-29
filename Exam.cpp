#include "Exam.h"
#include <string>
#include <iostream>
Exam::Exam(){
};
Exam::Exam(Fecha date, int grade, int id){
    setDate(date);
    setGrade(grade);
    setId(id);
    setState(true);
};
Fecha Exam::getDate() const{
    return _date;
};
int Exam::getGrade() const{
    return _grade;
};
int Exam::getId() const{
    return _id;
};
bool Exam::getState() const{
    return _state;
};
void Exam::setDate(Fecha date){
    _date = date;
};
void Exam::setGrade(int grade){
    _grade = grade;
};
void Exam::setId(int id){
    _id = id;
};
void Exam::setState(bool state){
    _state = state;
};
void Exam::show(){
    std::cout << "FECHA DE EXAMEN: " << getDate().toString() << std::endl;
    std::cout << "ID DE EXAMEN   : " << getId() << std::endl;
    std::cout << "NOTA DE EXAMEN : " << getGrade() << std::endl;
}