#pragma once
#include "FacultyStaff.h"
#include "Teacher.h"
#include "Student.h"
#include "UserLogin.h"
#include "Notice.h"
#include "Subject.h"
#include "Comission.h"
#include "GenericFile.h"
#include "SubjectXComission.h"
#include "StudentXSubject.h"
#include "Exam.h"
#include "Career.h"
#include "StudentXCareer.h"
#include "TeacherXSubject.h"
#include "SubjectXCareer.h"
#include "ExamXStudentXSubject.h"
#include "ExamXSubject.h"

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
        void showMenuComission(); // ok
        void sendUserTypeRequest(int, int);
        void sendGenericRequest(int, int); // ok
        void sendTeacherRequest(int);
        void sendStudentRequest(int);
        void sendNoticeRequest(int); //ok
        void sendComissionRequest(int);
        void listNotices(); // ok
        void registerComission(); // ok
        void editComission();
        void assignGradeStudent();
        void modifyGradeStudent();
        void generateExam();
        void assignTeacherToSubject();
        void showSubjects(int, int, int);
        void finishAssignmentProcess(int, int, int, int);
        // void generateCertificate();

        GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <UserLogin> _userLoginFile = GenericFile <UserLogin> ("usersLogin.dat");
        GenericFile <Notice> _noticeFile = GenericFile <Notice> ("notices.dat");
        GenericFile <Comission> _comissionFile = GenericFile <Comission> ("comissions.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
        GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        // GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
        GenericFile <SubjectXComission> _subjectXComissionFile = GenericFile <SubjectXComission> ("subjectsXComissions.dat");
        GenericFile <StudentXSubject> _studentXSubjectFile = GenericFile <StudentXSubject> ("studentsXSubjects.dat");
        GenericFile <StudentXCareer> _studentXCareerFile = GenericFile <StudentXCareer> ("studentsXCareers.dat");
        GenericFile <ExamXStudentXSubject> _examXStudentXSubject = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");
    public:
        Administrator();
        Administrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); // ok
        void show(); //ok
};