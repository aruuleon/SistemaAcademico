#include "SuperAdministrator.h"
#include "Administrator.h"
#include "UserLogin.h"
#include "GenericFile.h"
#include "Functions.h"

SuperAdministrator::SuperAdministrator() {

};
SuperAdministrator::SuperAdministrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
    
};
void SuperAdministrator::showMenu() {
    int selectedOption;
    do {
        std::cout << "MENU SUPER ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR ADMINISTRADOR" << std::endl;
        std::cout << "2 - ELIMINAR ADMINISTRADOR" << std::endl;
        std::cout << "3 - VOLVER A DAR DE ALTA ADMINISTADOR" << std::endl;
        std::cout << "4 - BUSCAR ADMINISTRADOR" << std::endl;
        std::cout << "5 - MOSTRAR LISTA ADMINISTRADORES" << std::endl;
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
        case 3: reEnrollAdministrator();
            break;
        case 4: searchAdministrator();
            break;
        case 5: listAdministrators();
            break;
        case 0: logout();
            break;
    }
};
void SuperAdministrator::registerAdministrator() {
    std::string name;
    std::string surname;
    std::string document;
    std::string email;
    std::string password;
    std::string phone;
    int file;
    int userType;
    std::cout << "REGISTRANDO ADMINISTRADOR.." << std::endl;
    std::cout << "INGRESAR NOMBRE: " << std::endl; 
    std::cin >>  name;
    std::cout << "INGRESAR APELLIDO: " << std::endl;
    std::cin >>  surname; 
    std::cout << "INGRESAR DNI: " << std::endl;
    std::cin >>  document; 
    std::cout << "INGRESAR CORREO: " << std::endl; 
    std::cin >>  email;
    std::cout << "INGRESAR TELEFONO: " << std::endl; 
    std::cin >>  phone;
    std::cout << "INGRESAR CLAVE: " << std::endl; 
    std::cin >> password;
    file = verifyFileAdministrators();
    GenericFile <Administrator> administratorFile ("administrators.dat");
    GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
    bool administratorResponse = administratorFile.save(Administrator(name, surname, document, email, password, phone, file, 2));
    bool userResponse = userLoginFile.save(UserLogin(password, file, 2));
};
void SuperAdministrator::withdrawAdministrator() {
    withdrawAdministrator();
};
void SuperAdministrator::searchAdministrator() {
    searchAdministrator();
};
void SuperAdministrator::listAdministrators() {
    listAdministrators();
};
void SuperAdministrator::reEnrollAdministrator(){
    reEnrollAdministrator();
}

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