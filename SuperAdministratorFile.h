#pragma once
#include "SuperAdministrator.h"
#include <string>

class SuperAdministratorFile{
private:
    char _fileName[30];
public:
    SuperAdministratorFile();
    SuperAdministratorFile(std::string);

    SuperAdministratorFile read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(SuperAdministrator);
    bool save(SuperAdministrator, int);
    bool update(SuperAdministrator, int);
    bool clearLog(std::string, int);
};