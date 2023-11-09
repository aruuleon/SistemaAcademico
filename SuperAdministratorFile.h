#pragma once
#include "SuperAdministrator.h"
#include <string>

class SuperAdministratorFile{
private:
    char _fileName[30];
public:
    SuperAdministratorFile();
    SuperAdministratorFile(std::string);

    SuperAdministrator read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(const SuperAdministrator&);
    bool save(const SuperAdministrator&, int);
    bool update(const SuperAdministrator&, int);
    bool deleteRecord(int);
};