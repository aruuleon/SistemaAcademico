#include <cstring>
#include <cstdio>
#include"SuperAdministratorFile.h"

SuperAdministratorFile::SuperAdministratorFile(){

}
SuperAdministratorFile::SuperAdministratorFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
SuperAdministrator SuperAdministratorFile::read(int position){
SuperAdministrator superAdministrator;
FILE *p = fopen("superAdministrators.dat", "rb");
if(p == nullptr){
    return superAdministrator;
}
fseek(p, position * sizeof(SuperAdministrator), SEEK_SET);
fread(&superAdministrator, sizeof(SuperAdministrator), 1, p);
fclose(p);
return superAdministrator;
}
int SuperAdministratorFile::searchRecord(int registryNumber){
    int position = 0;
        SuperAdministrator superAdministrator;
        FILE *p = fopen("superAdministrators.dat", "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&superAdministrator, sizeof(SuperAdministrator), 1, p)) {
            if(superAdministrator.getFile() == registryNumber){//id para buscar {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int SuperAdministratorFile::numberOfRecords(){
    FILE *p = fopen("superAdministrators.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(SuperAdministrator);
}
bool SuperAdministratorFile::save(const SuperAdministrator& superAdministrator){
        bool successfulSave = false; //guardado exitoso
        FILE * p = fopen("superAdministrators.dat", "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&superAdministrator, sizeof(SuperAdministrator), 1, p);
        fclose(p);
    return successfulSave;
}
bool SuperAdministratorFile::save(const SuperAdministrator& superAdministrator, int position) {
    bool successfulSave = false;
    FILE * p = fopen("superAdministrators.dat", "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(superAdministrator), SEEK_SET);
    successfulSave = fwrite(&superAdministrator, sizeof(SuperAdministrator), 1, p);
    fclose(p);
    return successfulSave;
}
bool SuperAdministratorFile::update(const SuperAdministrator& superAdministrator, int registryNumber){
    bool couldUpdate = false; //pudo actualizar
    FILE *p = fopen("superAdministrators.dat", "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(SuperAdministrator), SEEK_SET);
    couldUpdate = fwrite(&superAdministrator, sizeof(SuperAdministrator), 1, p);
    fclose(p);
    return couldUpdate;
}
bool SuperAdministratorFile::deleteRecord(int registryNumber){ //borrar registro
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        SuperAdministrator superAdministrator = read(position);
        superAdministrator.setState(false); //set activo(?
        return save(superAdministrator, position);
}