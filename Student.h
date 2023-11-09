#pragma once
#include "FacultyStaff.h"

class Student : public FacultyStaff {
    private:

    public:
        Student();
        Student(std::string, std::string, std::string, std::string, std::string, std::string, int);
        void registerToExam();
        void registerToSubject();
        void removeSubject();
        void showCareerSubjects();
        void showAcademicState();
        void showExamNotes();
};