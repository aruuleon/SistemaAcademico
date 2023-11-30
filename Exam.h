#pragma once
#include "Fecha.h"

class Exam{
    private:
        int _id;
        int _grade;
        bool _state;
        Fecha _date;
    public:
        Exam();
        Exam(int, int, Fecha);
        int getId() const;
        int getGrade() const;
        Fecha getDate() const;
        bool getState() const;
        void setId(int);
        void setGrade(int);
        void setState(bool);
        void setDate(Fecha);
        void show();
};