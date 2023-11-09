#include"TeacherFile.h"
#include <cstdio>

TeacherFile::TeacherFile(){

}
TeacherFile::TeacherFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
TeacherFile::TeacherFile read(int registryNumber){
Teacher teacher;
FILE *p = fopen("teacher.dat", "rb");
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
        FILE *p = fopen("teacher.dat", "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&teacher, sizeof(Teacher), 1, p)) {
            if(teacher.getDocument() == registryNumber){//id para buscar {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int TeacherFile::numberOfRecords(){
    FILE *p = fopen("teacher.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Teacher);
}
bool TeacherFile::save(const Teacher& teacher){
        bool successfulSave = false; //guardado exitoso
        FILE * p = fopen("teacher.dat", "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&teacher, sizeof(Teacher), 1, p);
        fclose(p);
        return successfulSave;
}
bool TeacherFile::save(const Teacher& teacher, int position) {
    bool successfulSave = false;
    FILE * p = fopen("teacher.dat", "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Teacher), SEEK_SET);
    successfulSave = fwrite(&teacher, sizeof(Teacher), 1, p);
    fclose(p);
    return successfulSave;
}
bool TeacherFile::update(const Teacher& teacher, int registryNumber){
    bool couldUpdate = false; //pudo actualizar
    FILE *p = fopen("teacher.dat", "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(Teacher), 1, p);
    couldUpdate = fwrite(&teacher, sizeof(Teacher), 1, p);
    fclose(p);
    return couldUpdate;
}
bool TeacherFile::clearLog(int registryNumber){
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        Teacher teacher = read(position);
        teacher.setAsset(false); //activo(?
        return save(teacher, position);
}