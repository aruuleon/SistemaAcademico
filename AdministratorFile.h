#pragma once
#include "Administrator.h"
#include <string>

class AdministratorFile {
private:
    char _fileName[30];
public:
    AdministratorFile();
    AdministratorFile(std::string);
    Administrator read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(const Administrator&);
    bool save(const Administrator&, int);
    bool update(const Administrator&, int);
    bool deleteRecord(int);
    bool numberOfActiveRecords();
};