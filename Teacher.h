#pragma once
#include "FacultyStaff.h"
#include "GenericFile.h"


class Teacher : public FacultyStaff {
    private:
        void sendRequest(Teacher, int);
        void showAssignedComissions();
        void showAssignedSubjects();
        void editInformation(Teacher);
        void sendRequestEdit(Teacher, int);
        void editMail(Teacher);
        void editPhone(Teacher);
        void editPassword(Teacher);
        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
    public:
        Teacher();
        Teacher(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Teacher);
        void show();
};