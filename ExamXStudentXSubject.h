#pragma once
#include <string>

class ExamXStudentXSubject {
    private:
        int _firstResourceId;
        int _secondResourceId;
        int _thirdResourceId;
        bool _attendance;
        bool _state;
    public:
        ExamXStudentXSubject();
        ExamXStudentXSubject(int, int, int);
        int getFirstResourceId() const;
        int getSecondResourceId() const;
        int getThirdResourceId() const;
        bool getAttendance() const;
        bool getState() const;
        void setFirstResourceId(int);
        void setSecondResourceId(int);
        void setThirdResourceId(int);
        void setAttendance(bool);
        void setState(bool);
};