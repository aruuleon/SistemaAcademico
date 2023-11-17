#include <iostream>
#include <cstring>
#include "FacultyStaff.h"

FacultyStaff::FacultyStaff() {

};
FacultyStaff::FacultyStaff(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType) {
    Person:Person(name, surname, document);
    setEmail(email);
    setPassword(password);
    setPhone(phone);
    setFile(file);
    setUserType(userType);
    setState(true);
};
std::string FacultyStaff::getEmail() const {
    return _email;
};
std::string FacultyStaff::getPassword() const {
    return _password;
};
std::string FacultyStaff::getPhone() const {
    return _phone;
};
int FacultyStaff::getFile() const {
    return _file;
};
int FacultyStaff::getUserType() const {
    return _userType;
};
bool FacultyStaff::getState() const {
    return _state;
};
void FacultyStaff::setEmail(std::string email) {
    strcpy(_email, email.c_str());
};
void FacultyStaff::setPassword(std::string password) {
    strcpy(_password, password.c_str());
};
void FacultyStaff::setPhone(std::string phone) {
    strcpy(_phone, phone.c_str());
};
void FacultyStaff::setFile(int file) {
    _file = file;
};
void FacultyStaff::setUserType(int userType) {
    _userType = userType;
};
void FacultyStaff::setState(bool state) {
    _state = state;
};
void FacultyStaff::logout() {
    std::cout << "FINALIZANDO SESION" << std::endl;
};
void FacultyStaff::show(){
    std::cout << "LEGAJO         : " << getFile() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};