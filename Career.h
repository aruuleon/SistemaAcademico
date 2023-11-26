#pragma once
#include <string>

class Career {
    private:
        char _name[60];
        char _studyType[40];
        int _id;
        int _duration;
        bool _state;
    public:
        Career();
        Career(std::string, std::string, int, int);
        std::string getName() const;
        std::string getStudyType() const;
        int getId() const;
        int getDuration() const;
        bool getState() const;
        void setName(std::string);
        void setStudyType(std::string);
        void setId(int);
        void setDuration(int);
        void setState(bool);
        void show();
};