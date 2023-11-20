#include "Administrator.h"
#include "TeacherFile.h"
#include "StudentFile.h"
#include "Functions.h"
#include "UserLoginFile.h"
#include "Fecha.h"
#include "NoticeFile.h"

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
        std::cout << "3 - AVISOS" << std::endl;
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
        case 3: showMenuNotice();
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
    file = verifyFile(userType);
    bool saveResponse;
    if(userType == 3){
        std::cout << "REGISTRANDO PROFESOR..." << std::endl;
        TeacherFile teacherFile("teachers.dat");
        saveResponse = teacherFile.save(Teacher(name, surname, document, email, password, phone, file, userType));
    } else{
        std::cout << "REGISTRANDO ALUMNO..." << std::endl;
        StudentFile studentFile("students.dat");
        saveResponse = studentFile.save(Student(name, surname, document, email, password, phone, file, userType));
    }
    UserLoginFile userLoginFile ("usersLogin.dat");
    bool userResponse = userLoginFile.save(UserLogin(password, file, userType));
};
void Administrator::editStaff() {
};
void Administrator::withdrawStaff(int userType) {
    (userType == 3) ? withdrawTeacher() : withdrawStudent();
};
void Administrator::reEnrollStaff(int userType){
    (userType == 3) ? reEnrollTeacher() : reEnrollStudent();
};
void Administrator::verifyInformation(int userType) {
    (userType == 3) ? searchTeacher() : searchStudent();
};
void Administrator::listStaff(int userType) {
    (userType == 3) ? listTeachers() : listStudents();
};
void Administrator::assignNoteStudent() {

};
void Administrator::editStudentNote() {

};
void Administrator::postNotice() {
    std::string title; 
    std::string content;
    int code;
    int day;
    int month;
    int year;
    std::cout << "INGRESAR FECHA AVISO: ";
    std::cout << "DIA: ";
    std::cin >> day;
    std::cout << "MES: ";
    std::cin >> month;
    std::cout << "ANIO: ";
    std::cin >> year;
    std::cout << "INGRESAR TITULO AVISO: ";
    std::cin >> title;
    std::cout << "INGRESAR DESCRIPCION AVISO: ";
    std::cin >> content;  
    code = verifyCodeNotice();
    NoticeFile noticeFile("notices.dat");
    bool response = noticeFile.save(Notice(Fecha(day, month, year), title, content, code));
};
void Administrator::withdrawNotice(){
    withDrawNotice();
};
void Administrator::editNotice(){
    
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
void Administrator::showMenuNotice(){
    int selectedOption;
    do {
        std::cout << "MENU AVISOS" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - SUBIR AVISO " << std::endl;
        std::cout << "2 - EDITAR AVISO" << std::endl;
        std::cout << "3 - DAR DE BAJA AVISO" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        sendNoticeRequest(selectedOption);
    } while(selectedOption != 0);
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
        case 0: logout();
            break;
    }
};
void Administrator::sendNoticeRequest(int selectedOption){
switch(selectedOption) {
        case 1: postNotice();
            break;
        case 2: withdrawNotice();
            break;
        case 3: editNotice();
            break;
        //case 0: logout();
        //    break;
    }
};

int Administrator::verifyFile(int userType){
    int generatedFile;
    if(userType == 3){
        generatedFile = verifyFileTeachers();
    } else{
        generatedFile = verifyFileStudents();
    }    
    return generatedFile;
};