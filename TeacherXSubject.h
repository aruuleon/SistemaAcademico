#pragma once
#include <string>

class TeacherXSubject {
    private:
        char _comissionCode[20];
        int _teacherId;
        int _subjectId;
    public:
        TeacherXSubject();
        TeacherXSubject(std::string, int, int);
        std::string getComissionCode() const;
        int getTeacherId() const;
        int getSubjectId() const;
        void setComissionCode(std::string);
        void setTeacherId(int);
        void setSubjectId(int);
};