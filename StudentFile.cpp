#include <cstring>
#include <cstdio>
#include"StudentFile.h"

StudentFile::StudentFile() {

}
StudentFile::StudentFile(std::string fileName) {
    strcpy(_fileName, fileName.c_str());
}
Student StudentFile::read(int registryNumber) {
Student student;
FILE *p = fopen(_fileName, "rb");
if(p == nullptr){
    return student;
}
fseek(p, registryNumber * sizeof(Student), SEEK_SET);
fread(&student, sizeof(Student), 1, p);
fclose(p);
return student;
}
int StudentFile::searchRecord(int registryNumber) {
    int position = 0;
        Student student;
        FILE *p = fopen(_fileName, "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&student, sizeof(Student), 1, p)) {
            if(student.getFile() == registryNumber) {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int StudentFile::numberOfRecords() {
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Student);
}
bool StudentFile::numberOfActiveRecords() {
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return false;
    }
    int numberOfRecords = this->numberOfRecords();
    int position = 0;
    bool activeRecord = false;
    while(!activeRecord && position < numberOfRecords) {
        Student student = this->read(position);
        if(student.getState()) {
            activeRecord = true;
        }
        position++;
    }
    return activeRecord;
}
bool StudentFile::save(const Student& student){
    bool successfulSave = false; //guardado exitoso
    FILE * p = fopen(_fileName, "ab");
    if(p == nullptr) {
        return successfulSave;
    }
    successfulSave  = fwrite(&student, sizeof(Student), 1, p);
    fclose(p);
    return successfulSave;
    }
bool StudentFile::save(const Student& student, int position) {
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Student), SEEK_SET);
    successfulSave = fwrite(&student, sizeof(Student), 1, p);
    fclose(p);
    return successfulSave;
}
bool StudentFile::deleteRecord(int registryNumber) {
        int position = searchRecord(registryNumber);
        Student student = read(position);
        student.setState(false);
        return save(student, position);
}
bool StudentFile::addOrDelete(int file, int action){
    int position = searchRecord(file);
    if(position != -1) {
        Student student = read(position);
        if(action == 1){
            student.setState(true);
        } else {
            student.setState(false);
        }
        return save(student, position);
    } else {
        return false;
    }
}