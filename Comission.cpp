#include "Comission.h"
#include <cstring>
#include <iostream>

Comission::Comission() {

};
Comission::Comission(std::string comissionCode, std::string modality, int turn, int year, int fourthQuarter) {
    setComissionCode(comissionCode);
    setModality(modality);
    setTurn(turn);
    setYear(year);
    setFourthQuarter(fourthQuarter);
    setState(true);
};
std::string Comission::getComissionCode() const {
    return _comissionCode;
};
std::string Comission::getModality() const {
    return _modality;
};
int Comission::getTurn() const {
    return _turn;
};
int Comission::getYear() const {
    return _year;
};
int Comission::getFourthQuarter() const {
    return _fourthQuarter;
};
bool Comission::getState() const {
    return _state;
};
void Comission::setComissionCode(std::string comissionCode) {
    strcpy(_comissionCode, comissionCode.c_str());
};
void Comission::setModality(std::string modality) {
    strcpy(_modality, modality.c_str());
};
void Comission::setTurn(int turn) {
    _turn = turn;
};
void Comission::setYear(int year) {
    _year = year;
};
void Comission::setFourthQuarter(int fourthQuarter) {
    _fourthQuarter = fourthQuarter;
};
void Comission::setState(bool state) {
    _state = state;
};
void Comission::show(){
    std::cout << "CODIGO DE COMISION         : " << getComissionCode() << std::endl; 
    std::cout << "MODALIDAD                  : " << getModality() << std::endl;
    std::cout << "TURNO                      : " << getTurn() << std::endl;
    std::cout << "ANIO                       : " << getYear() << std::endl; 
    std::cout << "CUATRIMESTRE               : " << getFourthQuarter() << std::endl; 
};