#pragma once
#include <string>
#include <cstring>
#include "GenericFile.h"
#include "Administrator.h"
#include "UserLogin.h"

void registerAdministrator();
void registerCareer();
void registerSubject();

void editAdministrator();
void editCareer();
void editSubject();

template <class T>
void listRegisterByOption(GenericFile<T> file) {
    int numberOfRecords = file.numberOfRecords();
    if(file.numberOfActiveRecords()) {
        std::cout << "=========================================================================" << std::endl;
        std::cout << "=========================================================================" << std::endl;
        for(int i = 0; i < numberOfRecords; i++) {
            if(file.read(i).getState()) {
                file.read(i).show();
                std::cout << "=========================================================================" << std::endl;
            }
        }
        std::cout << "=========================================================================" << std::endl;
    } else {
        std::cout << "NO SE ENCUENTRAN REGISTROS EN ESTE MOMENTO" << std::endl;
    }
    system("pause");
};
template <typename FacultyStaffFile, typename FacultyStaff>
void editRegisterByOption(FacultyStaffFile facultyStaffFile, FacultyStaff facultyStaff, std::string field) {
    int positionFacultyStaff  = facultyStaffFile.searchRecord(facultyStaff.getId());
    std::string newValue;
    
    std::cout << field << " ACTUAL: ";
    if(field == "EMAIL") {
        std::cout << facultyStaff.getEmail() << std::endl;   
    } else if(field == "PHONE") {
        std::cout << facultyStaff.getPhone() << std::endl;
    } else {
        std::cout << facultyStaff.getPassword() << std::endl;
    }
    std::cin.ignore();
    std::cout << "INGRESAR NUEVO " << field << ": ";
    std::getline(std::cin, newValue);
    editValueByOption(facultyStaffFile, facultyStaff, positionFacultyStaff, field, newValue);
};
template <typename FacultyStaffFile, typename FacultyStaff>
void editValueByOption(FacultyStaffFile facultyStaffFile, FacultyStaff facultyStaff, int positionFacultyStaff, std::string field, std::string newValue) {
    if(field == "EMAIL") {
        facultyStaff.setEmail(newValue);
    } else if(field == "PHONE") {
        facultyStaff.setPhone(newValue);
    } else {
        facultyStaff.setPassword(newValue);
    }
    facultyStaffFile.save(facultyStaff, positionFacultyStaff);
};
template <class T>
void searchRegisterByOption(GenericFile<T> file) {
    int id;

    std::cout << "INGRESAR LEGAJO A BUSCAR: ";
    std::cin >> id;
    int position = file.searchRecord(id);
    if(position != -1 && file.read(position).getState()) {
        file.read(position).show();
    } else {
        std::cout << "EL REGISTRO CON ID '" << id << "' NO FUE ENCONTRADO" << std::endl;
    }
    system("pause");
};
template <class T>
int verifyIdRegisterByOption(GenericFile<T> file) {
    int generatedFile;
    int numberOfRecords = file.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = file.read(numberOfRecords - 1).getId() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
};
template <class T>
int withdrawRegisterByOption(GenericFile<T> file, std::string optionReceived) {
    char optionCompare[20];
    int id;
    bool response;
    int idRegister;
    strcpy(optionCompare, optionReceived.c_str());

    std::cout << "INGRESAR ID DE REGISTRO A ELIMINAR: ";
    std::cin >> id;
    if(strcmp(optionCompare, "user") == 0) {
        GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
        response = file.addOrDelete(id, 2) && userLoginFile.addOrDelete(id, 2);
    } else {
        response = file.addOrDelete(id, 2);
    }
    if(response) {
        idRegister = id;
        std::cout << "EL REGISTRO CON ID '" << id << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        idRegister = -1;
        std::cout << "ERROR AL ELIMINAR REGISTRO" << std::endl;
    }
    system("pause");
    return idRegister;
};
template <class T>
void reEnrollRegisterByOption(GenericFile<T> file, std::string optionReceived) {
    char optionCompare[20];
    int id;
    bool response;

    strcpy(optionCompare, optionReceived.c_str());

    std::cout << "INGRESAR ID DE REGISTRO A DAR DE ALTA NUEVAMENTE: ";
    std::cin >> id;
    if(strcmp(optionCompare, "user") == 0) {
        GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
        response = file.addOrDelete(id, 1) && userLoginFile.addOrDelete(id, 1);
    } else {
        response = file.addOrDelete(id, 1);
    }
    if(response) {
        std::cout << "EL REGISTRO CON ID '" << id << "' SE RECUPERO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL RECUPERAR REGISTRO" << std::endl;
    }
    system("pause");
};
template <typename FirstResourceFile, typename SecondResourceFile, typename ResourseRelationshipFile, typename ResourceRelationship>
void setResourceRelationship(FirstResourceFile firstResourceFile, SecondResourceFile secondResourceFile, ResourseRelationshipFile resourseRelationshipFile, ResourceRelationship resourseRelationship, std::string nameFirstResource, std::string nameSecondResource) {
    if(secondResourceFile.numberOfActiveRecords() > 0) {
        int secondResourceId;
        listRegisterByOption(secondResourceFile);
        std::cout << "INGRESAR ID DE ALGUNA " << nameSecondResource << " A LA QUE DESEA ASIGNAR UNA " << nameFirstResource << ": ";
        std::cin >> secondResourceId;
        if(firstResourceFile.numberOfActiveRecords() > 0) {
            int firstResourceId;
            listRegisterByOption(firstResourceFile);
            std::cout << "INGRESAR ID DE ALGUNA " << nameFirstResource << " A ASIGNAR: ";
            std::cin >> firstResourceId;
            verifyCheckRelationship(resourseRelationshipFile, resourseRelationship, firstResourceId, secondResourceId, nameFirstResource, nameSecondResource);
        } else {
            std::cout << "NO SE ENCUENTRAN REGISTROS DE " << nameFirstResource << " EN ESTE MOMENTO" << std::endl;
        }
    } else {
        std::cout << "NO SE ENCUENTRAN REGISTROS DE " << nameSecondResource << " EN ESTE MOMENTO" << std::endl;
    }
    system("pause");
};
template <typename ResourseRelationshipFile, typename ResourseRelationship>
void verifyCheckRelationship(ResourseRelationshipFile resourseRelationshipFile, ResourseRelationship resourseRelationship, int firstResourceId, int secondResourceId, std::string nameFirstResource, std::string nameSecondResource) {
    int position = 0;
    bool checkRelationship = false;
    int numberOfRecords = resourseRelationshipFile.numberOfRecords();
    while(!checkRelationship && position < numberOfRecords){
        resourseRelationship = resourseRelationshipFile.read(position);
        if(resourseRelationship.getFirstResourceId() == firstResourceId && resourseRelationship.getSecondResourceId() == secondResourceId){
            checkRelationship = true;
        }
        position ++;
    }
    if(!checkRelationship) {
        resourseRelationshipFile.save(ResourseRelationship(firstResourceId, secondResourceId));
        std::cout << "LA " << nameFirstResource << " SE ASIGNO CORRECTAMENTE A LA " << nameSecondResource << std::endl;
    } else {
        std::cout << "LA " << nameFirstResource << " QUE INTENTA AGREGAR, YA SE ENCUENTRA ASIGNADA A LA " << nameSecondResource << std::endl;
    }
};
template <typename FirstResourceFile, typename SecondResourceFile, typename ResourseRelationshipFile, typename ResourceRelationship, typename FirstResource, typename SecondResource>
void showFirstResourcesBySecondResources(FirstResourceFile firstResourceFile, SecondResourceFile secondResourceFile, ResourseRelationshipFile resourseRelationshipFile, ResourceRelationship resourseRelationship, FirstResource firstResource, SecondResource secondResource, std::string nameFirstResource, std::string nameSecondResource) {
    int resourceId;
    std::cout << "INGRESAR ID DE LA " <<  nameSecondResource << ": ";
    std::cin >> resourceId;
    int position = secondResourceFile.searchRecord(resourceId);
    secondResource = secondResourceFile.read(position);
    int numberOfRecordsRelationship = resourseRelationshipFile.numberOfRecords();
    int numberOfRecordsFirstResource = firstResourceFile.numberOfRecords();
    std::cout << "NOMBRE " << nameSecondResource << ": " << secondResource.getName() << std::endl;
    std::cout << "LISTA DE " << nameFirstResource << " CORRESPONDIENTES: " << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < numberOfRecordsRelationship; i ++) {
        resourseRelationship = resourseRelationshipFile.read(i);
        if(resourseRelationship.getSecondResourceId() == secondResource.getId()) {
            for(int j = 0; j < numberOfRecordsFirstResource; j ++) {
                firstResource = firstResourceFile.read(j);
                if(firstResource.getState() && firstResource.getId() == resourseRelationship.getFirstResourceId()) {
                    firstResource.show();
                }
            }
        }
    }
    system("pause");
};
template <typename ResourceFile, typename ResourseRelationshipFile, typename ResourceRelationship, typename Resource>
void withdrawResource(ResourceFile resourceFile, ResourseRelationshipFile resourseRelationshipFile, ResourceRelationship resourseRelationship, Resource resource, int id) {
    if(id > 0) {
        int position = resourceFile.searchRecord(id);
        resource = resourceFile.read(position);
        int numberOfRecordsRelationship = resourseRelationshipFile.numberOfRecords();
        for(int i = 0; i < numberOfRecordsRelationship; i ++) {
            resourseRelationship = resourseRelationshipFile.read(i);
            if(resourseRelationship.getFirstResourceId() == resource.getId()) {
                resourseRelationship.setState(false);
                resourseRelationshipFile.save(resourseRelationship, i);
            }
        }
    }
    system("pause");
};
template <typename ResourseRelationshipFile, typename ResourceRelationship, typename FirstResource>
void withdrawRelationship(ResourseRelationshipFile resourseRelationshipFile, ResourceRelationship resourseRelationship, FirstResource firstResource, int secondResourceId, std::string nameFirstResource, std::string nameSecondResource) {
    int numberOfRecordsRelationship = resourseRelationshipFile.numberOfRecords();
    int positionRelationship = 0;
    bool relationshipFound = false;

    while(!relationshipFound && positionRelationship < numberOfRecordsRelationship) {
        resourseRelationship = resourseRelationshipFile.read(positionRelationship);
        if(resourseRelationship.getFirstResourceId() == firstResource.getId() && resourseRelationship.getSecondResourceId() == secondResourceId) {
            relationshipFound = true;
            resourseRelationship.setState(false);
            resourseRelationshipFile.save(resourseRelationship, positionRelationship);
        }
        positionRelationship++;
    }
    if(relationshipFound) std::cout << "EL " << nameFirstResource << " FUE DADO/A DE BAJA CORRECTAMENTE DE EL/LA " << nameSecondResource << std::endl;
    system("pause");
};