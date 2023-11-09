#pragma once
#include "Teacher.h"
#include <string>

class TeacherFile{
private:
    char _fileName[30];
public:
    TeacherFile();
    TeacherFile(std::string);

    TeacherFile read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(Teacher);
    bool save(Teacher, int);
    bool update(Teacher, int);
    bool clearLog(std::string, int);
};