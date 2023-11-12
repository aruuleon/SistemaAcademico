#include "Teacher.h"

Teacher::Teacher() {

};
Teacher::Teacher(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType) {
    FacultyStaff:FacultyStaff(name, surname, document, email, password, phone, file, userType);
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