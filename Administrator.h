#pragma once
#include "FacultyStaff.h"
#include "Teacher.h"
#include "Student.h"
#include "UserLogin.h"
#include "Notice.h"
#include "Comission.h"
#include "GenericFile.h"

class Administrator : public FacultyStaff {
    private:
        void sendRequest(int); // ok
        void registerStaff(int); // ok
        void editStaff();
        void withdrawStaff(int); // ok
        void reEnrollStaff(int); // ok
        void verifyInformation(int); // ok
        void listStaff(int); // ok
        void assignNoteStudent();
        void editStudentNote();
        void postNotice(); // ok
        void editNotice();
        void withdrawNotice(); // ok 
        void showGenericMenu(int); // ok
        void showMenuTeacher(); // ok
        void showMenuStudent(); // ok
        void showMenuNotice(); // ok
        void showMenuComission();
        void sendGenericRequest(int, int); // ok
        void sendNoticeRequest(int); //ok
        void sendComissionRequest(int);
        void listNotices(); // ok
        void registerComission();
        void editComission();
        void withdrawComission();
        void reEnrollComission();
        void verifyInformationComission();
        void listComissions();
        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <UserLogin> _userLoginFile = GenericFile <UserLogin> ("usersLogin.dat");
        GenericFile <Notice> _noticeFile = GenericFile <Notice> ("notices.dat");
        GenericFile <Comission> _comissionFile = GenericFile <Comission> ("comissions.dat");

    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); // ok
        void show(); //ok
};