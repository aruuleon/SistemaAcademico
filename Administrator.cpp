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
    if(userType == 3){
        file = verifyIdRegisterByOption(_teacherFile);
        _teacherFile.save(Teacher(name, surname, document, email, password, phone, file, userType));
    } else{
        std::cout << "INGRESAR ID CARRERA A LA QUE SE VA A INSCRIBIR EL ESTUDIANTE: ";
        int careerId;
        std::cin >> careerId;
        file = verifyIdRegisterByOption(_studentFile);
        _studentFile.save(Student(name, surname, document, email, password, phone, file, userType));
        _studentXCareerFile.save(StudentXCareer(file, careerId));
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
        sendUserTypeRequest(selectedOption, userType);
    } while(selectedOption != 0);
};
void Administrator::showMenuTeacher(){
    std::cout << "6 - ASIGNAR A MATERIA" << std::endl;
}
void Administrator::showMenuStudent(){
    std::cout << "6 - ASIGNAR NOTA" << std::endl;
    std::cout << "7 - MODIFICAR NOTA" << std::endl;
    std::cout << "8 - GENERAR EXAMEN" << std::endl;
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
    if(selectedOption >= 1 && selectedOption <= 5) {
        sendGenericRequest(selectedOption, userType);
    } else if(userType == 3) {
        sendTeacherRequest(selectedOption);
    } else {
        sendStudentRequest(selectedOption);
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
        case 6: assignTeacherToSubject();
            break;
    }
};
void Administrator::sendStudentRequest(int selectedOption) {
    switch(selectedOption) {
        case 6: assignGradeStudent();
            break;
        case 7: modifyGradeStudent();
            break;
        case 8: generateExam();
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
void Administrator::assignGradeStudent() {
    Subject subject;
    StudentXSubject studentXSubjets;
    int idStudent;
    int idExam;
    int grade;
    int idSubject;
    int day, month, year;
    int selectedOption;
    int numberOfRecordsRelationship = _studentXSubjectFile.numberOfRecords();
    bool response = false;
    bool attendance = false;
    GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat"); 
    GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");

    std::cout << "* ASIGNAR NOTA A ALUMNO *" << std::endl;
    std::cout << "INGRESAR EL LEGAJO DEL ALUMNO A ASIGNAR NOTA: ";
    std::cin >> idStudent;

    for(int i = 0; i < numberOfRecordsRelationship; i++){
        if(studentXSubjets.getFirstResourceId() == idStudent){
            subject.show();
        }
    }
    std::cout << "INGRESAR EL ID DE MATERIA A ASIGNAR LA NOTA: ";
    std::cin >> idSubject;
    std::cout << "INGRESE EL DIA DEL EXAMEN: ";
    std::cin >> day;
    std::cout << "INGRESE EL MES DEL EXAMEN: ";
    std::cin >> month;
    std::cout << "INGRESE EL ANIO DEL EXAMEN: ";
    std::cin >> year;
    idExam = verifyIdRegisterByOption(_examFile);
    std::cout << "EL ALUMNO SE PRESENTO A EL EXAMEN? " << std::endl;
    std::cout << "1- SI" << std::endl;
    std::cout << "2- NO" << std::endl;
    std::cin >> selectedOption;
    if(selectedOption == 1){
        std::cout << "INGRESE LA NOTA A ASIGNAR: ";
        std::cin >> grade;
        attendance = true;
    } else{
        grade = 0;
    }
    // if(_examFile.save(Exam (idExam, grade,Fecha(day, month, year))) && _examXStudentXSubjectFile.save(ExamXStudentXSubject(idExam, idStudent, idSubject, attendance))){
    //     std::cout << "SE GUARDO CORRECTAMENTE LA NOTA" << std::endl;
    // } else {
    //         std::cout << "NO SE PUDO GUARDAR LA NOTA" << std::endl;
    //     }
    system("pause");
};
void Administrator::modifyGradeStudent(){
    Exam exam;
    Subject subject;
    StudentXSubject studentXSubjets;
    int idStudent;
    int idExam;
    int grade;
    int idSubject;
    int selectedOption;
    int numberOfRecordsRelationship = _studentXSubjectFile.numberOfRecords();
    bool response = false;
    bool attendance = false;
    GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat"); 
    GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat");

    std::cout << "* MODIFICAR NOTA A ALUMNO *" << std::endl;
    std::cout << "INGRESAR EL LEGAJO DEL ALUMNO A MODIFICAR NOTA: ";
    std::cin >> idStudent;
    for(int i = 0; i < numberOfRecordsRelationship; i++){
        if(studentXSubjets.getFirstResourceId() == idStudent){
            subject.show();
        }
    }
    std::cout << "INGRESAR EL ID DE MATERIA A MODIFICAR LA NOTA: ";
    std::cin >> idSubject;
    std::cin >> selectedOption;
    std::cout << "INGRESE LA NOTA A MODIFICAR: ";
    std::cin >> grade;
    attendance = true;
    // exam.setGrade(grade);
    //_examFile.save(exam);
    if(_examFile.save((exam))){
        std::cout << "SE EDITO CORRECTAMENTE LA NOTA" << std::endl;
    } else {
            std::cout << "NO SE PUDO EDITAR LA NOTA" << std::endl;
        }
    system("pause");
};
void Administrator::generateExam() {
    GenericFile <Career> _careerFile = GenericFile <Career> ("careers.dat");
    GenericFile <Subject> _subjectFile = GenericFile <Subject> ("subjects.dat");
    GenericFile <SubjectXCareer> _subjectXCareerFile = GenericFile <SubjectXCareer> ("subjectsXCareers.dat");
    GenericFile <ExamXSubject> _examXSubjectFile = GenericFile <ExamXSubject> ("examsXSubjects.dat");
    int numberOfRecordsRelationship = _subjectXCareerFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    int careerId;
    int subjectId;
    int examId;

    std::cout << "GENERACION DE EXAMEN" << std::endl;
    std::cout << std::endl;
    listRegisterByOption(_careerFile);
    std::cout << "INGRESAR ID DE CARRERA:";
    std::cin >> careerId;
    for(int i = 0; i < numberOfRecordsSubject; i++) {
        Subject subject = _subjectFile.read(i);
        for(int j = 0; j < numberOfRecordsRelationship; j++) {
            SubjectXCareer subjectXCareer = _subjectXCareerFile.read(j);
            if(subjectXCareer.getSecondResourceId() == careerId && subject.getState() && subjectXCareer.getFirstResourceId() == subject.getId()) {
                subject.show();
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
    std::cout << "INGRESAR ID DE MATERIA A LA QUE PERTENECE EL EXAMEN: ";
    std::cin >> subjectId;
    examId = verifyIdRegisterByOption(_examFile);
    if(_examXSubjectFile.save(ExamXSubject(examId, subjectId))) std::cout << "EXAMEN GENERADO CORRRECTAMENTE" << std::endl;
};
void Administrator::assignTeacherToSubject() {
    GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
    int teacherId;
    int subjectId;
    int numberOfRecordsRelationship = _teacherXSubjectFile.numberOfRecords();
    int numberOfRecordsComission = _comissionFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    
    std::cout << "* ASIGNAR PROFESOR A MATERIA *" << std::endl;
    showSubjects(numberOfRecordsRelationship, numberOfRecordsSubject, numberOfRecordsComission);
    std::cout << "INGRESAR EL ID DE MATERIA A ASIGNAR: ";
    std::cin >> subjectId;
    std::cout << "INGRESAR EL LEGAJO DEL PROFESOR: ";
    std::cin >> teacherId;
    std::cout << std::endl;
    finishAssignmentProcess(numberOfRecordsRelationship, numberOfRecordsSubject, subjectId, teacherId);
    system("pause");
};
void Administrator::showSubjects(int numberOfRecordsRelationship, int numberOfRecordsSubject, int numberOfRecordsComission) {
    for(int i = 0; i < numberOfRecordsSubject; i++) {
        Subject subject = _subjectFile.read(i);
        for(int j = 0; j < numberOfRecordsComission; j++) {
            subject.show();
        }
    }
};
void Administrator::finishAssignmentProcess(int numberOfRecordsRelationship, int numberOfRecordsSubject, int subjectId, int teacherId) {
        GenericFile <TeacherXSubject> _teacherXSubjectFile = GenericFile <TeacherXSubject> ("teachersXSubjects.dat");
        int positionRelationship = 0;
        bool relationshipFound = false;
        while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
            TeacherXSubject teacherXSubject = _teacherXSubjectFile.read(positionRelationship);
            if(teacherXSubject.getSecondResourceId() == subjectId) {
                relationshipFound = true;
            }
            positionRelationship++;
        }
        if(!relationshipFound) {
            _teacherXSubjectFile.save(TeacherXSubject(teacherId, subjectId));
            std::cout << "EL PROFESOR FUE ASIGNADO A LA MATERIA CORRECTAMENTE" << std::endl;
        } else {
            std::cout << "ESTA MATERIA YA TIENE UN PROFESOR ASIGNADO A LA MISMA" << std::endl;
        }
};