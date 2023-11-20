#pragma once    
#include "Subject.h"

class SubjectFile{
    private:
        char _fileName[30];
    public:
        SubjectFile();
        SubjectFile(std::string name);
        Subject read(int);
        int searchRecord(int);
        int getNumberOfRecords();
        bool save(const Subject&);
        bool deleteRecord(int);
};