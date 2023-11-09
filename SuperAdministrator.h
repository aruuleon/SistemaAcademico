#pragma once
#include "FacultyStaff.h"

class SuperAdministrator : public FacultyStaff {
    private:

    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int);
        void registerAdministrator();
        void withdrawAdministrator();
};