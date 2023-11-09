#pragma once
#include <string>

class Career {
    private:
        char _name[40];
        int _careerId;
        int _studioType;
        int _duration;
        bool _state;
    public:
        Career();
        Career(std::string, int, int, int);
        std::string getName() const;
        int getCareerId() const;
        int getStudioType() const;
        int getDuration() const;
        bool getState() const;
        void setName(std::string);
        void setCareerId(int);
        void setStudioType(int);
        void setDuration(int);
        void setState(bool);
};