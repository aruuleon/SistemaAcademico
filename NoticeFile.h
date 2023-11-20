#pragma once
#include "Notice.h"
#include <string>

class NoticeFile{
private:
    char _fileName[30];
public:
    NoticeFile();
    NoticeFile(std::string);

    Notice read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool numberOfActiveRecords();
    bool save(const Notice&);
    bool save(const Notice&, int);
    bool deleteRecord(int);
    bool addOrDelete(int, int);
};