#include "SuperAdministrator.h"
// #include "AdministratorFile.h"
#include "UserLoginFile.h"

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
    AdministratorFile administratorFile ("administrators.dat");
    file = verifyFile(administratorFile);
    UserLoginFile userLoginFile ("usersLogin.dat");
    Administrator administrator = Administrator(name, surname, document, email, phone, password, file, 2);
    UserLogin userLogin = UserLogin(password, file, 2);
    bool administratorResponse = administratorFile.save(administrator);
    bool userResponse = userLoginFile.save(userLogin);
};
void SuperAdministrator::withdrawAdministrator() {
    std::cout << "ELIMINANDO ADMINISTRADOR.." << std::endl;
};
void SuperAdministrator::searchAdministrator() {
    std::cout << "BUSCANDO ADMINISTRADOR.." << std::endl;
};
void SuperAdministrator::listAdministrators() {
    std::cout << "MOSTRANDO LISTA ADMINISTRADORES.." << std::endl;
    AdministratorFile administratorFile ("administrators.dat");
    int numberOfRecords = administratorFile.numberOfRecords();
    for(int i = 0; i < numberOfRecords; i++) {
       Administrator administrator = administratorFile.read(i);
        std::cout << administrator.getFile() << std::endl;
        std::cout << administrator.getPassword() << std::endl;
        std::cout << administrator.getUserType() << std::endl;
        std::cout << std::endl;
    }
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
int SuperAdministrator::verifyFile(AdministratorFile administratorFile){
    int generatedFile;
    int numberOfRecords = administratorFile.numberOfRecords();
    std::cout << "CANT. REGISTROS " << numberOfRecords << std::endl;
    if(numberOfRecords==0){
        generatedFile = 1;
        std::cout << "NO HAY REGISTROS";
    }    
    else{
        std::cout << "HAY REGISTROS" << std::endl;
        Administrator administrator = administratorFile.read(numberOfRecords - 1);
        generatedFile = administrator.getFile() + 1;
    }
    std::cout << "LEGAJO ASIGNADO: " << generatedFile << std::endl;
    return generatedFile;

}
