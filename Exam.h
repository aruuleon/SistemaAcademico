#pragma once
#include "Fecha.h"

class Exam{
    private:
        Fecha _date;
        int _id;
        int _grade; //(calificación)
        bool _state;
    public:
        Exam();
        Exam(Fecha, int, int);
        Fecha getDate() const;
        int getId() const;
        int getGrade() const;
        bool getState() const;
        void setDate(Fecha);
        void setId(int);
        void setGrade(int);
        void setState(bool);
        void show();
};