#pragma once
#include <string>

class Subject {
    private:
        char _name[60];
        char _duration[20];
        int _id;
        int _careerId;
        int _yearCareer;
        bool _state;
    public:
        Subject();
        Subject(std::string, std::string, int, int);
        std::string getName() const;
        std::string getDuration() const;
        int getId() const;
        int getCareerId() const;
        int getyearCareer() const;
        bool getState() const;
        void setName(std::string);
        void setId(int);
        void setCareerId(int);
        void setDuration(std::string);
        void setYearCareer(int);
        void setState(bool);
        void show();
};