#pragma once
#include "Student.h"
#include <string>

class StudentFile{
private:
    char _fileName[30];
public:
    StudentFile();
    StudentFile(std::string);

    StudentFile read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(Student);
    bool save(Student, int);
    bool update(Student, int);
    bool clearLog(std::string, int);
};