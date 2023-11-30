#include "Functions.h"
#include "GenericFile.h"
#include "Administrator.h"
#include "Teacher.h"
#include "Student.h"
#include "UserLogin.h"
#include "Career.h"
#include "Subject.h"
#include "Notice.h"

void registerAdministrator() {
    std::string name;
    std::string surname;
    std::string document;
    std::string email;
    std::string password;
    std::string phone;
    int id;
    int userType;
    std::cout << "NOMBRE: " ;
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "APELLIDO: " ;
    getline(std::cin, surname);
    std::cout << "DNI: " ;
    std::cin >>  document; 
    std::cout << "CORREO: " ; 
    std::cin >>  email;
    std::cout << "TELEFONO: " ; 
    std::cin >>  phone;
    std::cout << "CLAVE: " ; 
    std::cin >> password;
    GenericFile <Administrator> administratorFile ("administrators.dat");
    id = verifyIdRegisterByOption(administratorFile);
    GenericFile <UserLogin> userLoginFile ("usersLogin.dat");
    bool administratorResponse = administratorFile.save(Administrator(name, surname, document, email, password, phone, id, 2));
    bool userResponse = userLoginFile.save(UserLogin(password, id, 2));
    system("pause");
};
void registerCareer() {
    std::string name;
    int studyType;
    int id;
    int duration;

    std::cout << "* TIPO DE ESTUDIO: " << std::endl;
    std::cout << "1 - TECNICATURA" << std::endl;
    std::cout << "2 - CARRERA DE GRADO" << std::endl;
    std::cout << "3 - POSGRADO" << std::endl;
    std::cout << "SELECCIONAR UNA OPCION: ";
    std::cin >> studyType;
    std::cout << std::endl;
    std::cout << "* NOMBRE: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << "* DURACION: ";
    std::cin >> duration;
    std::cout << std::endl;
    GenericFile <Career> careerFile ("careers.dat");
    id = verifyIdRegisterByOption(careerFile);
    bool careerResponse = careerFile.save(Career(name, studyType, id, duration));
    std::cout << careerResponse << std::endl;
    system("pause");
};
void registerSubject() {
    std::string name;
    int duration;
    int id;
    int yearCareer;
    int selectedOption;

    std::cout << "* NOMBRE: ";
    std::cin.ignore();
    getline(std::cin, name);
    std::cout << std::endl;
    std::cout << "* DURACION: " << std::endl;
    std::cout << "1 - CUATRIMESTRAL" << std::endl;
    std::cout << "2 - ANUAL" << std::endl;
    std::cout << "* SELECCIONAR UNA OPCION: ";
    std::cin >> duration;
    std::cout << std::endl;
    std::cout << "* EN QUE ANIO DE LA CARRERA SE DICTA: ";
    std::cin >> yearCareer;
    GenericFile <Subject> subjectFile ("subjects.dat");
    id = verifyIdRegisterByOption(subjectFile);
    bool responseSubject = subjectFile.save(Subject(name, duration, id, yearCareer));
    system("pause");
};
void editAdministrator() {
    system("pause");
};
void editCareer() {
    system("pause");
};
void editSubject() {
    system("pause");
};