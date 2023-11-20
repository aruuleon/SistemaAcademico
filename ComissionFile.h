#pragma once
#include "Comission.h"

class ComissionFile{
    private:
        char _fileName[30];
    public:
        ComissionFile();
        ComissionFile(std::string );
        Comission read(int);
        int searchRecord(std::string);
        int getNumberOfRecords();
        bool save(const Comission&);
        bool deleteRecord(std::string);
};
