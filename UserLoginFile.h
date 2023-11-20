#pragma once
#include "UserLogin.h"
#include <string>

class UserLoginFile {
private:
    char _fileName[30];
public:
    UserLoginFile();
    UserLoginFile(std::string);

    UserLogin read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(const UserLogin&);
    bool save(const UserLogin&, int);
    bool addOrDelete(int, int);
};