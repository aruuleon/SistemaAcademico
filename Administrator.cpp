#include "Administrator.h"
#include "Functions.h"
#include "Fecha.h"

Administrator::Administrator() {

};
Administrator::Administrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int file, int userType)
:FacultyStaff(name, surname, document, email, password, phone, file, userType) {
};
void Administrator::showMenu() {
    int selectedOption;
    do {
        system("cls");
        std::cout << "============================= ADMINISTRADOR =============================" << std::endl;
        std::cout << " " <<this->getSurname() << ", " << this->getName() << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - PROFESOR " << std::endl;
        std::cout << "2 - ALUMNO" << std::endl;
        std::cout << "3 - AVISOS" << std::endl;
        std::cout << "4 - COMISION" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: showGenericMenu(3);
            break;
        case 2: showGenericMenu(4);
            break;
        case 3: showMenuNotice();
            break;
        case 4: showMenuComission();
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
    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION REGISTRO                          " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "INGRESAR NOMBRE: " ;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "INGRESAR APELLIDO: " ;
    getline(std::cin, surname);
    std::cout << "INGRESAR DNI: " ;
    std::cin >>  document; 
    std::cout << "INGRESAR CORREO: " ; 
    std::cin >>  email;
    std::cout << "INGRESAR TELEFONO: " ; 
    std::cin >>  phone;
    std::cout << "INGRESAR CLAVE: " ; 
    std::cin >> password;
    bool saveResponse;
    if(userType == 3){
        file = verifyIdRegisterByOption(_teacherFile);
        saveResponse = _teacherFile.save(Teacher(name, surname, document, email, password, phone, file, userType));
    } else{
        file = verifyIdRegisterByOption(_studentFile);
        saveResponse = _studentFile.save(Student(name, surname, document, email, password, phone, file, userType));
    }
    bool userResponse = _userLoginFile.save(UserLogin(password, file, userType));
    system("pause");
};
void Administrator::editStaff() {
    
};
void Administrator::withdrawStaff(int userType) {
    (userType == 3) ? withdrawRegisterByOption(_teacherFile, "user") : withdrawRegisterByOption(_studentFile, "user");
};
void Administrator::reEnrollStaff(int userType){
    (userType == 3) ? reEnrollRegisterByOption(_teacherFile, "user") : reEnrollRegisterByOption(_studentFile, "user");
};
void Administrator::verifyInformation(int userType) {
    (userType == 3) ? searchRegisterByOption(_teacherFile) : searchRegisterByOption(_studentFile);
};
void Administrator::listStaff(int userType) {
    (userType == 3) ? listRegisterByOption(_teacherFile) : listRegisterByOption(_studentFile);
};
void Administrator::listNotices() {
    listRegisterByOption(_noticeFile);
};
void Administrator::assignNoteStudent() {

};
void Administrator::editStudentNote() {

};
void Administrator::postNotice() {
    std::string title; 
    std::string content;
    int id;
    int day;
    int month;
    int year;
    std::cout << "INGRESAR FECHA AVISO: " << std::endl;
    std::cout << "DIA: ";
    std::cin >> day;
    std::cout << "MES: ";
    std::cin >> month;
    std::cout << "ANIO: ";
    std::cin >> year;
    system("cls");
    std::cout << "INGRESAR TITULO AVISO: ";
    std::cin.ignore();
    getline(std::cin, title);
    system("cls");
    std::cout << "INGRESAR DESCRIPCION AVISO: ";
    getline(std::cin, content);
    id = verifyIdRegisterByOption(_noticeFile);
    bool response = _noticeFile.save(Notice(Fecha(day, month, year), title, content, id));
    system("pause");
};
void Administrator::withdrawNotice(){
    withdrawRegisterByOption(_noticeFile, "resource");
    system("pause");
};
void Administrator::editNotice(){
    
};
void Administrator::show(){
    std::cout << "LEGAJO         : " << getId() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
};
void Administrator::showGenericMenu(int userType){
    int selectedOption;
    do {
    system("cls");
    std::cout << "1 - REGISTRAR" << std::endl;
    std::cout << "2 - ELIMINAR" << std::endl;
    std::cout << "3 - RECUPERAR" << std::endl;
    std::cout << "4 - BUSCAR" << std::endl;
    std::cout << "5 - LISTA REGISTROS" << std::endl;
    if(userType == 3){
        showMenuTeacher();
    } else{
        showMenuStudent();
    }
    std::cout << "0 - VOLVER" << std::endl;
    std::cin >> selectedOption;
    system("cls");
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
    std::cout << "8 - GENERAR CERTIFICADO EXAMEN" << std::endl;
};
void Administrator::showMenuNotice(){
    int selectedOption;
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                               MENU AVISOS                               " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - EDITAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - LISTA REGISTROS" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendNoticeRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::showMenuComission(){
    int selectedOption;
    do {
        system("cls");
        std::cout << "=========================================================================" << std::endl;
        std::cout << "                               MENU COMISION                             " << std::endl;
        std::cout << "=========================================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - EDITAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - RECUPERAR" << std::endl;
        std::cout << "5 - BUSCAR" << std::endl;
        std::cout << "6 - LISTA REGISTROS" << std::endl;
        std::cout << "7 - ASIGNAR MATERIA A COMISION" << std::endl;
        std::cout << "8 - MOSTRAR MATERIAS SEGUN COMISION" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendComissionRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::sendUserTypeRequest(int selectedOption, int userType) {
    switch(selectedOption) {
        case 3: sendTeacherRequest(selectedOption);
            break;
        case 4: sendStudentRequest(selectedOption);
            break;
        default: sendGenericRequest(selectedOption, userType);
            break;
    }
};
void Administrator::sendGenericRequest(int selectedOption, int userType) {
    switch(selectedOption) {
        case 1: registerStaff(userType);
            break;
        case 2: withdrawStaff(userType);
            break;
        case 3: reEnrollStaff(userType);
            break;
        case 4: verifyInformation(userType);
            break;
        case 5: listStaff(userType);
            break;
    }
};
void Administrator::sendTeacherRequest(int selectedOption) {
    switch(selectedOption) {
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
    }
};
void Administrator::sendStudentRequest(int selectedOption) {
    switch(selectedOption) {
        case 6:
            break;
        case 7:
            break;
        case 8: generateCertificate();
            break;
    }
};
void Administrator::sendNoticeRequest(int selectedOption){
switch(selectedOption) {
        case 1: postNotice();
            break;
        case 2: editNotice();
            break;
        case 3: withdrawNotice();
            break;
        case 4: listNotices();
            break;
    }
};
void Administrator::sendComissionRequest(int selectedOption) {
    switch(selectedOption) {
        case 1: registerComission();
            break;
        case 2: editComission();
            break;
        case 3: withdrawRegisterByOption(_comissionFile, "resource");
            break;
        case 4: reEnrollRegisterByOption(_comissionFile, "resource");
            break;
        case 5: searchRegisterByOption(_comissionFile);
            break;
        case 6: listRegisterByOption(_comissionFile);
            break;
        case 7: setResourceRelationship(_subjectFile, _comissionFile, _subjectXComissionFile, SubjectXComission(), "MATERIA", "COMISION");
            break;
        case 8: showFirstResourcesBySecondResources(_subjectFile, _comissionFile, _subjectXComissionFile, SubjectXComission(), Subject(), Comission(), "MATERIAS", "COMISION");
            break;
    }
};
void Administrator::registerComission(){
    int modality;
    int id;
    int turn;
    int year;
    int fourthQuarter;

    std::cout << "=========================================================================" << std::endl;
    std::cout << "                           INFORMACION REGISTRO                          " << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "* TIPO MODALIDAD" << std::endl;    
    std::cout << "1- PRESENCIAL" << std::endl;
    std::cout << "2- VIRTUAL" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> modality;
    std::cout << std::endl;    
    std::cout << "* TURNO DE CURSADA" << std::endl;
    std::cout << "1- MANIANA" << std::endl;
    std::cout << "2- NOCHE" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> turn;
    std::cout << std::endl; 
    std::cout << "* INGRESAR ANIO DE COMISION: ";
    std::cin >> year;
    std::cout << std::endl; 
    std::cout << "* INGRESAR CUATRIMESTRE: " << std::endl;
    std::cout << "1- PRIMER CUATRIMESTRE" << std::endl;
    std::cout << "2- SEGUNDO CUATRIMESTRE" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> fourthQuarter;
    std::cout << std::endl; 
    id = verifyIdRegisterByOption(_comissionFile);
    bool response = _comissionFile.save(Comission(id, modality, turn, year, fourthQuarter));
    system("pause");
};
void Administrator::editComission(){
};
void Administrator::generateCertificate() {
    int id;
    
    std::cout << "GENERANDO CERTIFICADO.." << std::endl;
    std::cout << "INGRESAR ID DE ALUMNO: ";
    std::cin >> id;
    
};