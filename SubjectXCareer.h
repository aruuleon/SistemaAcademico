#pragma once
#include <string>

class SubjectXCareer {
    private:
        int _subjectId;
        int _careerId;
        bool _state;
    public:
        SubjectXCareer();
        SubjectXCareer(int, int);
        int getSubjectId() const;
        int getCareerId() const;
        bool getState() const;
        void setSubjectId(int);
        void setCareerId(int);
        void setState(bool);
};