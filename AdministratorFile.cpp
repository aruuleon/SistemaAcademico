#include <cstring>
#include <cstdio>
#include"AdministratorFile.h"

AdministratorFile::AdministratorFile(){

}
AdministratorFile::AdministratorFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
Administrator AdministratorFile::read(int position){
    Administrator administrator;
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        administrator.setState(false);
        return administrator;
    }
    fseek(p, position * sizeof(Administrator), SEEK_SET);
    fread(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return administrator;
}
int AdministratorFile::searchRecord(int file){
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    Administrator administrator;
    int position = 0;
    while(fread(&administrator, sizeof(Administrator), 1, p)) {
        if(administrator.getFile() == file){
            fclose(p);
            return position;
        }
        position++;
    }
    fclose(p);
    return -1;
}
int AdministratorFile::numberOfRecords(){
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Administrator);
}
bool AdministratorFile::numberOfActiveRecords() {
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return false;
    }
    int numberOfRecords = this->numberOfRecords();
    int position = 0;
    bool activeRecord = false;
    while(!activeRecord && position < numberOfRecords) {
        Administrator administrator = this->read(position);
        if(administrator.getState()) {
            activeRecord = true;
        }
        position++;
    }
    return activeRecord;
}
bool AdministratorFile::save(const Administrator& administrator){
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "ab");
    if(p == nullptr) {
        return successfulSave;
    }
    successfulSave  = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return successfulSave;
}
bool AdministratorFile::save(const Administrator& administrator, int position) {
    FILE * p = fopen(_fileName, "rb+");
    if(p == nullptr) {
        return false;
    }
    fseek(p, position * sizeof(Administrator), SEEK_SET);
    bool successfulSave = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return successfulSave;
}
bool AdministratorFile::update(const Administrator& administrator, int registryNumber){
    bool couldUpdate = false;
    FILE *p = fopen(_fileName, "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(Administrator), SEEK_SET);
    couldUpdate = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return couldUpdate;
}
bool AdministratorFile::deleteRecord(int file){
    int position = searchRecord(file);
    if(position != -1) {
        Administrator administrator = read(position);
        administrator.setState(false);
        return save(administrator, position);
    } else {
        return false;
    }
}
