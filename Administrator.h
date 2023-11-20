#pragma once
#include "FacultyStaff.h"

class Administrator : public FacultyStaff {
    private:
        void sendRequest(int);
        void registerStaff(int); //ok
        void editStaff();
        void withdrawStaff(int); //ok
        void reEnrollStaff(int); //ok
        void verifyInformation(int); //ok
        void listStaff(int); //ok
        void assignNoteStudent();
        void editStudentNote();
        void postNotice();
        void withdrawNotice();
        void editNotice();
        void showGenericMenu(int); //ok
        void showMenuTeacher(); //ok
        void showMenuStudent(); //ok
        void showMenuNotice();
        void sendGenericRequest(int, int); //ok
        void sendNoticeRequest(int);
        int verifyFile(int); //ok
    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); //ok
        void show(); //ok
};