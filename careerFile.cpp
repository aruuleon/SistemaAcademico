#include <cstring>
#include "CareerFile.h"

CareerFile::CareerFile(){

}

CareerFile::CareerFile(std::string name){
    strcpy(_fileName, name.c_str());
}

Career CareerFile::read(int position){
    Career career;
    FILE * reg = fopen("careers.txt", "rb");
    if(!reg) {
        return career;
    }

    fseek(reg, position * sizeof(Career), SEEK_SET);
    fread(&career, sizeof(Career), 1, reg);
    fclose(reg);

    return career;
}

int CareerFile::searchRecord(int file){
    int position = 0;
    Career career;
    FILE * reg = fopen("careers.txt", "rb");

    if(!reg) {
        return -1;
    }

    while(fread(&career, sizeof(Career), 1, reg)) {
        if(career.getCareerId() == file) {
            fclose(reg);
            return position;
        }
        position++;
    }

    fclose(reg);
    return -1;
}

int CareerFile::getNumberOfRecords(){
    FILE * reg = fopen("careers.txt", "rb");

        if(!reg) {
            return -1;
        }

        fseek(reg, 0, SEEK_END);
        int TotalBytes = ftell(reg);
        int numberOfRecords = TotalBytes / sizeof(Career);
        fclose(reg);

        return numberOfRecords;
}

bool CareerFile::save(const Career& obj){
    bool successfulSave = false;
    FILE * reg = fopen("careers.txt", "ab");

    if(!reg) {
        return successfulSave;
    }

    successfulSave = fwrite(&obj, sizeof(Career), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool CareerFile::deleteRecord(int file){
    int position = searchRecord(file);
    Career career = read(position);
    career.setState(false);
    return save(career);
}
