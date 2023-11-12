#pragma once
#include <string>
#include "SuperAdministratorFile.h"
#include "AdministratorFile.h"
#include "TeacherFile.h"
#include "StudentFile.h"

class System {
    private:
        char _name[20];
        SuperAdministratorFile _superAdministratorFile = SuperAdministratorFile("superAdministrators.dat");
        AdministratorFile _administratorFile = AdministratorFile("administrators.dat");
        TeacherFile _teacherFile = TeacherFile("teachers.dat");
        StudentFile _studentFile = StudentFile("students.dat");
        int verifyCredentials(int file, std::string password);
        void allowAccess(int, int); // permitir ingreso
    public:
        System();
        System(std::string);
        std::string getName() const;
        void setName(std::string);
        void runProgram();
        void login();
};