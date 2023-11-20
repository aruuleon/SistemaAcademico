#pragma once
#include <string>
#include <cstring>
#include "Fecha.h"

class Notice{
    private:
        Fecha _fecha;
        char _title[30];
        char _content[500];
        int _code;
        bool _state;
    public:
        Notice();
        Notice(Fecha, std::string, std::string, int);
        Fecha getFecha() const;
        std::string getTitle() const;
        std::string getContent() const;
        int getCode() const;
        bool getState() const;
        void setFecha(Fecha);
        void setTitle(std::string);
        void setContent(std::string);
        void setCode(int);
        void setState(bool);
        void show();
};