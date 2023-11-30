#include "Teacher.h"
#include "Functions.h"

Teacher::Teacher() {

};
Teacher::Teacher(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void Teacher::showMenu(Teacher teacher) {
    int selectedOption;
    do {std::cout << "================================ PROFESOR ===============================" << std::endl;
        std::cout << " " << getSurname() << ", " << getName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << "1 - COMISIONES ASIGNADAS" << std::endl;
        std::cout << "2 - MATERIAS ASIGNADAS" << std::endl;
        std::cout << "3 - EDICION" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendRequest(teacher, selectedOption);
    } while(selectedOption != 0);
};
void Teacher::sendRequest(Teacher teacher, int selectedOption) {
    switch(selectedOption) {
        case 1: showAssignedComissions();
            break;
        case 2: showAssignedSubjects();
            break;
        case 3: editInformation(teacher);
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
};
void Teacher::editInformation(Teacher teacher){
    int selectedOption;
    std::cout << "* SELECCIONE UN CAMPO A EDITAR" << std::endl;   
    std::cout << "1 - MAIL" << std::endl;
    std::cout << "2 - TELEFONO" << std::endl;
    std::cout << "3 - CLAVE" << std::endl;
    std::cin >> selectedOption;
    system("cls");
    sendRequestEdit(teacher, selectedOption);
};
void Teacher::sendRequestEdit(Teacher teacher, int selectedOption){
    switch (selectedOption){
    
    case 1: editMail(teacher);
        break;
    case 2: editPhone(teacher);
        break;
    case 3: editPassword(teacher);
        break;
    }    
};
void Teacher::editMail(Teacher teacher){
    int position  = _teacherFile.searchRecord(teacher.getId());
    std::string email;
    std::cout << "EMAIL ACTUAL:" << teacher.getEmail() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO EMAIL: " ;
    std::getline(std::cin, email);
    teacher.setEmail(email);
    _teacherFile.save(teacher, position);
};
void Teacher::editPhone(Teacher teacher){
    int position = _teacherFile.searchRecord(teacher.getId());
    std::string phone;
    std::cout << "TELEFONO ACTUAL:" << teacher.getPhone() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO TELEFONO: " ;
    std::getline(std::cin, phone);
    teacher.setPhone(phone);
    _teacherFile.save(teacher, position);
};
void Teacher::editPassword(Teacher teacher){
    int position = _teacherFile.searchRecord(teacher.getId());
    std::string password;
    std::cout << "CLAVE ACTUAL:" << teacher.getPassword() << std::endl;
    std::cin.ignore();
    std::cout << "INGRESAR NUEVA CLAVE: " ;
    std::getline(std::cin, password);
    teacher.setPhone(password);
    _teacherFile.save(teacher, position);
};