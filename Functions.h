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

std::string getStudyType(int);
std::string getCourseDuration(int);

template <class T>
int listRegisterByOption(GenericFile<T> file) {
    std::cout << "MOSTRANDO LISTA REGISTROS.." << std::endl;
    int numberOfRecords = file.numberOfRecords();
    if(file.numberOfActiveRecords()) {
        for(int i = 0; i < numberOfRecords; i++) {
            if(file.read(i).getState()) {
                file.read(i).show();
            }
        }
    } else {
        std::cout << "NO SE ENCUENTRAN REGISTROS EN ESTE MOMENTO" << std::endl;
    }
};
template <class T>
void searchRegisterByOption(GenericFile<T> file) {
    int id;

    std::cout << "BUSCANDO REGISTRO.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO A BUSCAR: ";
    std::cin >> id;
    int position = file.searchRecord(id);
    if(position != -1 && file.read(position).getState()) {
        file.read(position).show();
    } else {
        std::cout << "EL REGISTRO CON ID '" << id << "' NO FUE ENCONTRADO" << std::endl;
    }
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
void withdrawRegisterByOption(GenericFile<T> file, std::string optionReceived) {
    char optionCompare[20];
    int id;
    bool response;

    strcpy(optionCompare, optionReceived.c_str());

    std::cout << "ELIMINANDO REGISTRO.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR ID DE REGISTRO A ELIMINAR: ";
    std::cin >> id;
    if(strcmp(optionCompare, "user") == 0) {
        GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
        response = file.addOrDelete(id, 2) && userLoginFile.addOrDelete(id, 2);
    } else {
        response = file.addOrDelete(id, 2);
    }
    if(response) {
        std::cout << "EL REGISTRO CON ID '" << id << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL ELIMINAR REGISTRO" << std::endl;
    }
};
template <class T>
void reEnrollRegisterByOption(GenericFile<T> file, std::string optionReceived) {
    char optionCompare[20];
    int id;
    bool response;

    strcpy(optionCompare, optionReceived.c_str());

    std::cout << "VOLVIENDO A DAR DE ALTA REGISTRO..." << std::endl;
    std::cout << std::endl;
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
};