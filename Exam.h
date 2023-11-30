#pragma once
#include "Fecha.h"

class Exam{
    private:
        int _id;
        bool _state;
        Fecha _date;
    public:
        Exam();
        Exam(int, Fecha);
        int getId() const;
        Fecha getDate() const;
        bool getState() const;
        void setId(int);
        void setState(bool);
        void setDate(Fecha);
        void show();
};