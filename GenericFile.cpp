#include <cstring>
#include <cstdio>
#include "GenericFile.h"

template <class T>
GenericFile<T>::GenericFile(){

};
template <class T>
GenericFile<T>::GenericFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
};
template <class T>
T GenericFile<T>::read(int registryNumber){
T facultyStaff;
FILE *p = fopen(_fileName, "rb");
if(p == nullptr){
    return facultyStaff;
}
fseek(p, registryNumber * sizeof(T), SEEK_SET);
fread(&facultyStaff, sizeof(T), 1, p);
fclose(p);
return facultyStaff;
};
template <class T>
int GenericFile<T>::searchRecord(int registryNumber){
    int position = 0;
        T facultyStaff;
        FILE *p = fopen(_fileName, "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&facultyStaff, sizeof(T), 1, p)) {
            if(facultyStaff.getFile() == registryNumber){
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
};
template <class T>
int GenericFile<T>::numberOfRecords(){
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(T);
};
template <class T>
bool GenericFile<T>::save(const T& facultyStaff){
        bool successfulSave = false;
        FILE * p = fopen(_fileName, "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&facultyStaff, sizeof(T), 1, p);
        fclose(p);
    return successfulSave;
};
template <class T>
bool GenericFile<T>::save(const T& facultyStaff, int position) {
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(T), SEEK_SET);
    successfulSave = fwrite(&facultyStaff, sizeof(T), 1, p);
    fclose(p);
    return successfulSave;
};
template <class T>
bool GenericFile<T>::update(const T& facultyStaff, int registryNumber){
    bool couldUpdate = false;
    FILE *p = fopen(_fileName, "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(T), SEEK_SET);
    couldUpdate = fwrite(&facultyStaff, sizeof(T), 1, p);
    fclose(p);
    return couldUpdate;
};
template <class T>
bool GenericFile<T>::deleteRecord(int registryNumber){
    bool couldEliminate = false;
    int position = searchRecord(registryNumber);
    T facultyStaff = read(position);
    facultyStaff.setState(false);
    return save(facultyStaff, position);
};