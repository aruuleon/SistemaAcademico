#include <cstring>
#include <cstdio>
#include"UserLoginFile.h"

UserLoginFile::UserLoginFile() {

}
UserLoginFile::UserLoginFile(std::string fileName) {
    strcpy(_fileName, fileName.c_str());
}
UserLogin UserLoginFile::read(int registryNumber) {
    UserLogin userLogin;
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
        return userLogin;
    }
    fseek(p, registryNumber * sizeof(UserLogin), SEEK_SET);
    fread(&userLogin, sizeof(UserLogin), 1, p);
    fclose(p);
    return userLogin;
}
int UserLoginFile::searchRecord(int registryNumber) {
    int position = 0;
    UserLogin userLogin;
    FILE *p = fopen(_fileName, "rb");
    if(p == nullptr){
    return -1;
    }
    while(fread(&userLogin, sizeof(UserLogin), 1, p)) {
        if(userLogin.getFile() == registryNumber) {
            fclose(p);
            return position;
        }
        position++;
    }
    fclose(p);
    return -1;
}
int UserLoginFile::numberOfRecords() {
    FILE * p = fopen(_fileName, "rb");
    if(p == nullptr){
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(UserLogin);
}
bool UserLoginFile::save(const UserLogin& facultyStaff){
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "ab");
    if(p == nullptr) {
        return successfulSave;
    }
    successfulSave  = fwrite(&facultyStaff, sizeof(UserLogin), 1, p);
    fclose(p);
    return successfulSave;
    }
bool UserLoginFile::save(const UserLogin& userLogin, int position) {
    bool successfulSave = false;
    FILE * p = fopen(_fileName, "rb+");
        if(p == nullptr) {
            return successfulSave;
        }
    fseek(p, position * sizeof(UserLogin), SEEK_SET);
    successfulSave = fwrite(&userLogin, sizeof(UserLogin), 1, p);
    fclose(p);
    return successfulSave;
}
bool UserLoginFile::update(const UserLogin& userLogin, int registryNumber){
    bool couldUpdate = false;
    FILE *p = fopen(_fileName, "rb+");
    if(p == nullptr){
        return couldUpdate;
    }
    fseek(p, registryNumber * sizeof(UserLogin), SEEK_SET);
    couldUpdate = fwrite(&userLogin, sizeof(UserLogin), 1, p);
    fclose(p);
    return couldUpdate;
}
bool UserLoginFile::deleteRecord(int registryNumber) {
    bool couldEliminate = false;
        int position = searchRecord(registryNumber);
        UserLogin userLogin = read(position);
        userLogin.setState(false);
        return save(userLogin, position);
}