#pragma once
#include "Student.h"
#include <string>

class StudentFile{
private:
    char _fileName[30];
public:
    StudentFile();
    StudentFile(std::string);

    Student read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool numberOfActiveRecords();
    bool save(const Student&);
    bool save(const Student&, int);
    bool deleteRecord(int);
    bool addOrDelete(int, int);
};