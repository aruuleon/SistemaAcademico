#pragma once
#include "FacultyStaff.h"

class Administrator : public FacultyStaff {
    private:
        void sendRequest(int);
        void registerStaff();
        void editStaff();
        void removeStaff();
        void verifyInformation();
        void assignNoteStudent();
        void editStudentNote();
        void postNotices();
    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Administrator);
        void show();
};