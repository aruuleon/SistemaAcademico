#pragma once
#include <string>

class Subject {
    private:
        char _name[20];
        int _subjectId;
        int _careerId;
        int _duration;
        int _yearCareer;
        bool _state;
    public:
        Subject();
        Subject(std::string, int, int, int);
        std::string getName() const;
        int getSubjectId() const;
        int getCareerId() const;
        int getDuration() const;
        int getyearCareer() const;
        bool getState() const;
        void setName(std::string);
        void setSubjectId(int);
        void setCareerId(int);
        void setDuration(int);
        void setYearCareer(int);
        void setState(bool);
};