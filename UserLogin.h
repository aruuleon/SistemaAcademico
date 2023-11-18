#pragma once
#include <string>

class UserLogin {
    private:
        char _password[20];
        int _file;
        int _userType;
        bool _state;
    public:
        UserLogin();
        UserLogin(std::string, int, int);
        std::string getPassword() const;
        int getFile() const;
        int getUserType() const;
        bool getState() const;
        void setPassword(std::string);
        void setFile(int);
        void setUserType(int);
        void setState(bool);
        void show();
};