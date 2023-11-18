#include <iostream>
#include <cstring>
#include "System.h"
#include "Student.h"
#include "StudentFile.h"
#include "UserLoginFile.h"
#include "FacultyStaff.h"
#include "SuperAdministrator.h"
#include "GenericFile.h"

int main() {
    // System system("UTN");
    // system.runProgram();

    GenericFile <SuperAdministrator> genericFile("superAdministrators.dat");

    int cantidadRegistros = genericFile.numberOfRecords();
    std::cout << cantidadRegistros << std::endl;

    // UserLoginFile userLoginFile("usersLogin.dat");
    // StudentFile studentFile("students.dat");
    // SuperAdministratorFile superAdministratorFile("superAdministrators.dat");

    // int cantidadRegistrosUsers = userLoginFile.numberOfRecords();
    // int cantidadRegistrosStudent = studentFile.numberOfRecords();
    // int cantidadRegistrosSuper = superAdministratorFile.numberOfRecords();

    // UserLogin userLogin("super", 456, 1);
    // SuperAdministrator superAdministrator;
    // superAdministrator.setFile(456);
    // superAdministrator.setPassword("super");
    // superAdministrator.setUserType(1);
    
    // userLoginFile.save(userLogin);
    // superAdministratorFile.save(superAdministrator);

    // std::cout << "TODOS LOS USUARIOS REGISTRADOS: " << std::endl;
    // for(int i = 0; i < cantidadRegistrosUsers; i++) {
    //     UserLogin userLogin = userLoginFile.read(i);
    //     std::cout << userLogin.getFile() << std::endl;
    //     std::cout << userLogin.getPassword() << std::endl;
    //     std::cout << userLogin.getUserType() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << std::endl;

    // std::cout << "TODOS LOS ALUMNOS REGISTRADOS: " << std::endl;
    // for(int i = 0; i < cantidadRegistrosStudent; i++) {
    //     Student student = studentFile.read(i);
    //     std::cout << student.getFile() << std::endl;
    //     std::cout << student.getPassword() << std::endl;
    //     std::cout << student.getUserType() << std::endl;
    // }

    // std::cout << std::endl;
    // std::cout << std::endl;

    // std::cout << "TODOS LOS SUPER ADMINISTRADORES REGISTRADOS: " << std::endl;
    // for(int i = 0; i < cantidadRegistrosStudent; i++) {
    //     SuperAdministrator superAdministrator = superAdministratorFile.read(i);
    //     std::cout << superAdministrator.getFile() << std::endl;
    //     std::cout << superAdministrator.getPassword() << std::endl;
    //     std::cout << superAdministrator.getUserType() << std::endl;
    // }
    
    // GenericFile<UserLogin> genericFile ("usersLogin.dat");
    // int cantidadRegistrosStudent = genericFile.numberOfRecords();

    // for(int i = 0; i < cantidadRegistrosStudent; i++) {
    //     UserLogin userLogin = genericFile.read(i);
    //     std::cout << userLogin.getFile() << std::endl;
    //     std::cout << userLogin.getPassword() << std::endl;
    //     std::cout << userLogin.getUserType() << std::endl;
    // }

    return 0;
}