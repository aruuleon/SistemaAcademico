#pragma once
#include "FacultyStaff.h"

class Teacher : public FacultyStaff {
    private:

    public:
        Teacher();
        Teacher(std::string, std::string, std::string, std::string, std::string, std::string, int);
        void showAssignedComissions();
        void showAssignedSubjects();
};