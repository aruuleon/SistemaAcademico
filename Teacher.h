#pragma once
#include "FacultyStaff.h"

class Teacher : public FacultyStaff {
    private:
        void sendRequest(int);
        void showAssignedComissions();
        void showAssignedSubjects();
    public:
        Teacher();
        Teacher(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Teacher);
        void show();
};