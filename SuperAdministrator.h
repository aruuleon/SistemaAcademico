#pragma once
#include "FacultyStaff.h"

class SuperAdministrator : public FacultyStaff {
    private:
        void sendRequest(int);
        void registerAdministrator();
        void withdrawAdministrator();
        void searchAdministrator();
        void listAdministrators();
    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(SuperAdministrator);
        void show();
};