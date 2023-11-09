#include"SuperAdministratorFile.h"
#include <cstdio>

SuperAdministratorFile::SuperAdministratorFile(){

}
SuperAdministratorFile::SuperAdministratorFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
SuperAdministratorFile::SuperAdministratorFile read(int registryNumber){
SuperAdministrator superAdministrator;
FILE *p = fopen("superAdministrators.dat", "rb");//_fileName.c_str()(?)
if(p == nullptr){
    return superAdministrator;
}
fseek(p, registryNumber * sizeof(SuperAdministrator), SEEK_SET);
fread(&superAdministrator, sizeof(SuperAdministrator), 1, p);
fclose(p);
return superAdministrator;
}
int SuperAdministratorFile::searchRecord(int registryNumber){ // o position(?)
    int position = 0;
        SuperAdministrator superAdministrator;
        FILE *p = fopen("superAdministrators.dat", "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&superAdministrator, sizeof(SuperAdministrator), 1, p)) {
            if(superAdministrator.getDocument() == registryNumber){//id para buscar {
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
    fseek(p, registryNumber * sizeof(SuperAdministrator), 1, p);
    couldUpdate = fwrite(&superAdministrator, sizeof(SuperAdministrator), 1, p);
    fclose(p);
    return couldUpdate;
}
bool SuperAdministratorFile::clearLog(int registryNumber){ //borrar registro
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        SuperAdministrator superAdministrator = read(position);
        superAdministrator.setAsset(false); //set activo(?
        return save(superAdministrator, position);
}