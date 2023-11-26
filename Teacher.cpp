#include "Teacher.h"

Teacher::Teacher() {

};
Teacher::Teacher(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void Teacher::showMenu(Teacher teacher) {
    int selectedOption;
    do {
        std::cout << "MENU SUPER ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - COMISIONES ASIGNADAS" << std::endl;
        std::cout << "2 - MATERIAS ASIGNADAS" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void Teacher::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: showAssignedComissions();
            break;
        case 2: showAssignedSubjects();
            break;
        case 0: logout();
            break;
    }
};
void Teacher::showAssignedComissions() {

};
void Teacher::showAssignedSubjects() {

};
void Teacher::show(){
    std::cout << "LEGAJO         : " << getId() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};