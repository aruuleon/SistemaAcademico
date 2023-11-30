#include <fstream>
#include "Student.h"
#include "System.h"
#include "Fecha.h"
#include "Functions.h"

Student::Student() {

};
Student::Student(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
    
};
void Student::showMenu(Student student) {
    int selectedOption;
    do {
        std::cout << "MENU ALUMNO" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - INSCRIBIRSE A EXAMEN" << std::endl;
        std::cout << "2 - INSCRIBIRSE A MATERIA" << std::endl;
        std::cout << "3 - DARSE DE BAJA A MATERIA" << std::endl;
        std::cout << "4 - LISTA DE MATERIAS DEL PLAN" << std::endl;
        std::cout << "5 - ESTADO ACADEMICO" << std::endl;
        std::cout << "6 - NOTAS DE EXAMEN" << std::endl;
        std::cout << "7 - GENERAR CERTIFICADO EXAMEN" << std::endl;
        std::cout << "8 - EDICION" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendRequest(student, selectedOption);
    } while(selectedOption != 0);
};
void Student::sendRequest(Student student, int selectedOption) {
    switch(selectedOption) {
        case 1: registerToExam();
            break;
        case 2: registerToSubject(student);
            break;
        case 3: removeSubject();
            break;
        case 4: showCareerSubjects();
            break;
        case 5: showAcademicState();
            break;
        case 6: showExamNotes();
            break;
        case 7: showExamsByStudent(student);
            break;
        case 8: editInformation(student);
            break;
        case 0: logout();
            break;
    }
};
void Student::registerToExam() {

};
void Student::registerToSubject(Student student) {
    int careerId;
    int numberOfRecordsCareer = _careerFile.numberOfRecords();
    int positionCareer = 0;
    bool careerFound = false;
    while(!careerFound && positionCareer < numberOfRecordsCareer) {
        Career career = _careerFile.read(positionCareer);
        int numberOfRecordsRelationship = _subjectXCareer.numberOfRecords();
        int positionRelationship = 0;
        bool relationshipFound = false;
        while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
            StudentXCareer studentXCareer = _studentXCareer.read(positionRelationship);
            if(career.getState() && career.getId() == studentXCareer.getSecondResourceId() 
            && student.getId() == studentXCareer.getFirstResourceId()) {
                relationshipFound = true;
                careerId = studentXCareer.getSecondResourceId();
            }
            positionRelationship++;
        }
    }

    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int numberOfRecordsRelationship = _subjectXCareer.numberOfRecords();
    Career career = _careerFile.read(_careerFile.searchRecord(careerId));
    
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        SubjectXCareer subjectXCareer = _subjectXCareer.read(i);
        for(int j = 0; j < numberOfRecordsSubject; j++) {
            Subject subject = _subjectFile.read(j);
            if(career.getState() && career.getId() == subjectXCareer.getSecondResourceId() 
            && subject.getState() && subject.getId() == subjectXCareer.getFirstResourceId()) {
                subject.show();
            }
        }
    }
};
void Student::removeSubject() {

};
void Student::showCareerSubjects() {

};
void Student::showAcademicState() {

};
void Student::showExamNotes() {

};
void Student::showExamsByStudent(Student student) {
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int numberOfrecordsExam = _examFile.numberOfRecords();

    if(numberOfRecordsRelationship > 0) {
        for(int i = 0; i < numberOfRecordsRelationship; i++) {
            ExamXStudentXSubject examXStudentXSubject = _examXStudentXSubjectFile.read(i);
            int positionExam = 0;
            bool examFound = false;
            while(!examFound && positionExam < numberOfrecordsExam) {
                Exam exam = _examFile.read(positionExam);
                if(exam.getId() == examXStudentXSubject.getFirstResourceId() 
                && student.getId() == examXStudentXSubject.getSecondResourceId()) {
                    int positionSubject = 0;
                    bool subjectFound = false;                
                    while(!subjectFound && positionSubject < numberOfRecordsSubject) {
                        Subject subject = _subjectFile.read(positionSubject);
                        if(subject.getState() && subject.getId() == examXStudentXSubject.getThirdResourceId()) {
                            subjectFound = true;
                            showExam(exam, subject);
                        }
                        positionSubject++;
                    }
                    examFound = true;
                }
                positionExam++;
            }
        }
        requestCertificate(student);
    } else {
        std::cout << "NO REALIZASTE EXAMENES POR EL MOMENTO" << std::endl;
    }
};
void Student::requestCertificate(Student student) {
    int examenId;
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    std::cout << "SELECCIONAR ID DE EXAMEN A CERTIFICAR: ";
    std::cin >> examenId;
    int positionExam = _examFile.searchRecord(examenId);
    Exam exam = _examFile.read(positionExam);
    int position = 0;
    bool examFound = false;
    while(!examFound && position < numberOfRecordsRelationship) {
        ExamXStudentXSubject examXStudentXSubject = _examXStudentXSubjectFile.read(position);
        if(examXStudentXSubject.getFirstResourceId() == examenId) {
            examFound = true;
            if(examXStudentXSubject.getAttendance()) {
                generateCertificate(examXStudentXSubject, exam, student);
            } else {
                showMessageErrorGenerateCertificate(exam);
            }
        }
        position++;
    }
};
void Student::showMessageErrorGenerateCertificate(Exam exam) {
    std::cout << "NO PODES REALIZAR EL CERTIFICADO DEL EXAMEN CON ID " << exam.getId() << " PORQUE ESTUVISTE AUSENTE" << std::endl;
};
void Student::generateCertificate(ExamXStudentXSubject examXStudentXSubject, Exam exam, Student student) {
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int positionSubject = 0;
    bool subjectFound = false;
    while(!subjectFound && positionSubject < numberOfRecordsSubject) {
        Subject subject = _subjectFile.read(positionSubject);
        if(subject.getId() == examXStudentXSubject.getThirdResourceId()) {
            subjectFound = true;
            showGeneratedCertificate(exam, student, subject);
        }
        positionSubject++;
    }
};
void Student::showGeneratedCertificate(Exam exam, Student student, Subject subject) {
    System system = System("UNIVERSIDAD TECNOLOGICA NACIONAL", "Argentina", "Buenos Aires");
    Fecha date;
    std::cout << "SE CERTIFICA QUE " << student.getName() << " " << student.getSurname() << std::endl;
    std::cout << "RINDIO EL EXAMEN CORRESPONDIENTE A LA MATERIA " << subject.getName() << "EL DIA DE LA FECHA " << exam.getDate().toString() << std::endl;
    std::cout << "SE EXTIENDE EL PRESENTE A PEDIDO DEL/LA INTERESADO/A PARA SER PRESENTADO ANTE QUIEN CORRESPONDA"  << std::endl;
    std::cout << "A LA FECHA DEL " << date.toString() << ", EN " << system.getLocation() << "."  << std::endl;
    std::cout << std::endl;
    std::cout << "FIRMA: " << system.getName() << std::endl;
};
void Student::showExam(Exam exam, Subject subject) {
    std::cout << "INFORMACION EXAMEN" << std::endl;
    std::cout << "ID: " << exam.getId() << std::endl;
    std::cout << "CALIFICACION: " << exam.getGrade() << std::endl;
    std::cout << "FECHA: " << exam.getDate().toString() << std::endl;
    std::cout << "MATERIA: " << subject.getName() << std::endl;
};
void Student::show(){
    std::cout << "LEGAJO         : " << getId() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};

