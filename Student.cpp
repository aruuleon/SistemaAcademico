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
        std::cout << "4 - LISTA DE MATERIAS INSCRIPTAS" << std::endl;
        std::cout << "5 - ESTADO ACADEMICO" << std::endl;
        std::cout << "6 - NOTAS DE EXAMEN" << std::endl;
        std::cout << "7 - GENERAR CERTIFICADO EXAMEN" << std::endl;
        std::cout << "8 - EDICION" << std::endl;
        std::cout << "9 - INFORMACION PERSONAL" << std::endl;
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
        case 3: removeSubject(student);
            break;
        case 4: showRegisteredSubjects(student);
            break;
        case 5: showAcademicState();
            break;
        case 6: showExamsByStudent(student);
            break;
        case 7: requestCertificate(student);
            break;
        case 8: editInformation(student);
            break;
        case 9: showPersonalInformation(student);
            break;
        case 0: logout();
            break;
    }
};
void Student::registerToExam() {
    
};
void Student::registerToSubject(Student student) {
    int subjectId;
    int careerId = verifyStudentCareerId(student);
    showSubjectsOfTheCareer(careerId);
    std::cout << "SELECCIONAR ID DE MATERIA A LA QUE QUIERE REGISTRARSE: ";
    std::cin >> subjectId;
    if(_studentXSubject.save(StudentXSubject(student.getId(), subjectId))) {
        Subject subject = _subjectFile.read(_subjectFile.searchRecord(subjectId));
        std::cout << "USTED FUE REGISTRADO A LA SIGUIENTE MATERIA CORRECTAMENTE" << std::endl;
        subject.show();
    }
};
int Student::verifyStudentCareerId(Student student) {
    int careerId;
    int numberOfRecordsRelationship = _subjectXCareer.numberOfRecords();
    int positionRelationship = 0;
    bool relationshipFound = false;
    std::cout << "MATERIAS DE LA CARRERA" << std::endl;
    while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
        StudentXCareer studentXCareer = _studentXCareer.read(positionRelationship);
        if(studentXCareer.getFirstResourceId() == student.getId()) {
            int numberOfRecordsCareer = _careerFile.numberOfRecords();
            int positionCareer = 0;
            bool careerFound = false;
            while(!careerFound && positionCareer < numberOfRecordsCareer) {
                Career career = _careerFile.read(positionCareer);
                if(career.getState() && career.getId() == studentXCareer.getSecondResourceId()) {
                    careerFound = true;
                    careerId = career.getId();
                }
            }
            relationshipFound = true;
        }
        positionRelationship++;
    }
    return careerId;
};
void Student::showSubjectsOfTheCareer(int careerId) {
    int numberOfRecordsRelationship = _subjectXCareer.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    Career career = _careerFile.read(_careerFile.searchRecord(careerId));
    
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        SubjectXCareer subjectXCareer = _subjectXCareer.read(i);
        for(int j = 0; j < numberOfRecordsSubject; j++) {
            Subject subject = _subjectFile.read(j);
            if(career.getId() == subjectXCareer.getSecondResourceId() && subject.getState() && subject.getId() == subjectXCareer.getFirstResourceId()) {
                subject.show();
            }
        }
    }
}
void Student::removeSubject(Student student) {
    std::cout << "MATERIA A DARSE DE BAJA" << std::endl;
    showRegisteredSubjects(student);
    std::cout << std::endl;
    int subjectId;
    std::cout << "INGRESAR ID DE MATERIA A DAR DE BAJA: ";
    std::cin >> subjectId;
    withdrawRelationship(_studentXSubject, StudentXSubject(), student, subjectId, "ALUMNO/A", "MATERIA");
};
void Student::showRegisteredSubjects(Student student) {
    std::cout << "* MATERIAS INSCRIPTAS" << std::endl;
    std::cout << std::endl;
    int numberOfRecordsRelationship = _studentXSubject.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        StudentXSubject studentXSubject = _studentXSubject.read(i);
        if(studentXSubject.getState() && studentXSubject.getFirstResourceId() == student.getId()) {
            for(int j = 0; j < numberOfRecordsSubject; j++) {
                Subject subject = _subjectFile.read(j);
                if(subject.getState() && subject.getId() == studentXSubject.getSecondResourceId()) {
                    subject.show();
                }
            }
        }
    }
};
void Student::showAcademicState() {

};
void Student::showExamNotes(Student student) {
    std::cout << "LISTA DE EXAMENES REALIZADOS POR EL ALUMNO" << std::endl;
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    int numberOfRecordsExam = _examFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        ExamXStudentXSubject examXStudentXSubject = _examXStudentXSubjectFile.read(i);
        int positionExam = 0;
        bool examFound = false;
        while(!examFound && positionExam < numberOfRecordsExam) {
            Exam exam = _examFile.read(positionExam);
            if(exam.getId() == examXStudentXSubject.getFirstResourceId() && student.getId() == examXStudentXSubject.getSecondResourceId()) {
                int positionSubject = 0;
                bool subjectFound = false;
                while(!subjectFound && positionSubject < numberOfRecordsSubject) {
                    Subject subject = _subjectFile.read(positionSubject);
                    if(subject.getState() && subject.getId() == examXStudentXSubject.getThirdResourceId()) {
                        subjectFound = true;
                        showExam(exam, subject);
                    }
                }
                examFound = true;
            }
            positionExam++;
        }
    }
};
void Student::showExamsByStudent(Student student) {
    int numberOfRecordsRelationship = _examXStudentXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int numberOfrecordsExam = _examFile.numberOfRecords();

    if(numberOfRecordsRelationship > 0) {
        std::cout << "LISTA DE EXAMENES REALIZADOS POR EL ALUMNO" << std::endl;
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
    } else {
        std::cout << "NO REALIZASTE EXAMENES POR EL MOMENTO" << std::endl;
    }
};
void Student::requestCertificate(Student student) {
    showExamsByStudent(student);
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
    case 1: editRegisterByOption(_studentFile, student, "EMAIL");
        break;
    case 2: editRegisterByOption(_studentFile, student, "PHONE");
        break;
    case 3: editRegisterByOption(_studentFile, student, "PASSWORD");
        break;
    }
};
void Student::showPersonalInformation(Student student) {
    student.show();
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