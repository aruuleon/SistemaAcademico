#pragma once
#include<string>

class Comission {
    private:
        int _id;
        int _modality;
        int _turn;
        int _year;
        int _fourthQuarter;
        bool _state;
    public:
        Comission();
        Comission(int, int, int, int, int);
        std::string getModality() const;
        std::string getTurn() const;
        int getId() const;
        int getYear() const;
        int getFourthQuarter() const;
        bool getState() const;
        void setId(int);
        void setModality(int);
        void setTurn(int);
        void setYear(int);
        void setFourthQuarter(int);
        void setState(bool);
        void show();
};