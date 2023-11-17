#pragma once
#include <string>

class StudentXSubject{
    private:
        char _comissionCode[20];
        int _studentId;
        int _subjectId;
    public:
        StudentXSubject();
        StudentXSubject(std::string, int, int);
        std::string getComissionCode() const;
        int getStudentId() const;
        int getSubjectId() const;
        void setComissionCode(std::string);
        void setStudentId(int);
        void setSubjectId(int);
        void show();
};