#pragma once
#include "Administrator.h"
#include <string>

class AdministratorFile{
private:
    char _fileName[30];
public:
    AdministratorFile();
    AdministratorFile(std::string);

    AdministratorFile read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(Administrator);
    bool save(Administrator, int);
    bool update(Administrator, int);
    bool clearLog(std::string, int);
};