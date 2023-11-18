#pragma once
#include "FacultyStaff.h"
#include "AdministratorFile.h"

class SuperAdministrator : public FacultyStaff {
    private:
        void sendRequest(int); // ok
        void registerAdministrator(); // ok
        void withdrawAdministrator(); // ok
        void searchAdministrator(); // ok
        void listAdministrators(); // ok
        int verifyFile(); // ok
        void show(); // ok
    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); // ok
};