#include "Student.h"

Student::Student() {

};
Student::Student(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
    
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

};
void Student::registerToSubject() {

};
void Student::removeSubject() {

};
void Student::showCareerSubjects() {

};
void Student::showAcademicState() {

};
void Student::showExamNotes() {

};
void Student::show(){
    std::cout << "LEGAJO         : " << getFile() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};