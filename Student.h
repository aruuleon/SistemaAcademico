#pragma once

#include "FacultyStaff.h"
#include "Exam.h"
#include "Career.h"
#include "Subject.h"
#include "StudentXCareer.h"
#include "ExamXStudentXSubject.h"
#include "GenericFile.h"
#include "Student.h"
#include "SubjectXCareer.h"
#include "StudentXSubject.h"
#include "ExamXSubject.h"

class Student : public FacultyStaff {
    private:
        void sendRequest(Student, int);
        void registerToExam(Student);
        void registerToSubject(Student);
        void removeSubject(Student);
        void showRegisteredSubjects(Student);
        void showAcademicState();
        void showExamNotes(Student);
        void showExamsByStudent(Student);
        void requestCertificate(Student);
        void generateCertificate(ExamXStudentXSubject, Exam, Student);
        void showMessageErrorGenerateCertificate(Exam);
        void showGeneratedCertificate(Exam, Student, Subject);
        void showExam(Exam, Subject);
        void editInformation(Student);
        void sendRequestEdit(Student, int);
        void showPersonalInformation(Student);
        int verifyStudentCareerId(Student);
        void showSubjectsOfTheCareer(int);
        GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
        GenericFile <StudentXCareer> _studentXCareerFile = GenericFile <StudentXCareer> ("studentsXCareers.dat");
        GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat");
        GenericFile <StudentXSubject> _studentXSubjectFile = GenericFile <StudentXSubject> ("studentsXSubjects.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <ExamXSubject> _examXSubjectFile = GenericFile <ExamXSubject> ("examsXSubjects.dat");
        GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");
    public:
        Student();
        Student(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(Student);
        void show();
};