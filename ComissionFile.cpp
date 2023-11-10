#include <cstring>
#include "ComissionFile.h"

ComissionFile::ComissionFile(){

}

ComissionFile::ComissionFile(std::string name){
    strcpy(_fileName, name.c_str());
}

Comission ComissionFile::read(int position){
    Comission comission;
    FILE * reg = fopen("comissions.txt", "rb");
    if(!reg) {
        return comission;
    }

    fseek(reg, position * sizeof(Comission), SEEK_SET);
    fread(&comission, sizeof(Comission), 1, reg);
    fclose(reg);

    return comission;
}

int ComissionFile::searchRecord(std::string comissionCode){
    int position = 0;
    Comission comission;
    FILE * reg = fopen("comissions.txt", "rb");

    if(!reg) {
        return -1;
    }

    while(fread(&comission, sizeof(Comission), 1, reg)) {
        if(comission.getComissionCode() == comissionCode) {
            fclose(reg);
            return position;
        }
        position++;
    }

    fclose(reg);
    return -1;
}

int ComissionFile::getNumberOfRecords(){
    FILE * reg = fopen("comissions.txt", "rb");

        if(!reg) {
            return -1;
        }

        fseek(reg, 0, SEEK_END);
        int TotalBytes = ftell(reg);
        int numberOfRecords = TotalBytes / sizeof(Comission);
        fclose(reg);

        return numberOfRecords;
}

bool ComissionFile::save(const Comission& obj){
    bool successfulSave = false;
    FILE * reg = fopen("comissions.txt", "ab");

    if(!reg) {
        return successfulSave;
    }

    successfulSave = fwrite(&obj, sizeof(Comission), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool ComissionFile::update(const Comission& obj, int position){
    bool successfulSave = false;
    FILE * reg = fopen("comissions.txt", "rb+");

    if(!reg) {
        return successfulSave;
    }

    fseek(reg, position * sizeof(Comission), SEEK_SET);
    successfulSave = fwrite(&obj, sizeof(Comission), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool ComissionFile::deleteRecord(std::string comissionCode){
    int position = searchRecord(comissionCode);
    Comission comission = read(position);
    comission.setState(false);
    return save(comission);
}