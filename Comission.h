#pragma once
#include<string>

class Comission {
    private:
        char _comissionCode[20];
        char _modality[20];
        int _turn;
        int _year;
        int _fourthQuarter;
        bool _state;
    public:
        Comission();
        Comission(std::string, std::string, int, int, int);
        std::string getComissionCode() const;
        std::string getModality() const;
        int getTurn() const;
        int getYear() const;
        int getFourthQuarter() const;
        bool getState() const;
        void setComissionCode(std::string);
        void setModality(std::string);
        void setTurn(int);
        void setYear(int);
        void setFourthQuarter(int);
        void setState(bool);
        void show();
};