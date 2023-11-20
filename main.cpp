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
    System system("UTN");
    system.runProgram();

    // std::cout << sizeof(Administrator);
    // std::cout << sizeof(FacultyStaff);
    // GenericFile <SuperAdministrator> genericFile("superAdministrators.dat");
    

    //int cantidadRegistros = genericFile.numberOfRecords();
    //std::cout << cantidadRegistros << std::endl;

    // StudentFile studentFile("students.dat");

    // AdministratorFile administratorFile("administrators.dat");
    // int cantidadRegistrosUsers = administratorFile.numberOfRecords();
    // Administrator a;
    // a.setFile(4);
    // a.setPassword("coco");
    // a.setUserType(2);

    // int cantidadRegistrosStudent = studentFile.numberOfRecords();
    // int cantidadRegistrosSuper = superAdministratorFile.numberOfRecords();
    
    // SuperAdministratorFile superAdministratorFile("superAdministrators.dat");
    // UserLoginFile userLoginFile("usersLogin.dat");
    // int cantidadRegistrosUsers = userLoginFile.numberOfRecords();
    
    // UserLogin userLogin("super", 1, 1);
    // SuperAdministrator superAdministrator;
    // superAdministrator.setPassword("super");
    // superAdministrator.setUserType(1);
    // superAdministrator.setFile(1);
    
    // userLoginFile.save(userLogin);
    // superAdministratorFile.save(superAdministrator);

    // std::cout << "TODOS LOS USUARIOS REGISTRADOS: " << std::endl;
    // for(int i = 0; i < cantidadRegistrosUsers; i++) {
    //   UserLogin userLogin = userLoginFile.read(i);
    //    std::cout << userLogin.getFile() << std::endl;
    //    std::cout << userLogin.getPassword() << std::endl;
    //    std::cout << userLogin.getUserType() << std::endl;
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
    // AdministratorFile administratorFile("administrators.dat");
    // int registros = administratorFile.numberOfRecords();
    // std::cout << registros << std::endl;
    // for(int i = 0; i < registros; i++){
    //     Administrator a = administratorFile.read(i); 
    //     std::cout << a.getFile() << std::endl;
    //     std::cout << a.getPassword() << std::endl;
    //     std::cout << a.getUserType() << std::endl;
    // }

    // Administrator administrator = Administrator("nombre", "apellido", "123456789", "789456123", "email@gmail.com", "password", 1, 1);
    // administrator.show();

    return 0;
}