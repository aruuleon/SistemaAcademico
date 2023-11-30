#pragma once

#include "FacultyStaff.h"
#include "Exam.h"
#include "Career.h"
#include "Subject.h"
#include "StudentXCareer.h"
#include "ExamXStudentXSubject.h"
#include "GenericFile.h"
#include "Student.h"

class Student : public FacultyStaff {
    private:
        void sendRequest(Student, int);
        void registerToExam();
        void registerToSubject(Student);
        void removeSubject();
        void showCareerSubjects();
        void showAcademicState();
        void showExamNotes();
        void showExamsByStudent(Student);
        void requestCertificate(Student);
        void generateCertificate(ExamXStudentXSubject, Exam, Student);
        void showMessageErrorGenerateCertificate(Exam);
        void showGeneratedCertificate(Exam, Student, Subject);
        void showExam(Exam, Subject);
        void editInformation(Student);
        void sendRequestEdit(Student, int);
        void editMail(Student);
        void editPhone(Student);
        void editPassword(Student);
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <StudentXCareer> _studentXCareer = GenericFile <StudentXCareer> ("studentsXCareers.dat");
        GenericFile <SubjectXCareer> _subjectXCareer = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
        GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");
    public:
        Student();
        Student(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Student);
        void show();
};