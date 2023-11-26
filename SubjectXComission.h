#pragma once
#include <string>

class SubjectXComission {
    private:
        int _subjectId;
        int _comissionId;
        bool _state;
    public:
        SubjectXComission();
        SubjectXComission(int, int);
        int getComissionId() const;
        int getSubjectId() const;
        bool getState() const;
        void setComissionId(int);
        void setSubjectId(int);
        void setState(bool);
};