#include <cstring>
#include "UserLogin.h"

UserLogin::UserLogin() {

};
UserLogin::UserLogin(std::string password, int file, int userType) {
    setPassword(password);
    setFile(file);
    setUserType(userType);
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
void UserLogin::setPassword(std::string password) {
    strcpy(_password, password.c_str());
};
void UserLogin::setFile(int file) {
    _file = file;
};
void UserLogin::setUserType(int userType) {
    _userType = userType;
};