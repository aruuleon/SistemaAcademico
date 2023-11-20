#include "Notice.h"
#include <iostream>

Notice::Notice(){

};
Notice::Notice(Fecha fecha, std::string title, std::string content, int code){
    setFecha(fecha);
    setTitle(title);
    setContent(content);
    setCode(code);
    setState(true);
};
Fecha Notice::getFecha() const{
    return _fecha;
};
std::string Notice::getTitle() const{
    return _title;
};
std::string Notice::getContent() const{
    return _content;
};
int Notice::getCode() const{
    return _code;
};
bool Notice::getState() const{
    return _state;
};
void Notice::setFecha(Fecha fecha){
    _fecha = fecha;
};
void Notice::setTitle(std::string title){
    strcpy(_title, title.c_str());
};
void Notice::setContent(std::string content){
    strcpy(_content, content.c_str());
};
void Notice::setCode(int code){
    _code = code;
};
void Notice::setState(bool state){
    _state = state;
};
void Notice::show(){
    std::cout << "FECHA PUBLICACION: " << getFecha().toString() << std::endl;
    std::cout << "TITULO: " << getTitle() << std::endl;
    std::cout << getContent() << std::endl;
};