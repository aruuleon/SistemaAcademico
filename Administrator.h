#pragma once
#include "FacultyStaff.h"

class Administrator : public FacultyStaff {
    private:

    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int);
        void registerStaff();
        void editStaff();
        void removeStaff();
        void verifyInformation();
        void assignNoteStudent();
        void editStudentNote();
        void postNotices();
};