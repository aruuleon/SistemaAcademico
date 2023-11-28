#pragma once
#include "FacultyStaff.h"
#include "GenericFile.h"
#include "Administrator.h"
#include "Subject.h"
#include "Career.h"
#include "SubjectXCareer.h"

class SuperAdministrator : public FacultyStaff {
    private:
        void sendRequest(int); // ok
        void sendGenericRequest(int, int); //ok
        void showGenericMenu(int); //ok
        void registerByOption(int); //ok
        void editByOption(int); 
        void withdrawByOption(int); //ok
        void reEnrollByOption(int); //ok
        void searchByOption(int); //ok
        void listByOption(int); //ok
        GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
        GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
        GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
        GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
    public:
        SuperAdministrator();
        SuperAdministrator(std::string, std::string, std::string, std::string, std::string, std::string, int, int);
        void showMenu(); // ok
        void show(); // ok
        void withdrawSubject(int);
        void withdrawCareer(int);
        void showSubjectsByCareer();
};
// template <class T>
// void reEnrollByOption(int optionReceived, GenericFile <T> file) {
//     std::string name = (optionReceived == 1) ? "user" : "resourse"; 
//     reEnrollRegisterByOption(file, name);
// };