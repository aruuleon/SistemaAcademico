#pragma once
#include <string>
#include "Teacher.h"

class TeacherFile{
private:
    char _fileName[30];
public:
    TeacherFile();
    TeacherFile(std::string);

    Teacher read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(const Teacher&);
    bool save(const Teacher&, int);
    bool update(const Teacher&, int);
    bool deleteRecord(int);
};