#include "Functions.h"

template <typename T>
int verifyFile(T fileName){
    int generatedFile;
    int numberOfRecords = fileName.numberOfRecords();
    if(numberOfRecords > 0){
        generatedFile = fileName.read(numberOfRecords - 1).getFile() + 1;
    } else {
        generatedFile = 1;
    }
    return generatedFile;
}