#include "Administrator.h"

Administrator::Administrator() {

};
Administrator::Administrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
    
};
void Administrator::showMenu(Administrator administrator) {
    int selectedOption;
    do {
        std::cout << "MENU ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - MODIFICAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - VERIFICAR INFORMACION" << std::endl;
        std::cout << "5 - ASIGNAR NOTA ALUMNO" << std::endl;
        std::cout << "6 - EDITAR NOTA ALUMNO" << std::endl;
        std::cout << "7 - SUBIR AVISOS" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: registerStaff();
            break;
        case 2: editStaff();
            break;
        case 3: removeStaff();
            break;
        case 4: verifyInformation();
            break;
        case 5: assignNoteStudent();
            break;
        case 6: editStudentNote();
            break;
        case 7: postNotices();
            break;
        case 0: logout();
            break;
    }
};
void Administrator::registerStaff() {

};
void Administrator::editStaff() {

};
void Administrator::removeStaff() {

};
void Administrator::verifyInformation() {

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