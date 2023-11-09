#pragma once
#include <string>

class SubjectXComission {
    private:
        char _comissionCode[20];
        int _subjectId;
        int _numberOfExams;
        bool _assignedTime;
    public:
        SubjectXComission();
        SubjectXComission(std::string, int, int);
        std::string getComissionCode() const;
        int getSubjectId() const;
        int getNumberOfExams() const;
        bool getAssignedTime() const;
        void setComissionCode(std::string);
        void setSubjectId(int);
        void setNumberOfExams(int);
        void setAssignedTime(bool);
};