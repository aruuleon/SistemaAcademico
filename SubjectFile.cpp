#include <cstring>
#include "SubjectFile.h"

SubjectFile::SubjectFile(){

}

SubjectFile::SubjectFile(std::string name){
    strcpy(_fileName, name.c_str());
}

Subject SubjectFile::read(int position){
    Subject subject;
    FILE * reg = fopen("subjects.txt", "rb");
    if(!reg) {
        return subject;
    }

    fseek(reg, position * sizeof(Subject), SEEK_SET);
    fread(&subject, sizeof(Subject), 1, reg);
    fclose(reg);

    return subject;
}

int SubjectFile::searchRecord(int file){
    int position = 0;
    Subject subject;
    FILE * reg = fopen("subjects.txt", "rb");

    if(!reg) {
        return -1;
    }

    while(fread(&subject, sizeof(Subject), 1, reg)) {
        if(subject.getCareerId() == file) {
            fclose(reg);
            return position;
        }
        position++;
    }

    fclose(reg);
    return -1;
}

int SubjectFile::getNumberOfRecords(){
    FILE * reg = fopen("subjects.txt", "rb");

        if(!reg) {
            return -1;
        }

        fseek(reg, 0, SEEK_END);
        int TotalBytes = ftell(reg);
        int numberOfRecords = TotalBytes / sizeof(Subject);
        fclose(reg);

        return numberOfRecords;
}

bool SubjectFile::save(const Subject& obj){
    bool successfulSave = false;
    FILE * reg = fopen("subjects.txt", "ab");

    if(!reg) {
        return successfulSave;
    }

    successfulSave = fwrite(&obj, sizeof(Subject), 1, reg);
    fclose(reg);

    return successfulSave;
}

bool SubjectFile::deleteRecord(int file){
    int position = searchRecord(file);
    Subject subject = read(position);
    subject.setState(false);
    return save(subject);
}
