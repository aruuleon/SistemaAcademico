#include <iostream>
#include <cstring>
#include "System.h"
#include "UserLoginFile.h"
#include "UserLogin.h"
#include "GenericFile.h"

System::System() {

};
System::System(std::string name) {
    setName(name);
};
std::string System::getName() const {
    return _name;
};
void System::setName(std::string name) {
    strcpy(_name, name.c_str());
};
void System::runProgram() {
    login();
};
void System::login() {
    int file;
    int userType;
    std::string password;

    do {
        do {
            std::cout << "INICIAR SESION" << std::endl;
            std::cout << std::endl;
            std::cout << "LEGAJO: ";
            std::cin >> file;
            std::cout << "CLAVE: ";
            std::cin >> password;
            userType = verifyCredentials(file, password);
            if(userType == 0) {
                std::cout << "CREDENCIALES INCORRECTAS" << std::endl;
            }
        } while(userType == 0);
        allowAccess(file, userType);
    } while(true);
};
int System::verifyCredentials(int file, std::string password) {
    UserLoginFile userLoginFile ("usersLogin.dat");
    int numberOfRecords = userLoginFile.numberOfRecords();
    int userType = 0;
    int userPosition = 0;
    bool userFound = false;

    while(!userFound && userPosition < numberOfRecords) {
        UserLogin userLogin = userLoginFile.read(userPosition);
        if(userLogin.getFile() == file && userLogin.getPassword() == password) {
            userFound = true;
            userType = userLogin.getUserType();
        }
        userPosition++;
    }
    return userType;
};
void System::allowAccess(int file, int userType) {
    switch(userType) {
        case 1: 
            {int position = _superAdministratorFile.searchRecord(file);
            SuperAdministrator superAdministrator = _superAdministratorFile.read(position);
            superAdministrator.showMenu();}
            break;
        case 2: 
            {int position = _administratorFile.searchRecord(file);
            Administrator administrator = _administratorFile.read(position);
            administrator.showMenu(administrator);}
            break;
        case 3: 
            {int position = _teacherFile.searchRecord(file);
            Teacher teacher = _teacherFile.read(position);
            teacher.showMenu(teacher);}
            break;
        case 4: 
            {int position = _studentFile.searchRecord(file);
            Student student = _studentFile.read(position);
            student.showMenu(student);}
            break;
    }
};