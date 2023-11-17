#include "SuperAdministrator.h"

SuperAdministrator::SuperAdministrator() {

};
SuperAdministrator::SuperAdministrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType) {
    FacultyStaff:FacultyStaff(name, surname, document, email, password, phone, file, userType);
};
void SuperAdministrator::showMenu(SuperAdministrator superAdministrator) {
    int selectedOption;
    do {
        std::cout << "MENU SUPER ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR ADMINISTRADOR" << std::endl;
        std::cout << "2 - ELIMINAR ADMINISTRADOR" << std::endl;
        std::cout << "3 - BUSCAR ADMINISTRADOR" << std::endl;
        std::cout << "4 - MOSTRAR LISTA ADMINISTRADORES" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void SuperAdministrator::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: registerAdministrator();
            break;
        case 2: withdrawAdministrator();
            break;
        case 3: searchAdministrator();
            break;
        case 4: listAdministrators();
            break;
        case 0: logout();
            break;
    }
};
void SuperAdministrator::registerAdministrator() {
    std::cout << "REGISTRANDO ADMINISTRADOR.." << std::endl;
};
void SuperAdministrator::withdrawAdministrator() {
    std::cout << "ELIMINANDO ADMINISTRADOR.." << std::endl;
};
void SuperAdministrator::searchAdministrator() {
    std::cout << "BUSCANDO ADMINISTRADOR.." << std::endl;
};
void SuperAdministrator::listAdministrators() {
    std::cout << "MOSTRANDO LISTA ADMINISTRADORES.." << std::endl;
};
void SuperAdministrator::show(){
    std::cout << "LEGAJO         : " << getFile() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};