#include "careerFile.h"

careerFile::careerFile(){

}

careerFile::careerFile(std::string name){
    strcpy(_fileName, name.c_str());
}

Career read(int position){
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

int search(int file){
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

int getNumberOfRecords(){
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

bool save(Career obj){
    bool successfulSave = false;
    FILE * reg = fopen("careers.txt", "ab");

    if(!reg) {
        return successfulSave;
    }

    successfulSave = fwrite(&obj, sizeof(Career), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool update(Career obj, int position){
    bool successfulSave = false;
    FILE * reg = fopen("careers.txt", "rb+");

    if(!reg) {
        return successfulSave;
    }

    fseek(reg, position * sizeof(Career), SEEK_SET);
    successfulSave = fwrite(&obj, sizeof(Career), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool deleteRecord(int file){
    int position = search(file);
    Career career = read(position);
    career.setState(false);
    return save(career);
}
