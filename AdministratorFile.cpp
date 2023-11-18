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
// if(p == nullptr){
//     return administrator;
// }
fseek(p, position * sizeof(Administrator), SEEK_SET);
fread(&administrator, sizeof(Administrator), 1, p);
fclose(p);
return administrator;
}
int AdministratorFile::searchRecord(int registryNumber){
    int position = 0;
        Administrator administrator;
        FILE *p = fopen(_fileName, "rb");
        if(p == nullptr){
        return -1;
        }
        while(fread(&administrator, sizeof(Administrator), 1, p)) {
            if(administrator.getFile() == registryNumber){//id para buscar {
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
    // if(p == nullptr){
    //     std::cout << "NO PUDO ABRIR EL ARCHIVO" << std::endl;
    //     return -1;
    // }
    std::cout << "PUDO ABRIR EL ARCHIVO" << std::endl;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Administrator);
}
bool AdministratorFile::save(const Administrator& administrator){
        bool successfulSave = false; //guardado exitoso
        FILE * p = fopen(_fileName, "ab");
        if(p == nullptr) {
            return successfulSave;
        }
        successfulSave  = fwrite(&administrator, sizeof(Administrator), 1, p);
        fclose(p);
    return successfulSave;
}
bool AdministratorFile::save(const Administrator& administrator, int position) {
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
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
    FILE *p = fopen(_fileName, "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(Administrator), SEEK_SET);
    couldUpdate = fwrite(&administrator, sizeof(Administrator), 1, p);
    fclose(p);
    return couldUpdate;
}
bool AdministratorFile::deleteRecord(int registryNumber){
    bool couldEliminate = false;
        int position = searchRecord(registryNumber);
        Administrator administrator = read(position);
        administrator.setState(false);
        return save(administrator, position);
}
