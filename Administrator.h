#pragma once
#include "FacultyStaff.h"

class Administrator : public FacultyStaff {
    private:
        void sendRequest(int);
        void registerStaff(int);
        void editStaff();
        void removeStaff(int);
        void reEnrollStaff(int);
        void verifyInformation(int);
        void listStaff(int);
        void assignNoteStudent();
        void editStudentNote();
        void postNotices();
        void showGenericMenu(int);
        void showMenuTeacher();
        void showMenuStudent();
        void sendGenericRequest(int, int);
    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu();
        void show();
};