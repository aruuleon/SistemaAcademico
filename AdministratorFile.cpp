#include"AdministratorFile.h"
#include <cstdio>

AdministratorFile::AdministratorFile(){

}
AdministratorFile::AdministratorFile(std::string fileName){
    strcpy(_fileName, fileName.c_str());
}
AdministratorFile::AdministratorFile read(int registryNumber){
Administrator administrator;
FILE *p = fopen("administrators.dat ", "rb");
if(p == nullptr){
    return administrator;
}
fseek(p, registryNumber * sizeof(Administrator), SEEK_SET);
fread(&administrator, sizeof(Administrator), 1, p);
fclose(p);
return administrator;
}
int AdministratorFile::searchRecord(int registryNumber){
    int position = 0;
        Administrator administrator;
        FILE *p = fopen("administrators.dat", "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&administrator, sizeof(Administrator), 1, p)) {
            if(administrator.getDocument() == registryNumber){//id para buscar {
                fclose(p);
                return position;
            }
            position++;
        }
    fclose(p);
    return -1;
}
int AdministratorFile::numberOfRecords(){
    FILE *p = fopen("administrators.dat", "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Administrator);
}
bool AdministratorFile::save(const Administrator& administrator){
        bool successfulSave = false; //guardado exitoso
        FILE * p = fopen("administrators.dat", "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&administrator, sizeof(Administrator), 1, p);
        fclose(p);
    return successfulSave;
}
bool AdministratorFile::save(const Administrator& administrator, int position) {
    bool successfulSave = false;
    FILE * p = fopen("administrators.dat", "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(Administrator), SEEK_SET);
    successfulSave = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return successfulSave;
}
bool AdministratorFile::update(const Administrator& administrator, int registryNumber){
    bool couldUpdate = false; //pudo actualizar
    FILE *p = fopen("administrators.dat", "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(Administrator), 1, p);
    couldUpdate = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return couldUpdate;
}
bool AdministratorFile::clearLog(int registryNumber){
    bool couldEliminate = false; //pudo eliminar
        int position = searchRecord(registryNumber);
        Administrator administrator = read(position);
        administrator.setAsset(false); //activo(?
        return save(administrator, position);
}