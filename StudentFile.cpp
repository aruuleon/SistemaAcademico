#include"StudentFile.h"
#include <cstdio>

StudentFile::StudentFile(){

}
StudentFile::StudentFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
StudentFile::StudentFile read(int registryNumber){
Student student;
FILE *p = fopen("student.dat", "rb");
if(p == nullptr){
    return student;
}
fseek(p, registryNumber * sizeof(Student), SEEK_SET);
fread(&student, sizeof(Student), 1, p);
fclose(p);
return student;
}
int StudentFile::searchRecord(int registryNumber){
    int position = 0;
        Student student;
        FILE *p = fopen("student.dat", "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&student, sizeof(Student), 1, p)) {
            if(student.getDocument() == registryNumber){//id para buscar {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int StudentFile::numberOfRecords(){
    FILE *p = fopen("student.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Student);
}
bool StudentFile::save(const Student& student){
    bool successfulSave = false; //guardado exitoso
    FILE * p = fopen("student.dat", "ab");
    if(p == nullptr) {
        return successfulSave;
    }
    successfulSave  = fwrite(&student, sizeof(Student), 1, p);
    fclose(p);
    return successfulSave;
    }
bool StudentFile::save(const Student& student, int position) {
    bool successfulSave = false;
    FILE * p = fopen("student.dat", "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Student), SEEK_SET);
    successfulSave = fwrite(&student, sizeof(Student), 1, p);
    fclose(p);
    return successfulSave;
}
bool StudentFile::update(const Student& student, int registryNumber){
    bool couldUpdate = false; //pudo actualizar
    FILE *p = fopen("student.dat", "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(Student), 1, p);
    couldUpdate = fwrite(&student, sizeof(Student), 1, p);
    fclose(p);
    return couldUpdate;
}
bool StudentFile::clearLog(int registryNumber){
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        Student student = read(position);
        student.setAsset(false); //activo(?
        return save(student, position);
}