#pragma once
#include <string>

class Subject {
    private:
        char _name[60];
        int _duration;
        int _id;
        int _careerId;
        int _yearCareer;
        bool _state;
    public: 
        Subject();
        Subject(std::string, int, int, int);
        std::string getName() const;
        std::string getDuration() const;
        int getId() const;
        int getCareerId() const;
        int getyearCareer() const;
        bool getState() const;
        void setName(std::string);
        void setId(int);
        void setCareerId(int);
        void setDuration(int);
        void setYearCareer(int);
        void setState(bool);
        void show();
};