void Student::editInformation(Student student){
    int selectedOption;
    std::cout << "* SELECCIONE UN CAMPO A EDITAR" << std::endl;   
    std::cout << "1 - MAIL" << std::endl;
    std::cout << "2 - TELEFONO" << std::endl;
    std::cout << "3 - CLAVE" << std::endl;
    std::cin >> selectedOption;
    system("cls");
    sendRequestEdit(student, selectedOption);
};
void Student::sendRequestEdit(Student student, int selectedOption){
    switch (selectedOption){
    
    case 1: editMail(student);
        break;
    case 2: editPhone(student);
        break;
    case 3: editPassword(student);
        break;
    }    
};

void Student::editMail(Student student){
    int position  = _studentFile.searchRecord(student.getId());
    std::cout << "ID " << student.getId(); 
    std::cout << position << std::endl;
    std::string email;
    std::cout << "EMAIL ACTUAL:" << student.getEmail() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO EMAIL: " ;
    std::getline(std::cin, email);
    student.setEmail(email);
    _studentFile.save(student, position);
};
void Student::editPhone(Student student){
    int position = _studentFile.searchRecord(student.getId());
    std::string phone;
    std::cout << "TELEFONO ACTUAL:" << student.getPhone() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO TELEFONO: " ;
    std::getline(std::cin, phone);
    student.setPhone(phone);
    _studentFile.save(student, position);
};
void Student::editPassword(Student student){
    int position = _studentFile.searchRecord(student.getId());
    std::string password;
    std::cout << "CLAVE ACTUAL:" << student.getPassword() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVA CLAVE: " ;
    std::getline(std::cin, password);
    student.setPhone(password);
    _studentFile.save(student, position);
};