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
        std::cout << "1 - MATERIAS ASIGNADAS" << std::endl;
        std::cout << "2 - EDICION" << std::endl;
        std::cout << "3 - INFORMACION PERSONAL" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        system("cls");
        sendRequest(teacher, selectedOption);
    } while(selectedOption != 0);
};
void Teacher::sendRequest(Teacher teacher, int selectedOption) {
    switch(selectedOption) {
        case 1: showAssignedSubjects(teacher);
            break;
        case 2: editInformation(teacher);
            break;
        case 3: showPersonalInformation(teacher);
            break;
        case 0: logout();
            break;
    }
};
void Teacher::showAssignedSubjects(Teacher teacher) {
    int numberOfRecordsRelationship = _teacherXSubjectFile.numberOfRecords();
    int numberOfRecordsSubject = _subjectFile.numberOfRecords();
    std::cout << "MATERIAS DEL PROFESOR" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i++) {
        TeacherXSubject teacherXSubject = _teacherXSubjectFile.read(i);
        if(teacherXSubject.getFirstResourceId() == teacher.getId()){
            for(int i = 0; i < numberOfRecordsSubject; i++) {
                Subject subject = _subjectFile.read(i);
                if(subject.getState() && subject.getId() == teacherXSubject.getSecondResourceId()) {
                    subject.show();
                    std::cout << "=========================================" << std::endl;
                }
            }
        }
    }
    system("pause");
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
        case 1: editRegisterByOption(_teacherFile, teacher, "EMAIL");
            break;
        case 2: editRegisterByOption(_teacherFile, teacher, "PHONE");
            break;
        case 3: editRegisterByOption(_teacherFile, teacher, "PASSWORD");
            break;
    }
};
void Teacher::showPersonalInformation(Teacher teacher) {
    teacher.show();
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