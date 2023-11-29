#include "Student.h"

Student::Student() {

};
Student::Student(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
    
};
void Student::showMenu(Student student) {
    int selectedOption;
    do {
        std::cout << "================================= ALUMNO ================================" << std::endl;
        std::cout << " " << this->getSurname() << ", " << this->getName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - INSCRIBIRSE A EXAMEN" << std::endl;
        std::cout << "2 - INSCRIBIRSE A MATERIA" << std::endl;
        std::cout << "3 - DARSE DE BAJA A MATERIA" << std::endl;
        std::cout << "4 - LISTA DE MATERIAS DEL PLAN" << std::endl;
        std::cout << "5 - ESTADO ACADEMICO" << std::endl;
        std::cout << "6 - NOTAS DE EXAMEN" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void Student::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: registerToExam();
            break;
        case 2: registerToSubject();
            break;
        case 3: removeSubject();
            break;
        case 4: showCareerSubjects();
            break;
        case 5: showAcademicState();
            break;
        case 6: showExamNotes();
            break;
        case 0: logout();
            break;
    }
};
void Student::registerToExam() {
    system("pause");
};
void Student::registerToSubject() {
    system("pause");
};
void Student::removeSubject() {
    system("pause");
};
void Student::showCareerSubjects() {
    system("pause");
};
void Student::showAcademicState() {
    system("pause");
};
void Student::showExamNotes() {
    system("pause");
};
void Student::show(){
    std::cout << "LEGAJO         : " << getId() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
};