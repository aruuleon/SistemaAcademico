#pragma once
#include <string>

class UserLogin {
    private:
        char _password[20];
        int _file;
        int _userType;
    public:
        UserLogin();
        UserLogin(std::string, int, int);
        std::string getPassword() const;
        int getFile() const;
        int getUserType() const;
        void setPassword(std::string);
        void setFile(int);
        void setUserType(int);
};