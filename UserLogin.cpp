#include <iostream>
#include <cstring>
#include "UserLogin.h"

UserLogin::UserLogin() {

};
UserLogin::UserLogin(std::string password, int file, int userType) {
    setPassword(password);
    setFile(file);
    setUserType(userType);
    setState(true);
};
std::string UserLogin::getPassword() const {
    return _password;
};
int UserLogin::getFile() const {
    return _file;
};
int UserLogin::getUserType() const {
    return _userType;
};
bool UserLogin::getState() const {
    return _state;
};
void UserLogin::setPassword(std::string password) {
    strcpy(_password, password.c_str());
};
void UserLogin::setFile(int file) {
    _file = file;
};
void UserLogin::setUserType(int userType) {
    _userType = userType;
};
void UserLogin::setState(bool state) {
    _state = state;
};
void UserLogin::show(){
    std::cout << "CLAVE          : " << getPassword() << std::endl;
    std::cout << "LEGAJO         : " << getFile() << std::endl;
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; //perfil de usuario?
};