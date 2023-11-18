#pragma once
#include <iostream>
#include <string>

template <class T>
class GenericFile {
private:
    char _fileName[30];
public:
    GenericFile();
    GenericFile(std::string);
    T read(int);
    int searchRecord(int);
    int numberOfRecords();
    bool save(const T&);
    bool save(const T&, int);
    bool update(const T&, int);
    bool deleteRecord(int);
};