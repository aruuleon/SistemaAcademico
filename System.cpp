#include <iostream>
#include <cstring>
#include "System.h"
#include "UserLogin.h"
#include "GenericFile.h"

System::System() {

};
System::System(std::string name) {
    setName(name);
    GenericFile <SuperAdministrator> _superAdministratorFile = GenericFile <SuperAdministrator> ("superAdministrators.dat");
    GenericFile <Administrator> _administratorFile = GenericFile <Administrator> ("administrators.dat");
    GenericFile <Teacher> _teacherFile = GenericFile <Teacher> ("teachers.dat");
    GenericFile <Student> _studentFile = GenericFile <Student> ("students.dat");
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
    GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
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
            {
                SuperAdministrator superAdministrator = _superAdministratorFile.read(_superAdministratorFile.searchRecord(file));
                superAdministrator.showMenu();
            }
        break;
        case 2: 
            {
                Administrator administrator = _administratorFile.read(_administratorFile.searchRecord(file));
                administrator.showMenu();
            }
        break;
        case 3: 
            {
                Teacher teacher = _teacherFile.read(_teacherFile.searchRecord(file));
                teacher.showMenu(teacher);
            }
        break;
        case 4: 
            {
                Student student = _studentFile.read(_studentFile.searchRecord(file));
                student.showMenu(student);
            }
        break;
    }
};