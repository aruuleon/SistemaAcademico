#pragma once
#include "Person.h"

class FacultyStaff : public Person {
    private:
        char _email[20];
        char _password[20];
        char _phone[20];
        int _file;
        bool _state;
    public:
        FacultyStaff();
        FacultyStaff(std::string, std::string, std::string, std::string, std::string, std::string, int);
        std::string getEmail() const;
        std::string getPassword() const;
        std::string getPhone() const;
        int getFile() const;
        bool getState() const;
        void setEmail(std::string email);
        void setPassword(std::string password);
        void setPhone(std::string phone);
        void setFile(int file);
        void setState(bool state);
        void logout();

};