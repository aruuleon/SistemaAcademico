#include "Administrator.h"

Administrator::Administrator() {

};
Administrator::Administrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
    
};
void Administrator::showMenu() {
    int selectedOption;
    do {
        std::cout << "MENU ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - PROFESOR " << std::endl;
        std::cout << "2 - ALUMNO" << std::endl;
        std::cout << "3 - SUBIR AVISOS" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: showGenericMenu(3);
            break;
        case 2: showGenericMenu(4);
            break;
        case 3: postNotices();
            break;
        case 0: logout();
            break;
    }
};
void Administrator::registerStaff(int userType) {
    std::string name;
    std::string surname;
    std::string document;
    std::string email;
    std::string password;
    std::string phone;
    int file;
    std::cout << "REGISTRANDO STAFF.." << std::endl;
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
    // file = verifyFile();
    // AdministratorFile administratorFile ("administrators.dat");
    // UserLoginFile userLoginFile ("usersLogin.dat");
    // bool administratorResponse = administratorFile.save(Administrator(name, surname, document, email, password, phone, file, 2));
    // bool userResponse = userLoginFile.save(UserLogin(password, file, 2));
    if(userType == 3){
        
    } else{

    }
};
void Administrator::editStaff() {
};
void Administrator::removeStaff(int userType) {
    if(userType == 3){

    } else{

    }
};
void Administrator::reEnrollStaff(int userType){
    if(userType == 3){

    } else{

    }
};
void Administrator::verifyInformation(int userType) {
    if(userType == 3){

    } else{

    }
};
void Administrator::listStaff(int userType) {
    std::cout << "MOSTRANDO LISTA STAFF.." << std::endl;
    if(userType == 3){

    } else{

    }
};
void Administrator::assignNoteStudent() {

};
void Administrator::editStudentNote() {

};
void Administrator::postNotices() {

};
void Administrator::show(){
    std::cout << "LEGAJO         : " << getFile() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};
void Administrator::showGenericMenu(int userType){
    int selectedOption;
    do {
    std::cout << "1 - REGISTRAR" << std::endl;
    std::cout << "2 - ELIMINAR" << std::endl;
    std::cout << "3 - DAR DE ALTA" << std::endl;
    std::cout << "4 - MOSTRAR INFORMACION" << std::endl;
    std::cout << "5 - MOSTAR LISTA REGISTROS" << std::endl;
    if(userType == 3){
        showMenuTeacher();
    } else{
        showMenuStudent();
    }
    std::cout << "0 - VOLVER" << std::endl;
    std::cin >> selectedOption;
    sendGenericRequest(selectedOption, userType);
    } while(selectedOption != 0);
};
void Administrator::showMenuTeacher(){
    std::cout << "6 - ASIGNAR MATERIA" << std::endl;
    std::cout << "7 - ASIGNAR COMISION" << std::endl;
     //EDITAR COMISION DE PROFESOR
}
void Administrator::showMenuStudent(){
    std::cout << "6 - ASIGNAR NOTA" << std::endl;
    std::cout << "7 - MODIFICAR NOTA" << std::endl;
};
void Administrator::sendGenericRequest(int selectedOption, int userType) {
    switch(selectedOption) {
        case 1: registerStaff(userType);
            break;
        case 2: removeStaff(userType);
            break;
        case 3: reEnrollStaff(userType);
            break;
        case 4: verifyInformation(userType);
            break;
        case 5: listStaff(userType);
            break;
        case 0: logout();
            break;
    }
};