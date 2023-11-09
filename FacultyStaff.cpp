#include "FacultyStaff.h"
#include <cstring>

FacultyStaff::FacultyStaff() {

};
FacultyStaff::FacultyStaff(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file) {
    Person:Person(name, surname, document);
    setEmail(email);
    setPassword(password);
    setPhone(phone);
    setFile(file);
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
void FacultyStaff::setState(bool state) {
    _state = state;
};
void FacultyStaff::logout() {

};