#pragma once
#include "Career.h"

class CareerFile{
    private:
        char _fileName[30];
    public:
        CareerFile();
        CareerFile(std::string name);
        Career read(int);
        int searchRecord(int);
        int getNumberOfRecords();
        bool save(const Career&);
        bool update(const Career&, int);
        bool deleteRecord(int);
};
