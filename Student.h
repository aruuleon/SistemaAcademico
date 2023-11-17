#pragma once
#include "FacultyStaff.h"

class Student : public FacultyStaff {
    private:
        void sendRequest(int);
        void registerToExam();
        void registerToSubject();
        void removeSubject();
        void showCareerSubjects();
        void showAcademicState();
        void showExamNotes();
    public:
        Student();
        Student(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Student);
        void show();
};