#pragma once
#include "FacultyStaff.h"
#include "GenericFile.h"
#include "Administrator.h"
#include "Career.h"
#include "Subject.h"

class SuperAdministrator : public FacultyStaff {
    private:
        void sendRequest(int); // ok
        void sendGenericRequest(int, int);
        void showGenericMenu(int);
        void registerByOption(int);
        void editByOption(int);
        void withdrawByOption(int);
        void reEnrollByOption(int);
        void searchByOption(int);
        void listByOption(int);
        GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); // ok
        void show(); // ok
};