#include "SuperAdministrator.h"
#include "Functions.h"

SuperAdministrator::SuperAdministrator() {

};
SuperAdministrator::SuperAdministrator(std::string name, std::string surname, std::string document, std::string email, std::string password, std::string phone, int id, int userType)
:FacultyStaff(name, surname, document, email, password, phone, id, userType) {
};
void SuperAdministrator::showMenu() {
    int selectedOption;
    do {
        std::cout << "MENU SUPER ADMINISTRADOR" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - ADMINISTRADOR" << std::endl;
        std::cout << "2 - CARRERA" << std::endl;
        std::cout << "3 - MATERIA" << std::endl;
        std::cout << "0 - CERRAR SESION" << std::endl;
        std::cin >> selectedOption;
        sendRequest(selectedOption);
    } while(selectedOption != 0);
};
void SuperAdministrator::sendRequest(int selectedOption) {
    if(selectedOption != 0) {
        showGenericMenu(selectedOption);
    } else {
        logout();
    }
};
void SuperAdministrator::showGenericMenu(int optionReceived) {
    int selectedOption;
    do {
        std::cout << "1 - REGISTRAR" << std::endl;
        std::cout << "2 - EDITAR" << std::endl;
        std::cout << "3 - ELIMINAR" << std::endl;
        std::cout << "4 - VOLVER A DAR DE ALTA" << std::endl;
        std::cout << "5 - MOSTRAR INFORMACION" << std::endl;
        std::cout << "6 - MOSTRAR LISTA" << std::endl;
        if(optionReceived == 2) {
            std::cout << "7 - ASIGNAR MATERIA A CARRERA" << std::endl;
            std::cout << "8 - MOSTRAR MATERIAS SEGUN CARRERA" << std::endl;
        }
        std::cout << "0 - VOLVER" << std::endl;
        std::cin >> selectedOption;
        sendGenericRequest(optionReceived, selectedOption);
    } while(selectedOption != 0);
};
void SuperAdministrator::sendGenericRequest(int optionReceived, int selectedOption) {
    switch(selectedOption) {
        case 1: registerByOption(optionReceived);
            break;
        case 2: editByOption(optionReceived);
            break;
        case 3: withdrawByOption(optionReceived);
            break;
        case 4: reEnrollByOption(optionReceived);
            break;
        case 5: searchByOption(optionReceived);
            break;
        case 6: listByOption(optionReceived);
            break;
        case 7: assignSubjectToCareer();
            break;
        case 8: showSubjectsByCareer();
        break;

    }
};
void SuperAdministrator::registerByOption(int optionReceived)  {
    switch(optionReceived) {
        case 1: registerAdministrator();
            break;
        case 2: registerCareer();
            break;
        case 3: registerSubject();
            break;
    }
};
void SuperAdministrator::editByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: editAdministrator();
            break;
        case 2: editCareer();
            break;
        case 3: editSubject();
            break;
    }
};
void SuperAdministrator::withdrawByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: withdrawRegisterByOption(_administratorFile, "user");
            break;
        case 2: withdrawCareer(withdrawRegisterByOption(_careerFile, "resource"));
            break;
        case 3: withdrawSubject(withdrawRegisterByOption(_subjectFile, "resource"));
            break;
    }
};
void SuperAdministrator::reEnrollByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: reEnrollRegisterByOption(_administratorFile, "user");
            break;
        case 2: reEnrollRegisterByOption(_careerFile, "resource");
            break;
        case 3: reEnrollRegisterByOption(_subjectFile, "resource");
            break;
    }
};
void SuperAdministrator::searchByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: searchRegisterByOption(_administratorFile);
            break;
        case 2: searchRegisterByOption(_careerFile);
            break;
        case 3: searchRegisterByOption(_subjectFile);
            break;
    }
};
void SuperAdministrator::listByOption(int optionReceived) {
    switch(optionReceived) {
        case 1: listRegisterByOption(_administratorFile);
            break;
        case 2: listRegisterByOption(_careerFile);
            break;
        case 3: listRegisterByOption(_subjectFile);
            break;
    }
};
void SuperAdministrator::assignSubjectToCareer(){
    int careerId;
    int subjectId;
    bool checkRelationship = false;
    int position = 0;
    int numberOfRecords = _subjectXCareerFile.numberOfRecords();
    std::cout << "INGRESAR ID DE ALGUNA DE ESTAS CARRERAS A LA QUE DESEA ASIGNAR MATERIA: " << std::endl;
    if(_careerFile.numberOfActiveRecords() > 0){
        listRegisterByOption(_careerFile);
        std::cin >> careerId;
        std::cout << "INGRESAR ID DE ALGUNA DE ESTAS MATERIAS A ASIGNAR: " << std::endl;
        if(_subjectFile.numberOfActiveRecords() > 0){
            listRegisterByOption(_subjectFile);
            std::cin >> subjectId;
            while(!checkRelationship && position < numberOfRecords){
                SubjectXCareer subjectXCareer = _subjectXCareerFile.read(position);
                if(subjectXCareer.getSubjectId() == subjectId && subjectXCareer.getCareerId() == careerId){
                    checkRelationship = true;
                }
                position ++;
            }
            if(!checkRelationship){
            _subjectXCareerFile.save(SubjectXCareer(subjectId, careerId));
            std::cout << "LA MATERIA SE ASIGNO CORRECTAMENTE A LA CARRERA" <<  std::endl; 
            } else {
                std::cout << "LA MATERIA QUE INTENTA AGREGAR, YA SE ENCUENTRA ASIGNADA A LA CARRERA" << std::endl;
            }
            
        }
    }
};
void SuperAdministrator::withdrawSubject(int id) {
    int position = _subjectFile.searchRecord(id);
    Subject subject = _subjectFile.read(position);
    int numberOfRecords = _subjectXCareerFile.numberOfRecords();
    for(int i = 0; i < numberOfRecords; i ++) {
        SubjectXCareer subjectXCareer = _subjectXCareerFile.read(i);
        if(subjectXCareer.getSubjectId() == subject.getId()) {
            subjectXCareer.setState(false);
            _subjectXCareerFile.save(subjectXCareer, i);
        }
    }  
};
void SuperAdministrator::withdrawCareer(int id) {
    int position = _careerFile.searchRecord(id);
    Career career = _careerFile.read(position);
    int numberOfRecords = _subjectXCareerFile.numberOfRecords();
    for(int i = 0; i < numberOfRecords; i ++) {
        SubjectXCareer subjectXCareer = _subjectXCareerFile.read(i);
        if(subjectXCareer.getCareerId() == career.getId()) {
            subjectXCareer.setState(false);
            _subjectXCareerFile.save(subjectXCareer, i);
        }
    }    
};
void SuperAdministrator::showSubjectsByCareer() {
    int id;
    std::cout << "INGRESAR ID DE LA CARRERA" << std::endl;
    std::cin >> id;
    int position = _careerFile.searchRecord(id);
    Career career = _careerFile.read(position);
    int numberOfRecordsRelationship = _subjectXCareerFile.numberOfRecords();
    int numberOfRecordsSubjects = _subjectFile.numberOfRecords();
    std::cout << "CARRERA: " << career.getName() << std::endl;
    std::cout << "MATERIAS CORRESPONDIENTES: " << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i ++) {
        SubjectXCareer subjectXCareer = _subjectXCareerFile.read(i);
        if(subjectXCareer.getCareerId() == career.getId()) {
            for(int j = 0; j < numberOfRecordsSubjects; j ++) {
                Subject subject = _subjectFile.read(j);
                if(subject.getState() && subject.getId() == subjectXCareer.getSubjectId()) {
                    subject.show();
                }
            }
        }
    }
};
void SuperAdministrator::show(){
    std::cout << "LEGAJO         : " << getId() << std::endl; 
    std::cout << "NOMBRE         : " << getName() << std::endl;
    std::cout << "APELLIDO       : " << getSurname() << std::endl;
    std::cout << "DOCUMENTO      : " << getDocument() << std::endl; 
    std::cout << "CLAVE          : " << getPassword() << std::endl; 
    std::cout << "MAIL           : " << getEmail() << std::endl; 
    std::cout << "TELEFONO       : " << getPhone() << std::endl; 
    std::cout << "TIPO DE USUARIO: " << getUserType() << std::endl; 
};