#include <cstring>
#include <cstdio>
#include"TeacherFile.h"

TeacherFile::TeacherFile(){

}
TeacherFile::TeacherFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
Teacher TeacherFile::read(int registryNumber){
Teacher teacher;
FILE *p = fopen(_fileName, "rb");
if(p == nullptr){
    return teacher;
}
fseek(p, registryNumber * sizeof(Teacher), SEEK_SET);
fread(&teacher, sizeof(Teacher), 1, p);
fclose(p);
return teacher;
}
int TeacherFile::searchRecord(int registryNumber){
    int position = 0;
        Teacher teacher;
        FILE *p = fopen(_fileName, "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&teacher, sizeof(Teacher), 1, p)) {
            if(teacher.getFile() == registryNumber){//id para buscar {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int TeacherFile::numberOfRecords(){
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Teacher);
}
bool TeacherFile::numberOfActiveRecords() {
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return false;
    }
    int numberOfRecords = this->numberOfRecords();
    int position = 0;
    bool activeRecord = false;
    while(!activeRecord && position < numberOfRecords) {
        Teacher teacher = this->read(position);
        if(teacher.getState()) {
            activeRecord = true;
        }
        position++;
    }
    return activeRecord;
}
bool TeacherFile::save(const Teacher& teacher){
        bool successfulSave = false; //guardado exitoso
        FILE * p = fopen(_fileName, "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&teacher, sizeof(Teacher), 1, p);
        fclose(p);
        return successfulSave;
}
bool TeacherFile::save(const Teacher& teacher, int position) {
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Teacher), SEEK_SET);
    successfulSave = fwrite(&teacher, sizeof(Teacher), 1, p);
    fclose(p);
    return successfulSave;
}
bool TeacherFile::deleteRecord(int registryNumber){
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        Teacher teacher = read(position);
        teacher.setState(false); //activo(?
        return save(teacher, position);
}
bool TeacherFile::addOrDelete(int file, int action){
    int position = searchRecord(file);
    if(position != -1) {
        Teacher teacher = read(position);
        if(action == 1){
            teacher.setState(true);
        } else {
            teacher.setState(false);
        }
        return save(teacher, position);
    } else {
        return false;
    }
}