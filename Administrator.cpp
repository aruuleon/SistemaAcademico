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
        std::cout << "MENU ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - PROFESOR " << std::endl;
        std::cout << "2 - ALUMNO" << std::endl;
        std::cout << "3 - AVISOS" << std::endl;
        std::cout << "4 - COMISION" << std::endl;
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
    std::cout << "REGISTRANDO STAFF.." << std::endl;
    std::cout << "INGRESAR NOMBRE: " << std::endl;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "INGRESAR APELLIDO: " << std::endl;
    getline(std::cin, surname);
    std::cout << "INGRESAR DNI: " << std::endl;
    std::cin >>  document; 
    std::cout << "INGRESAR CORREO: " << std::endl; 
    std::cin >>  email;
    std::cout << "INGRESAR TELEFONO: " << std::endl; 
    std::cin >>  phone;
    std::cout << "INGRESAR CLAVE: " << std::endl; 
    std::cin >> password;
    bool saveResponse;
    if(userType == 3){
        file = verifyIdRegisterByOption(_teacherFile);
        std::cout << "REGISTRANDO PROFESOR..." << std::endl;
        saveResponse = _teacherFile.save(Teacher(name, surname, document, email, password, phone, file, userType));
    } else{
        file = verifyIdRegisterByOption(_studentFile);
        std::cout << "REGISTRANDO ALUMNO..." << std::endl;
        saveResponse = _studentFile.save(Student(name, surname, document, email, password, phone, file, userType));
    }
    bool userResponse = _userLoginFile.save(UserLogin(password, file, userType));
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
    std::cout << "INGRESAR FECHA AVISO: ";
    std::cout << "DIA: ";
    std::cin >> day;
    std::cout << "MES: ";
    std::cin >> month;
    std::cout << "ANIO: ";
    std::cin >> year;
    std::cout << "INGRESAR TITULO AVISO: ";
    std::cin.ignore();
    getline(std::cin, title);
    std::cout << "INGRESAR DESCRIPCION AVISO: ";
    getline(std::cin, content);
    id = verifyIdRegisterByOption(_noticeFile);
    bool response = _noticeFile.save(Notice(Fecha(day, month, year), title, content, id));
};
void Administrator::withdrawNotice(){
    withdrawRegisterByOption(_noticeFile, "resource");
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
        std::cout << "4 - MOSTRAR LISTA AVISOS" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        sendNoticeRequest(selectedOption);
    } while(selectedOption != 0);
};
void Administrator::showMenuComission(){
    int selectedOption;
    do {
        std::cout << "MENU COMISION" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - REGISTRAR COMISION " << std::endl;
        std::cout << "2 - EDITAR COMISION" << std::endl;
        std::cout << "3 - ELIMINAR COMISION" << std::endl;
        std::cout << "4 - DAR DE ALTA COMISION" << std::endl;
        std::cout << "5 - MOSTRAR INFORMACION COMISION" << std::endl;
        std::cout << "6 - MOSTRAR LISTA COMISION" << std::endl;
        std::cout << "7 - ASIGNAR MATERIA A COMISION" << std::endl;
        std::cout << "8 - MOSTRAR MATERIAS SEGUN COMISION" << std::endl;
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        sendComissionRequest(selectedOption);
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
        case 3: withdrawComission();
            break;
        case 4: reEnrollComission();
            break;
        case 5: verifyInformationComission();
            break;
        case 6: listComissions();
            break;
        case 7: assignSubjectToComission();
            break;
        case 8: showSubjectsByComission();
            break;
    }
};
void Administrator::registerComission(){
    int modality;
    int id;
    int turn;
    int year;
    int fourthQuarter;

    std::cout << "REGISTRANDO COMISION" << std::endl;
    std::cout << "TIPO MODALIDAD" << std::endl;    
    std::cout << "1- PRESENCIAL" << std::endl;
    std::cout << "2- VIRTUAL" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> modality;    
    std::cout << "TURNO DE CURSADA" << std::endl;
    std::cout << "1- MANIANA" << std::endl;
    std::cout << "2- NOCHE" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> turn;
    std::cout << "INGRESAR ANIO DE COMISION: ";
    std::cin >> year;
    std::cout << "INGRESAR CUATRIMESTRE: " << std::endl;
    std::cout << "1- PRIMER CUATRIMESTRE" << std::endl;
    std::cout << "2- SEGUNDO CUATRIMESTRE" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> fourthQuarter;
    id = verifyIdRegisterByOption(_comissionFile);
    bool response = _comissionFile.save(Comission(id, modality, turn, year, fourthQuarter));
};
void Administrator::editComission(){
};
void Administrator::withdrawComission(){
    withdrawRegisterByOption(_comissionFile, "resource");
};
void Administrator::reEnrollComission(){
    reEnrollRegisterByOption(_comissionFile, "resource");
};
void Administrator::verifyInformationComission(){
    searchRegisterByOption(_comissionFile);
};
void Administrator::listComissions(){
    listRegisterByOption(_comissionFile);
};
void Administrator::assignSubjectToComission(){
    int comissionId;
    int subjectId;
    bool checkRelationship = false;
    int position = 0;
    int numberOfRecords = _subjectXComissionFile.numberOfRecords();
    std::cout << "INGRESAR ID DE ALGUNA DE ESTAS COMISIONES A LA QUE DESEA ASIGNAR MATERIA: " << std::endl;
    if(_comissionFile.numberOfActiveRecords() > 0){
        listRegisterByOption(_comissionFile);
        std::cin >> comissionId;
        std::cout << "INGRESAR ID DE ALGUNA DE ESTAS MATERIAS A ASIGNAR: " << std::endl;
        if(_subjectFile.numberOfActiveRecords() > 0){
            listRegisterByOption(_subjectFile);
            std::cin >> subjectId;
            while(!checkRelationship && position < numberOfRecords){
                SubjectXComission subjectXComission = _subjectXComissionFile.read(position);
                if(subjectXComission.getSubjectId() == subjectId && subjectXComission.getComissionId() == comissionId){
                    checkRelationship = true;
                }
                position ++;
            }
            if(!checkRelationship){
                _subjectXComissionFile.save(SubjectXComission(subjectId, comissionId));
                std::cout << "LA MATERIA SE ASIGNO CORRECTAMENTE A LA COMISION" <<  std::endl;
            } else {
                std::cout << "LA MATERIA QUE INTENTA AGREGAR, YA SE ENCUENTRA ASIGNADA A LA COMISION" << std::endl;
            }
        }
    }
};
void Administrator::showSubjectsByComission(){
    int id;
    std::cout << "INGRESAR ID DE LA COMISION" << std::endl;
    std::cin >> id;
    int position = _comissionFile.searchRecord(id);
    Comission comission = _comissionFile.read(position);
    int numberOfRecordsRelationship = _subjectXComissionFile.numberOfRecords();
    int numberOfRecordsSubjects = _subjectFile.numberOfRecords();
    std::cout << "COMISION: " << comission.getId() << std::endl;
    std::cout << "MATERIAS CORRESPONDIENTES: " << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i ++) {
        SubjectXComission subjectXComission = _subjectXComissionFile.read(i);
        if(subjectXComission.getComissionId() == comission.getId()) {
            for(int j = 0; j < numberOfRecordsSubjects; j ++) {
                Subject subject = _subjectFile.read(j);
                if(subject.getState() && subject.getId() == subjectXComission.getSubjectId()) {
                    subject.show();
                }
            }
        }
    }
};
