#include "Career.h"

class careerFile
{
    private:
        char _fileName[30];
    public:
        careerFile();
        careerFile(std::string name);

        Career read(int);
        int search(int );
        int getNumberOfRecords();
        bool save(Career);
        bool update(Career, int);
        bool deleteRecord(int);


};
