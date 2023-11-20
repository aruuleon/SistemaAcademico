#include "Functions.h"
#include "AdministratorFile.h"
#include "StudentFile.h"
#include "TeacherFile.h"
#include "UserLoginFile.h"
#include "NoticeFile.h"

int verifyFileAdministrators(){
    AdministratorFile administratorFile("administrators.dat");
    int generatedFile;
    int numberOfRecords = administratorFile.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = administratorFile.read(numberOfRecords - 1).getFile() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
};

int verifyFileTeachers(){
    TeacherFile teacherFile("teachers.dat");
    int generatedFile;
    int numberOfRecords = teacherFile.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = teacherFile.read(numberOfRecords - 1).getFile() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
};

int verifyFileStudents(){
    StudentFile studentFile("students.dat");
    int generatedFile;
    int numberOfRecords = studentFile.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = studentFile.read(numberOfRecords - 1).getFile() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
};
int verifyCodeNotice(){
    NoticeFile noticeFile("notices.dat");
    int generatedFile;
    int numberOfRecords = noticeFile.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = noticeFile.read(numberOfRecords - 1).getCode() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
};
void withdrawAdministrator(){
    int file;
    AdministratorFile administratorFile ("administrators.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "ELIMINANDO ADMINISTRADOR.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ADMINISTRADOR A ELIMINAR: ";
    std::cin >> file;

    if(administratorFile.addOrDelete(file, 2) && userLoginFile.addOrDelete(file, 2)) {
        std::cout << "EL ADMINISTRADOR CON LEGAJO '" << file << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL ELIMINAR ADMINISTRADOR" << std::endl;
    }
};
void withdrawTeacher(){
    int file;
    TeacherFile teacherFile ("teachers.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "ELIMINANDO PROFESOR.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE PROFESOR A ELIMINAR: ";
    std::cin >> file;

    if(teacherFile.addOrDelete(file, 2) && userLoginFile.addOrDelete(file, 2)) {
        std::cout << "EL PROFESOR CON LEGAJO '" << file << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL ELIMINAR PROFESOR" << std::endl;
    }
};
void withdrawStudent(){
    int file;
    StudentFile studentFile ("students.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "ELIMINANDO ALUMNO.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ALUMNO A ELIMINAR: ";
    std::cin >> file;

    if(studentFile.addOrDelete(file, 2) && userLoginFile.addOrDelete(file, 2)) {
        std::cout << "EL ALUMNO CON LEGAJO '" << file << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL ELIMINAR ALUMNO" << std::endl;
    }
};
void withDrawNotice(){
    int code;
    NoticeFile noticeFile ("notices.dat");

    std::cout << "ELIMINANDO AVISO.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR CODIGO DE AVISO A ELIMINAR: ";
    std::cin >> code;

    if(noticeFile.addOrDelete(code, 2)) {
        std::cout << "EL AVISO CON CODIGO '" << code << "' SE ELIMINO CORRECTAMENTE" << std::endl;
    } else {
        std::cout << "ERROR AL ELIMINAR AVISO" << std::endl;
    }
};
void reEnrollAdministrator(){
    int file;
    AdministratorFile administratorFile ("administrators.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "VOLVIENDO A DAR DE ALTA ADMINISTRADOR..." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ADMINISTRADOR A DAR DE ALTA NUEVAMENTE: ";
    std::cin >> file;

    if(administratorFile.addOrDelete(file, 1) && userLoginFile.addOrDelete(file, 1)) {
        std::cout << "EL ADMINISTRADOR CON LEGAJO '" << file << "' FUE DADO DE ALTA CORRECTAM,ENTE" << std::endl;
    } else {
        std::cout << "ERROR AL DAR DE ALTA AL ADMINISTRADOR" << std::endl;
    }
};
void reEnrollTeacher(){
    int file;
    TeacherFile teacherFile ("teachers.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "VOLVIENDO A DAR DE ALTA PROFESOR..." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE PROFESOR A DAR DE ALTA NUEVAMENTE: ";
    std::cin >> file;

    if(teacherFile.addOrDelete(file, 1) && userLoginFile.addOrDelete(file, 1)) {
        std::cout << "EL PROFESOR CON LEGAJO '" << file << "' FUE DADO DE ALTA CORRECTAM,ENTE" << std::endl;
    } else {
        std::cout << "ERROR AL DAR DE ALTA AL PROFESOR" << std::endl;
    }
};
void reEnrollStudent(){
    int file;
    StudentFile studentFile ("students.dat");
    UserLoginFile userLoginFile ("usersLogin.dat");

    std::cout << "VOLVIENDO A DAR DE ALTA ALUMNO..." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ALUMNO A DAR DE ALTA NUEVAMENTE: ";
    std::cin >> file;

    if(studentFile.addOrDelete(file, 1) && userLoginFile.addOrDelete(file, 1)) {
        std::cout << "EL ALUMNO CON LEGAJO '" << file << "' FUE DADO DE ALTA CORRECTAM,ENTE" << std::endl;
    } else {
        std::cout << "ERROR AL DAR DE ALTA AL ALUMNO" << std::endl;
    }
};
void listAdministrators(){
    std::cout << "MOSTRANDO LISTA ADMINISTRADORES.." << std::endl;
    AdministratorFile administratorFile ("administrators.dat");
    int numberOfRecords = administratorFile.numberOfRecords();
    if(administratorFile.numberOfActiveRecords()) {
        for(int i = 0; i < numberOfRecords; i++) {
            Administrator administrator = administratorFile.read(i);
            if(administrator.getState()) {
                administrator.show();
            }
        }
    } else {
        std::cout << "NO SE ENCUENTRAN ADMINISTRADOS REGISTRADOS EN ESTE MOMENTO" << std::endl;
    }
};
void listTeachers(){
    std::cout << "MOSTRANDO LISTA PROFESORES.." << std::endl;
    TeacherFile teacherFile ("teachers.dat");
    int numberOfRecords = teacherFile.numberOfRecords();
    if(teacherFile.numberOfActiveRecords()) {
        for(int i = 0; i < numberOfRecords; i++) {
            Teacher teacher = teacherFile.read(i);
            if(teacher.getState()) {
                teacher.show();
            }
        }
    } else {
        std::cout << "NO SE ENCUENTRAN PROFESORES REGISTRADOS EN ESTE MOMENTO" << std::endl;
    }
};
void listStudents(){
    std::cout << "MOSTRANDO LISTA ALUMNOS.." << std::endl;
    StudentFile studentFile ("students.dat");
    int numberOfRecords = studentFile.numberOfRecords();
    if(studentFile.numberOfActiveRecords()) {
        for(int i = 0; i < numberOfRecords; i++) {
            Student student = studentFile.read(i);
            if(student.getState()) {
                student.show();
            }
        }
    } else {
        std::cout << "NO SE ENCUENTRAN ALUMNOS REGISTRADOS EN ESTE MOMENTO" << std::endl;
    }
};
void searchAdministrator(){
    int file;
    AdministratorFile administratorFile ("administrators.dat");

    std::cout << "BUSCANDO ADMINISTRADOR.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ADMINISTRADOR A BUSCAR: ";
    std::cin >> file;

    int position = administratorFile.searchRecord(file);
    Administrator administrator = administratorFile.read(position);
    if(position != -1 && administrator.getState()) {
        administrator.show();
    } else {
        std::cout << "EL ADMINISTRADOR CON LEGAJO '" << file << "' NO SE ENCUENTRA REGISTRADO" << std::endl;
    }
};
void searchTeacher(){
    int file;
    TeacherFile teacherFile ("teachers.dat");

    std::cout << "BUSCANDO PROFESOR.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE PROFESOR A BUSCAR: ";
    std::cin >> file;

    int position = teacherFile.searchRecord(file);
    Teacher teacher = teacherFile.read(position);
    if(position != -1 && teacher.getState()) {
        teacher.show();
    } else {
        std::cout << "EL PROFESOR CON LEGAJO '" << file << "' NO SE ENCUENTRA REGISTRADO" << std::endl;
    }
};
void searchStudent(){
    int file;
    StudentFile studentFile ("students.dat");

    std::cout << "BUSCANDO ALUMNO.." << std::endl;
    std::cout << std::endl;
    std::cout << "INGRESAR LEGAJO DE ALUMNO A BUSCAR: ";
    std::cin >> file;

    int position = studentFile.searchRecord(file);
    Student student = studentFile.read(position);
    if(position != -1 && student.getState()) {
        student.show();
    } else {
        std::cout << "EL ALUMNO CON LEGAJO '" << file << "' NO SE ENCUENTRA REGISTRADO" << std::endl;
    }
};