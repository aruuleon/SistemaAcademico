#include <iostream>
#include <cstring>
#include "System.h"
#include "GenericFile.h"
#include "Administrator.h"
#include "UserLogin.h"

int main() {
    System system("UNIVERSIDAD TECNOLOGICA NACIONAL", "Argentina", "Buenos Aires");
    system.runProgram();

    // GenericFile <Exam> _examFile = GenericFile <Exam> ("exams.dat"); //?
    // Exam exam(1, 5 , Fecha(2,5,2023));
    // GenericFile <ExamXStudentXSubject> _examXStudentXSubjectFile = GenericFile <ExamXStudentXSubject> ("examsXStudentsXSubjects.dat"); //?
    // ExamXStudentXSubject examXStudentXSubject(1, 1 , 1, true);
    // _examFile.save(exam);
    // _examXStudentXSubjectFile.save(examXStudentXSubject);

    // GenericFile <StudentXSubject> _studentXSubjectFile = GenericFile <StudentXSubject> ("studentsXSubjects.dat");
    // _studentXSubjectFile.save(StudentXSubject(1, 1));

    // GenericFile <SuperAdministrator> superAdministratorFile ("superAdministrators.dat");
    // GenericFile <Administrator> administratorFile ("administrators.dat");
    // GenericFile <UserLogin> userLoginFile ("usersLogin.dat");

    // Administrator administrator = Administrator("NombrePrueba", "ApellidoPrueba", "123456789", "789456123", "prueba@gmail.com", "prueba", 101, 2);
    // UserLogin userLogin = UserLogin("prueba", 101, 2);
    // administratorFile.save(administrator);
    // userLoginFile.save(userLogin);

    // SuperAdministrator superAdministrator = SuperAdministrator("Daniel", "Kloster", "123456789", "789456123", "dkloster@gmail.com", "dkloster", 321, 1);
    // Administrator administrator = Administrator("Brian", "Lara", "123456789", "789456123", "blara@gmail.com", "blara", 654, 2);
    // UserLogin userLoginUno = UserLogin("dkloster", 321, 1);
    // UserLogin userLoginDos = UserLogin("blara", 654, 2);

    // superAdministratorFile.save(superAdministrator);
    // administratorFile.save(administrator);
    // userLoginFile.save(userLoginUno);
    // userLoginFile.save(userLoginDos);

    return 0;
}